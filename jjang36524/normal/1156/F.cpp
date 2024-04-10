#include <iostream>
using namespace std;
#define int long long
#define MOD 998244353
int dp[5010];
int arr[5010];
int fi[5010];
int d(int n,int p=MOD-2)
{
	if (p % 2)
	{
		return n * d(n, p - 1)%MOD;
	}
	else if (!p)
		return 1;
	int a = d(n, p / 2);
	return a * a%MOD;
}
signed main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr[a]++;
	}
	int be = 0;
	int ans = 0;
	fi[2] = 1;
	for (i = 1; i<=N; i++)
	{
		if (arr[i] > 1)
		{
			int f = arr[i] * (arr[i]-1);
			int j;
			int p = 1;
			for (j = 2; j <= be + 2; j++)
			{
			
				dp[j] += f * fi[j];
				dp[j] %= MOD;
			}
		}
		be += (!(!arr[i]));
		int k;
		if (!(!arr[i]))
		{
			for (k = be+2; k >1; k--)
			{
				fi[k + 1] += arr[i] * fi[k];
				fi[k + 1] %= MOD;
			}
		}
		
	}
	int r = 1;
	for (i = 1; i <= N; i++)
	{
		r = (r * d(N + 1 - i)) % MOD;
		ans += dp[i]*r;
		ans %= MOD;
	}
	cout << ans;
}