#include "minishell.h"

void	test(char *line, int indent)
{
	char	**argv;
	int		i;

	argv = tokenizer(line, 0);
	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '(')
			{
				argv[i][ft_strlen(argv[i]) - 1] = '\0';
				test(argv[i] + 1, indent + 4);
			}
		else
			printf("%-*s%i: %s\n", indent, "", i, argv[i]);
		i++;
	}
}

int main()
{
	char line[4096];
	ssize_t _read;

	while(1)
	{
		write(1, "> ", 2);
		_read = read(0, line, sizeof(line));
		if (_read <= 0)
			break ;
		line[_read - 1] = '\0';
		test(line, 0);
	}
}

