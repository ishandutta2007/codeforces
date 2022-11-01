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

const int MAX_N = (int)3e5 + 77;

vector<int> g[MAX_N], children[MAX_N];
bool met[MAX_N];
int n;
ll subtree[MAX_N], dp_par[MAX_N], p[MAX_N];
vector<ll> dp_chld[MAX_N];

void dfs_init(int v)
{
	met[v] = true;
	subtree[v] = 1LL;

	for(auto u: g[v])
	{
		if(!met[u])
		{
			dfs_init(u);
			subtree[v] += subtree[u];

			children[v].push_back(u);
			p[u] = v;
		}
	}
}

void dfs_calc(int v)
{
	dp_par[v] = subtree[v];

	for(auto u: children[v])
	{
		dfs_calc(u);
		dp_par[v] += dp_par[u];
	}

	dp_chld[v].resize(len(children[v]));
}

void dfs_calc2(int v)
{
	int c = len(children[v]);

	for(int i = 0; i < c; ++i)
	{
		int u = children[v][i], parent = p[v];

		dp_chld[v][i] = dp_par[v] - dp_par[u] - subtree[v] + n - subtree[u];

		if(parent != NIL)
		{
			int index = lower_bound(children[parent].begin(), children[parent].end(), v) - children[parent].begin();
			dp_chld[v][i] += dp_chld[parent][index];
		}
	}

	for(auto u: children[v])
		dfs_calc2(u);
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n - 1; ++i)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	const int root = 0;

	p[root] = NIL;
	dfs_init(root);

	for(int v = 0; v < n; ++v)
		sort(children[v].begin(), children[v].end());

	dfs_calc(root);
	dfs_calc2(root);

#ifdef __LOCAL

	for(int v = 0; v < n; ++v)
		cout << v + 1 << " --> " << subtree[v] << " (subtree)" << endl;

	for(int v = 0; v < n; ++v)
		cout << v + 1 << " --> " << dp_par[v] << " (dp_par)" << endl;

	for(int v = 0; v < n; ++v)
		cout << v + 1 << " --> " << dp_chld[v] << " (dp_chld)" << endl;

#endif

	ll answ = NIL;

	for(int v = 0; v < n; ++v)
	{
		answ = max(answ, dp_par[v]);
		int c = 0;

		for(auto value: dp_chld[v])
		{
			int u = children[v][c++];
			answ = max(answ, n + value + dp_par[u] - subtree[u]);
		}
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}