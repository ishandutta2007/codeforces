#include <iostream>
#include <algorithm>
#define MOD 1000000007LL
using namespace std;
#define int long long
int dp[5010][5010];
int dp2[5010][5010];
int mul[5010];
int arr[5010];
signed main()
{
	int N, K, Q;
	cin >> N >> K >> Q;
	int i;
	for (i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[0][i] = 1;
		dp2[K][i] = 1;
	}
	for (i = 1; i <= K; i++)
	{
		int j;
		for (j = 1; j <= N; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	for (i = K-1; i >=0; i--)
	{
		int j;
		for (j = 1; j <= N; j++)
		{
			dp2[i][j] = (dp2[i + 1][j - 1] + dp2[i + 1][j + 1]) % MOD;
		}
	}
	int ans = 0;
	for (i = 1; i <= N; i++)
	{
		int j;
		for (j = 0; j <= K; j++)
		{
			mul[i] += dp[j][i] * dp2[j][i];
			mul[i] %= MOD;
		}
		ans += mul[i] * arr[i];
		ans %= MOD;
	}
	for (i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		ans -= mul[a] * arr[a];
		ans += MOD * MOD;
		ans %=MOD;
		ans += mul[a] *b;
		ans += MOD * MOD;
		ans %= MOD;
		arr[a] = b;
		cout << ans << '\n';
	}
}