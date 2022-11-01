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

const ll mod = 1000000007;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)5e5 + 7;

ll fact[MAX_N], invfact[MAX_N];

ll binpow(ll x, ll y)
{
	if(y == 0)
		return 1;

	ll ret = binpow(x, y >> 1);

	ret = (ret * ret) % mod;

	if(y & 1)
		ret = (ret * x) % mod;

	return ret;
}

ll c(ll k, ll n)
{
	ll ret = 1;

	ret = (ret * fact[n]) % mod;
	ret = (ret * invfact[k]) % mod;
	ret = (ret * invfact[n - k]) % mod;

	return ret;
}

void solve()
{
	ll x;
	cin >> x;

	cout << (mod + 2 * c(x - 1, 2 * x - 1) - x) % mod << endl;
}

int main()
{
	fact[0] = invfact[0] = 1;

	for(int i = 1; i < MAX_N; ++i)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		invfact[i] = binpow(fact[i], mod - 2);
	}

	fast_io();
	solve();

	return 0;
}