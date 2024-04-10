#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
	return a;
    } else {
	return b;
    }
}

int main()
{
    int n, m, k, i, j, l;
    char s[300][301];

    scanf("%d %d %d", &n, &m, &k);

    for (i = 0; i < n; i++) scanf("%s", s[i]);

    for (i = 1; i < 300; i++) {
	for (j = 0; j < n; j++) {
	    for (l = 0; l < m; l++) {
		if (s[j][l] != '*') continue;

		if (j - i < 0 || j + i >= n || l - i < 0 || l + i >= m) {
		    continue;
		}

		if (s[j - i][l] != '*') continue;
		if (s[j + i][l] != '*') continue;
		if (s[j][l - i] != '*') continue;
		if (s[j][l + i] != '*') continue;

		k--;

		if (k == 0) {
		    printf("%d %d\n", j + 1, l + 1);
		    printf("%d %d\n", j - i + 1, l + 1);
		    printf("%d %d\n", j + i + 1, l + 1);
		    printf("%d %d\n", j + 1, l - i + 1);
		    printf("%d %d\n", j + 1, l + i + 1);

		    return 0;
		}
	    }
	}
    }

    puts("-1");

    return 0;
}