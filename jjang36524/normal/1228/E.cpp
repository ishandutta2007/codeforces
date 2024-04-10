#include <iostream>
using namespace std;
#define MOD 1000000007LL
#define int long long
int N, M;
int dp[255][255];
int p[255][2];
int c[255][255];
signed main()
{
	cin >> N >> M;
	dp[0][N] = 1;
	int i;
	p[0][0] = 1;
	p[0][1] = 1;
	for (i = 0; i <= N; i++)
	{
		int j;
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j] + c[i-1][j - 1]) % MOD;
		}
	}
	for (i = 1; i <= N; i++)
	{
		p[i][0] = p[i - 1][0] * (M - 1) % MOD;
		p[i][1] = p[i - 1][1] * M % MOD;
	}
	for (i = 1; i <= N; i++)
	{
		int j;
		for (j = N-1; j >= 0; j--)
		{
			int k;
			for (k = N; k >= j; k--)
			{
				int r = dp[i - 1][k];
				r = r * p[j][0]%MOD;
				r = r * p[N - k][1] % MOD;
				r = r * c[k][j] % MOD;
				if (j == k)
					r = (r + MOD*MOD - dp[i-1][k]*p[N][0])%MOD;
				dp[i][j] = (dp[i][j] + r) % MOD;
			}
		}
	}
	cout << dp[N][0];
}