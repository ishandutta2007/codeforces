#include <stdio.h>

long long dp[1001][500];
int mod = 1000000007;

int dfs(int n, int k)
{
    int i;

    if (dp[n][k] >= 0) return dp[n][k];

    if (k == 1) {
	return dp[n][k] = (n - 2) * (n - 1) / 2;
    }

    dp[n][k] = 0;

    for (i = k * 2 - 1; i <= n - 2; i++) {
	dp[n][k] = (dp[n][k] + (long long)dfs(i, k - 1) * (n - i - 1)) % mod;
    }

    return dp[n][k];
}

int main()
{
    int n, m, k, i, j;

    scanf("%d %d %d", &n, &m, &k);

    if (k * 2 >= n || k * 2 >= m) {
	puts("0");

	return 0;
    }

    for (i = 0; i <= 1000; i++) {
	for (j = 0; j <= k; j++) {
	    dp[i][j] = -1;
	}
    }

    printf("%d\n", (int)((long long)dfs(n, k) * dfs(m, k) % mod));

    return 0;
}