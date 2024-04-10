#include <iostream>
#include <string.h>
#include <algorithm>
#define MOD 998244353
using namespace std;
#define int long long
int N, M, T;
double a, b, c, d;
int dp[500510];
int s(int n, int p = 998244351)
{
	if (p == 0)
		return 1;
	else if (p % 2)
	{
		return s(n, p - 1) * n % MOD;
	}
	int ans = s(n, p / 2);
	return ans * ans % MOD;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	M--;
	int i;
	int c = 1;
	dp[M] = 1;
	for (i = M+1; i <= N; i++)
	{
		c = c * i % MOD;
		c = c * s(i - M)%MOD;
		dp[i] = c;
	}
	int ans = 0;
	for (i = 1; i <= N; i++)
		ans += dp[(N / i)-1];
	cout << ans % MOD;
}