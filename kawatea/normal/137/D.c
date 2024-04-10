#include <stdio.h>
#include <string.h>

char s[501];
int a[500][500];
int dp[500][500];
int n;

int dfs(int x, int y)
{
    int min = 1e9, i;

    if (dp[x][y] >= 0) return dp[x][y];

    if (n - x < y) return -1;

    if (y == 1) return dp[x][y] = a[x][n - 1];

    for (i = x + 1; i < n; i++) {
	int p = dfs(i, y - 1);

	if (p >= 0 && a[x][i - 1] + p < min) {
	    min = a[x][i - 1] + p;
	}
    }

    return dp[x][y] = min;
}

void dfs2(int x, int y)
{
    int min = 1e9, num, i;

    if (y == 1) {
	if (x > 0) putchar('+');

	for (i = 0; i <= (n - x) / 2; i++) s[x + i] = s[n - i - 1];

	for (i = x; i < n; i++) putchar(s[i]);

	puts("");

	return;
    }

    for (i = x + 1; i < n; i++) {
	int p = dfs(i, y - 1);

	if (p >= 0 && a[x][i - 1] + p < min) {
	    min = a[x][i - 1] + p;
	    num = i;
	}
    }

    if (x > 0) putchar('+');

    for (i = 0; i <= (num - x) / 2; i++) s[x + i] = s[num - i - 1];

    for (i = x; i < num; i++) putchar(s[i]);

    dfs2(num, y - 1);
}

int main()
{
    int k, min = 1e9, num, i, j, l;

    scanf("%s", s);
    scanf("%d", &k);

    n = strlen(s);

    for (i = 0; i < n; i++) {
	for (j = i; j < n; j++) {
	    for (l = 0; l <= (j - i) / 2; l++) {
		if (s[i + l] != s[j - l]) a[i][j]++;
	    }
	}
    }

    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    dp[i][j] = -1;
	}
    }

    for (i = 1; i <= k; i++) {
	int x = dfs(0, i);

	if (x < min) {
	    min = x;
	    num = i;
	}
    }

    printf("%d\n", min);

    dfs2(0, num);

    return 0;
}