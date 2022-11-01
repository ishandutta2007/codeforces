#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int dp[5002][5002];
int cu[5002];

int main()
{
	int n, k, a, b; scanf("%d%d%d%d", &n, &a, &b, &k);
	for (int i = 1;i <= n;i++) if (i != b) dp[0][i] = 1;
	for (int j = 1;j <= k;j++)
	{
		for (int i = 1;i <= n;i++) cu[i] = (cu[i-1]+dp[j-1][i])%MOD;
		for (int i = 1;i <= n;i++) if (i != b)
		{
			int lo = -1, hi = -1;
			if (i < b)
			{
				hi = b-1;
				int di = hi-i;
				lo = i-di;
				if (lo < 1) lo = 1;
			} else
			{
				lo = b+1;
				int di = i-lo;
				hi = i+di;
				if (hi > n) hi = n;
			}
			dp[j][i] = ((cu[hi]-cu[lo-1])%MOD+MOD)%MOD;
			dp[j][i] = (dp[j][i]-dp[j-1][i]+MOD)%MOD;
		}
	}
	printf("%d\n", dp[k][a]);
	return 0;
}