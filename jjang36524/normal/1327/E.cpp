#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
#define MOD 998244353LL
int dp[200100];
int po[200100];
int psum[200100];
int N;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	po[0] = 1;
	for (i = 1; i <= N; i++)
	{
		po[i] = (po[i - 1] * 10LL) % MOD;
		dp[i] = (po[i] * i - po[i - 1] * (i - 1) + MOD * MOD) % MOD;
	}
	for (i = N; i > 0; i--)
	{
		cout << (dp[i] - dp[i - 1] + MOD) % MOD << ' ';
	}
}