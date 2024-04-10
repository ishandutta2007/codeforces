#include <cstdio>

#define MOD  (1000000007)

int dp[5002][5002];
int cum[5002];
int n;
int a;
int b;
int k;

int main()
{
	scanf("%d%d%d%d", &n, &a, &b, &k);
	dp[0][a] = 1;
	for (int i = 1;i <= k;i++)
	{
		for (int j = 1;j <= n;j++)
			cum[j] = (cum[j-1] + dp[i-1][j]) % MOD;
		for (int j = 1;j <= n;j++)
		{
			if (j == b)
				continue;
			int lo = 1, hi = n;
			if (j < b)
			{
				lo = 1;
				hi = (j + b - 1) >> 1;
			} else if (j > b)
			{
				lo = ((j + b) >> 1) + 1;
				hi = n;
			}
			dp[i][j] = (((cum[hi] - cum[lo-1] + MOD) % MOD) - dp[i-1][j] + MOD) % MOD;
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		ans = (ans + dp[k][i]) % MOD;
	printf("%d\n", ans);
	return 0;
}