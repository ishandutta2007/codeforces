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

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

ll cnt(ll i, ll j)
{
	vector<ll> dp(i + 1, 0);

	dp[0] = 1;

	for(ll k = 1; k <= i; ++k)
	{
		for(ll dlt = 1; dlt <= j && k - dlt >= 0; ++dlt)
			dp[k] = (dp[k] + dp[k - dlt]) % mod;
	}

	return dp[i];
}

void solve()
{
	ll n, k, d;
	cin >> n >> k >> d;

	if(d == 1)
		cout << cnt(n, k) << endl;
	else
		cout << (mod + cnt(n, k) - cnt(n, d - 1)) % mod << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}