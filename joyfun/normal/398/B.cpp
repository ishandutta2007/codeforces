#include <stdio.h>
#include <string.h>

const int N = 2005;
int n, m, r, c, rv[N], cv[N], i, j;
double dp[N][N];

int main() {
	scanf("%d%d", &n, &m);
	r = c = n;
	int a, b;
	while (m--) {
		scanf("%d%d", &a, &b);
		if (rv[a] == 0) r--;
		if (cv[b] == 0) c--;
		rv[a] = 1; cv[b] = 1;
	}
	for (i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + (double)n/i;
		dp[0][i] = dp[0][i - 1] + (double)n/i;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = n * n;
			dp[i][j] += dp[i - 1][j - 1] * i * j;
			dp[i][j] += dp[i - 1][j] * i * (n - j);
			dp[i][j] += dp[i][j - 1] * (n - i) * j;
			dp[i][j] /= (n * n - (n - i) * (n - j));
		}
	}
	printf("%.10lf\n", dp[r][c]);
	return 0;
}