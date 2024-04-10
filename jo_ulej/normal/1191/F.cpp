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

#define len(X) ((ll)(X).size())

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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 77;

pll raw[MAX_N];
vector<ll> level[MAX_N];
int n;

vector<ll> ordx, ordy;

ll cnt[MAX_N];

namespace fenwick
{
	ll fen[MAX_N];

	inline void add(ll i, ll x)
	{
		for(; i < MAX_N; i |= i + 1)
			fen[i] += x;
	}

	inline ll get(ll r)
	{
		ll answ = 0;

		for(; r >= 0; r = (r & (r + 1)) - 1)
			answ += fen[r];

		return answ;
	}
};

void add(ll i)
{
	++cnt[i];

	if(cnt[i] == 1)
		fenwick::add(i, 1);
}

void del(ll i)
{
	--cnt[i];

	if(!cnt[i])
		fenwick::add(i, -1);
}

ll get(ll l, ll r)
{
	if(r < l)
		return 0;

	return fenwick::get(r) - fenwick::get(l - 1);
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> raw[i].first >> raw[i].second;

	for(int i = 0; i < n; ++i)
	{
		ordx.push_back(raw[i].first);
		ordy.push_back(raw[i].second);
	}

	sort(ordx.begin(), ordx.end());
	sort(ordy.begin(), ordy.end());

	ordx.erase(unique(ordx.begin(), ordx.end()), ordx.end());
	ordy.erase(unique(ordy.begin(), ordy.end()), ordy.end());

	for(int i = 0; i < n; ++i)
	{
		ll x = lower_bound(ordx.begin(), ordx.end(), raw[i].first) - ordx.begin();
		ll y = lower_bound(ordy.begin(), ordy.end(), raw[i].second) - ordy.begin();

		level[y].push_back(x);
		add(x);
	}

	ll answ = 0;

	for(ll y = 0; y < n; ++y)
	{
		if(level[y].empty())
			continue;

		DBG(level[y]);

		ll flen = get(0, n);
		answ += (flen * (flen + 1)) / 2;

		sort(level[y].begin(), level[y].end());

		ll pref = get(0, level[y].front() - 1), suff = get(level[y].back() + 1, n);

		answ -= (pref * (pref + 1)) / 2;
		answ -= (suff * (suff + 1)) / 2;

		for(int i = 0; i + 1 < len(level[y]); ++i)
		{
			ll x1 = level[y][i], x2 = level[y][i + 1];
			ll inside = get(x1 + 1, x2 - 1);

			answ -= (inside * (inside + 1)) / 2;
		}

		for(auto& x: level[y])
			del(x);
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}