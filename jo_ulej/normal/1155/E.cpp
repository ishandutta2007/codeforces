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

const ll mod = 1e6 + 3;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int k = 10;

const ll TEST0 = 1;
const ll TEST1 = 1;
const ll TEST2 = 0;
const ll TEST3 = 0;

ll ask(ll x)
{
	x %= mod;
#ifdef __LOCAL
	ll ret = TEST3;

	ret = (x * ret + TEST2) % mod;
	ret = (x * ret + TEST1) % mod;
	ret = (x * ret + TEST0) % mod;

	return ret;
#else
	ll ret;

	cout << "? " << x << endl;
	cin >> ret;

	if(ret == -1)
		exit(0);

	return ret;
#endif
}

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

ll inv(ll x)
{
	return binpow(x, mod - 2);
}

ll value[k + 1], magic[k + 1];
ll invmem[mod + 1];

ll get(ll x)
{
	ll ret = 0;

	for(ll i = 0; i <= k; ++i)
	{
		ll dlt = 1;

		for(ll j = 0; j <= k; ++j)
		{
			if(j == i)
				continue;

			ll temp1 = (mod + x - j) % mod;
			dlt = (dlt * temp1) % mod;

			//ll temp2 = (mod + i - j) % mod;
			//dlt = (dlt * invmem[temp2]) % mod;
		}

		//dlt = (dlt * value[i]) % mod;
		dlt = (dlt * magic[i]) % mod;
		ret = (ret + dlt) % mod;
	}

	return ret;
}

void solve()
{
	for(ll x = 0; x <= k; ++x)
		value[x] = ask(x);

	for(ll i = 0; i <= k; ++i)
	{
		magic[i] = 1;

		for(ll j = 0; j <= k; ++j)
		{
			if(j == i)
				continue;

			ll temp2 = (mod + i - j) % mod;
			magic[i] = (magic[i] * inv(temp2)) % mod;
		}

		magic[i] = (magic[i] * value[i]) % mod;
	}

	for(ll x = 0; x < mod; ++x)
	{
		ll y = get(x);

		if(y == 0)
		{
			cout << "! " << x << endl;
			return;
		}
	}

	DBG("aaaaaa");

	cout << "! " << -1 << endl;
}

int main()
{
	fast_io();
	solve();
}