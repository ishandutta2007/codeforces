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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

struct edge
{
	int v, u;
	ll weight;
	int id;

	edge(int _v, int _u, ll _weight, int _id): v(_v), u(_u), weight(_weight), id(_id)
	{
	}

	bool operator<(const edge& other) const
	{
		return weight < other.weight;
	}
};

const int MAX_N = (int)1e5 + 77;

int n, m;
vector<edge> edges;

namespace dsu
{
	int p[MAX_N], r[MAX_N];

	inline void clear()
	{
		for(int i = 0; i < n; ++i)
			p[i] = i, r[i] = 1;
	}

	int get(int v)
	{
		if(p[v] == v)
			return v;

		return (p[v] = get(p[v]));
	}

	inline void merge(int v, int u)
	{
		v = get(v), u = get(u);

		if(v != u)
		{
			if(r[v] > r[u])
				swap(v, u);

			p[v] = u;
		}
	}
}

namespace mst
{
	inline ll get(int forced_edge)
	{
		dsu::clear();
		ll answ = 0;

		if(forced_edge != NIL)
		{
			answ += edges[forced_edge].weight;
			dsu::merge(edges[forced_edge].v, edges[forced_edge].u);
		}

		for(auto edge: edges)
		{
			if(dsu::get(edge.v) != dsu::get(edge.u))
			{
				answ += edge.weight;
				dsu::merge(edge.v, edge.u);
			}
		}

		return answ;
	}
}

inline bool check(ll M)
{
	int forced = NIL;

	for(int i = 0; i < m; ++i)
		if(edges[i].id == 0)
			forced = i;

	edges[forced].weight = M;
	sort(edges.begin(), edges.end());

	for(int i = 0; i < m; ++i)
		if(edges[i].id == 0)
			forced = i;

	ll mst_cost = mst::get(NIL);
	ll forced_cost = mst::get(forced);

	return mst_cost == forced_cost;
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int v, u;
		ll weight;
		cin >> v >> u >> weight;

		edges.emplace_back(v - 1, u - 1, weight, i);
	}

	ll L = 0, R = (ll)1e9 + 77;

	while(R - L > 1)
	{
		ll M = (L + R) / 2;

		if(check(M))
			L = M;
		else
			R = M;
	}

	cout << min(L, (ll)1e9) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}