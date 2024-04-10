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

ll md;

ll dist(ll x, ll y)
{
	ll d = abs(x - y);

	return min(d, md - d) % md;
}

void solve()
{
	ll n, k, a, b;
	cin >> n >> k >> a >> b;

	ll mn = LL_INF, mx = -LL_INF;
	md = n * k;

	for(ll p = 0; p < n; ++p)
	{
		for(ll start: {a, (md - a) % md})
		{
			for(ll fin: {p * k + b, (p * k + md - b) % md})
			{
				DBG(start); DBG(fin);
				ll L = dist(fin, start);

				if(!L)
					L = md;

				ll val = (n * k) / __gcd(n * k, L);

				mn = min(mn, val);
				mx = max(mx, val);
			}
		}
	}

	cout << mn << " " << mx << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}