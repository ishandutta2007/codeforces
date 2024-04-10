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

ll lcm(ll a, ll b)
{
	return (a / __gcd(a, b)) * b;
}

void solve()
{
	ll a, b;
	cin >> a >> b;

	if(a < b)
		swap(a, b);

	vector<ll> divs;

	for(ll i = 1; i * i <= (a - b); ++i)
	{
		if((a - b) % i == 0)
		{
			divs.push_back(i);

			if((a - b) / i != i)
				divs.push_back((a - b) / i);
		}
	}

	ll answ = 0;
	ll glob = lcm(a, b);

	for(auto g: divs)
	{
		ll k = (g - a % g) % g;
		
		ll loc = lcm(a + k, b + k);

		if(loc < glob || (loc == glob && k < answ))
			answ = k, glob = loc;
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}