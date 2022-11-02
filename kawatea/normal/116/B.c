#include <stdio.h>

int main()
{
    int n, m, sum = 0, i, j;
    char s[10][11];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) scanf("%s", s[i]);

    for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++) {
	    if (s[i][j] == 'P') {
		if (i > 0 && s[i - 1][j] == 'W') {
		    s[i - 1][j] = '.';
		    sum++;
		} else if (i < n - 1 && s[i + 1][j] == 'W') {
		    s[i + 1][j] = '.';
		    sum++;
		} else if (j > 0 && s[i][j - 1] == 'W') {
		    s[i][j - 1] = '.';
		    sum++;
		} else if (j < m - 1 && s[i][j + 1] == 'W') {
		    s[i][j + 1] = '.';
		    sum++;
		}
	    }
	}
    }

    printf("%d\n", sum);

    return 0;
}