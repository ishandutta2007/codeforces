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

const ll mod = 998244353;

// n, b, k
ll dp[1001][4][2001];

int cnt_delta(int b1, int b2)
{
	if(b2 == 0 || b2 == 3)
	{
		if(b1 + b2 == 3)
			return 1;

		return 0;
	}
	else
	{
		if(b1 + b2 == 3)
			return 2;

		if(b1 == 0 || b1 == 3)
			return 1;

		return 0;
	}
}

void solve()
{
	dp[1][0][1] = 1;
	dp[1][1][2] = 1;
	dp[1][2][2] = 1;
	dp[1][3][1] = 1;

	int N, K;
	cin >> N >> K;

	for(int n = 2; n <= N; ++n)
	{
		for(int k = 1; k <= 2000; ++k)
		{
			for(int b2 = 0; b2 <= 3; ++b2)
			{
				for(int b1 = 0; b1 <= 3; ++b1)
				{
					int dk = cnt_delta(b1, b2);

					if(k - dk > 0)
						dp[n][b2][k] = (dp[n][b2][k] + dp[n - 1][b1][k - dk]) % mod;
				}
			}
		}
	}

	ll ans = 0;

	for(int b = 0; b <= 3; ++b)
		ans = (ans + dp[N][b][K]) % mod;

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}