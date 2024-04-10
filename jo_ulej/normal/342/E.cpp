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

const int MAX_N = (int)1e5 + 77;
const int MAX_E_SZ = 2 * MAX_N;
const int MAX_LOG_E_SZ = 19;

vector<int> g[MAX_N];

int euler[MAX_E_SZ], esz = 0;
int depth[MAX_N], tin[MAX_N];

int sparse[MAX_LOG_E_SZ][MAX_E_SZ], lg[MAX_E_SZ];

int met[MAX_N], mark = 13;

int n, q;

void prepare(int v)
{
	met[v] = mark;

	tin[v] = esz;
	euler[esz++] = v;

	for(auto u: g[v])
	{
		if(met[u] != mark)
		{
			depth[u] = depth[v] + 1;
			prepare(u);

			euler[esz++] = v;
		}
	}
}

inline int choose_lca(int v, int u)
{
	return (depth[v] < depth[u] ? v : u);
}

inline void build_spase_table()
{
	for(int i = 0; i < esz; ++i)
		sparse[0][i] = euler[i];

	for(int log = 1; log < MAX_LOG_E_SZ; ++log)
		for(int i = 0; i + (1 << log) - 1 < esz; ++i)
			sparse[log][i] = choose_lca(sparse[log - 1][i], sparse[log - 1][i + (1 << (log - 1))]);
}

inline int dist(int v, int u)
{
	int l = tin[v], r = tin[u];

	if(l > r)
		swap(l, r);

	int log = lg[r - l + 1];

	int lca = choose_lca(sparse[log][l], sparse[log][r - (1 << log) + 1]);

	return depth[v] + depth[u] - 2 * depth[lca];
}

bool wasc[MAX_N];

int subtree[MAX_N], mxsubtree[MAX_N];
int p[MAX_N], best[MAX_N];

inline int choose_cen(int v, int u)
{
	if(v == NIL)
		return u;

	if(u == NIL)
		return v;

	return (mxsubtree[v] < mxsubtree[u] ? v : u);
}

void calc_subtree(int v)
{
	met[v] = mark;
	subtree[v] = 1;

	for(auto u: g[v])
	{
		if(met[u] != mark && !wasc[u])
		{
			calc_subtree(u);
			subtree[v] += subtree[u];
		}
	}
}

int find_centroid(int v, int full_tree_size)
{
	met[v] = mark;
	mxsubtree[v] = 0;
	int answ = NIL;

	for(auto u: g[v])
	{
		if(met[u] != mark && !wasc[u])
		{
			answ = choose_cen(answ, find_centroid(u, full_tree_size));
			mxsubtree[v] = max(mxsubtree[v], subtree[u]);
		}
	}

	mxsubtree[v] = max(mxsubtree[v], full_tree_size - subtree[v]);
	answ = choose_cen(answ, v);

	return answ;
}

void build_decomposition(int v, char level = 'A', int par = NIL)
{
	++mark;
	calc_subtree(v);

	++mark;
	v = find_centroid(v, subtree[v]);

	wasc[v] = true;
	p[v] = par;

#ifdef __LOCAL
	cout << "vertex " << v + 1 << " has level " << level << endl;
#endif

	for(auto u: g[v])
	{
		if(!wasc[u])
		{
			build_decomposition(u, level + 1, v);
		}
	}
}

inline void activate(int v)
{
	int par = v;

	while(par != NIL)
	{
		if(dist(par, v) < dist(par, best[par]))
			best[par] = v;

		par = p[par];
	}
}

inline int get(int v)
{
	int answ = 0, par = v;

	while(par != NIL)
	{
		if(dist(best[par], v) < dist(answ, v))
			answ = best[par];

		par = p[par];
	}

	return dist(v, answ);
}

void solve()
{
	cin >> n >> q;

	for(int i = 0; i < n - 1; ++i)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	++mark;
	prepare(0);

	build_spase_table();
	memset(p, NIL, sizeof(p));

	build_decomposition(0);

	for(; q; --q)
	{
		int t, v;
		cin >> t >> v;
		--v;

		if(t == 1)
			activate(v);
		else
			cout << get(v) << "\n";		
	}
}

int main()
{
	lg[1] = 0;

	for(int i = 2; i < MAX_E_SZ; ++i)
		lg[i] = 1 + lg[i >> 1];

	fast_io();
	solve();

	return 0;
}