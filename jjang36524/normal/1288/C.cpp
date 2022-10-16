#include <iostream>
using namespace std;
#define int long long
#define MOD 1000000007
int N, M, T;
int c[3001][3001];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i,j;
	for (i = 0; i <= 3000; i++)
	{
		c[i][0] = c[i][i] = 1;
	}
	for (i = 1; i <= 3000; i++)
	{
		for (j = 1; j < i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%MOD;
		}
	}
	int ans = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = i; j <= N; j++)
		{
			ans += c[i+M-2][M - 1] * c[N + M - j-1][M - 1] % MOD;
		}
	}
	cout << ans % MOD;
}