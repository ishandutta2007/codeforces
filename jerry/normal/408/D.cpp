#include <cstdio>

#define MOD  1000000007

int dp[1001];
int p[1001];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", p+i);
	for (int i = 0;i < n;i++)
	{
		dp[i+1] = (dp[i] - dp[p[i]-1] + 2 + dp[i]) % MOD;
		if (dp[i+1] < 0)
			dp[i+1] += MOD;
	}
	printf("%d\n", dp[n]);
	return 0;
}