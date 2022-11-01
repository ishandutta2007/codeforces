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
	int weight;
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
const int MAX_M = (int)1e6 + 77;

int n, m, answ[MAX_M];
vector<edge> edges;

namespace dsu
{
	int p[MAX_N], r[MAX_N], f[MAX_N], d[MAX_N];

	inline void clear()
	{
		for(int i = 0; i < n; ++i)
			p[i] = i, r[i] = 1, f[i] = NIL;
	}

	int get(int v)
	{
		int answ = v;

		while(p[answ] != answ)
			answ = p[answ];

		return answ;
	}

	inline void merge(int v, int u, int time)
	{
		v = get(v), u = get(u);

		if(v != u)
		{
			if(r[v] > r[u])
				swap(v, u);

			p[v] = u;
			f[v] = time;

			r[u] += r[v];
		}
	}

	void make_depth(int v)
	{
		vector<int> path;

		for(;;)
		{
			path.push_back(v);

			if(v == p[v])
				break;

			v = p[v];
		}

		for(int i = 0; i < len(path); ++i)
			d[path[i]] = len(path) - i;
	}

	inline int find_last(int v, int u)
	{
		int answ = NIL;
		make_depth(v); make_depth(u);

		while(v != u)
		{
			if(d[v] > d[u])
			{
				answ = max(answ, f[v]);
				v = p[v];
			}
			else if(d[u] > d[v])
			{
				answ = max(answ, f[u]);
				u = p[u];
			}
			else
			{
				answ = max({answ, f[v], f[u]});
				v = p[v], u = p[u];
			}
		}

		return answ;
	}
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int v, u, weight;
		cin >> v >> u >> weight;

		edges.emplace_back(v - 1, u - 1, weight, i);
		answ[i] = NIL;
	}

	sort(edges.begin(), edges.end());

	dsu::clear();

	for(int i = 0; i < m; ++i)
	{
		int v = edges[i].v, u = edges[i].u;

		if(dsu::get(v) != dsu::get(u))
		{
			dsu::merge(v, u, i);	
		}
		else
		{
			int pos = dsu::find_last(v, u);

			DBG(pos);
			answ[edges[i].id] = edges[pos].weight;
		}
	}

	for(int i = 0; i < m; ++i)
		if(answ[i] != NIL)
			cout << answ[i] << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}