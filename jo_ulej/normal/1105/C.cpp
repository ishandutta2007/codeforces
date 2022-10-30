#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const int MAX_N = 200100;

ll dp[MAX_N][3], l, r;

ll cnt2(ll x, ll m)
{
	ll ret = x / 3;

	if(m != 0 && m <= x % 3)
		++ret;

	return ret;
}

ll cnt(ll m)
{
	return cnt2(r, m) - cnt2(l - 1, m);
}

void solve()
{
	int n;

	cin >> n >> l >> r;

	dp[0][0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		for(int m = 0; m < 3; ++m)
		{
			for(int m1 = 0; m1 < 3; ++m1)
			{
				dp[i][(m + m1) % 3] = (dp[i][(m + m1) % 3] + dp[i - 1][m] * cnt(m1)) % mod;
			}
		}
	}

	cout << dp[n][0] << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}