#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
	#define endl '\n'
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

void solve()
{
	ll n, x;
	cin >> n >> x;

	ll answ = LL_INF;
	ll maxd = -LL_INF;

	vector<pll> dh;

	for(int i = 0; i < n; ++i)
	{
		ll d, h;
		cin >> d >> h;

		dh.emplace_back(d, h);
		maxd = max(maxd, d);
	}

	for(int i = 0; i < n; ++i)
	{
		ll d = dh[i].first, h = dh[i].second;

		if(x <= d)
		{
			answ = min(answ, 1LL);
			continue;
		}

		if(d <= h)
			continue;

		ll low = 0, high = (ll)1e9 + 777;

		while(high - low > 1)
		{
			ll mid = (low + high) / 2;

			if(x - mid * (d - h) <= maxd)
				high = mid;
			else
				low = mid;
		}

		answ = min(answ, high + 1);
	}

	cout << (answ >= LL_INF ? NIL : answ) << endl;
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}