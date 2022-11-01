#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = 501;

ll dp[MAX_N][MAX_N]; // dp[n][m][b]
ll prevdp[MAX_N][MAX_N];

void solve()
{
	ll n, m, b, mod;
	cin >> n >> m >> b >> mod;

	prevdp[0][0] = 1;

	vector<ll> a(n);

	for(auto& el: a)
		cin >> el;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			for(int k = 0; k <= b; ++k)
			{
				dp[j][k] = prevdp[j][k];
					   
				if(k >= a[i - 1] && j >= 1)
					dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i - 1]]) % mod;
			}
		}

		memcpy(prevdp, dp, sizeof(dp));
	}

	ll ans = 0;

	for(int k = 0; k <= b; ++k)
		ans = (ans + dp[m][k]) % mod;

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}