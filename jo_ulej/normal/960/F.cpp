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
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

struct Tree
{
	vector<int> tree;
	int sz;

	Tree(int _sz = 0): sz(_sz)
	{
		tree.resize(2 * sz, 0);
	}

	void change(int pos, int val)
	{
		pos += sz;

		if(val > tree[pos])
		{
			tree[pos] = val;

			for(; pos > 1; pos /= 2)
				tree[pos / 2] = max(tree[pos], tree[pos ^ 1]);
		}
	}

	int get(int l, int r)
	{
		l += sz;
		r += sz + 1;
		int acc = 0;

		while(l < r)
		{
			if(l & 1)
				acc = max(acc, tree[l++]);

			if(r & 1)
				acc = max(acc, tree[--r]);

			l /= 2;
			r /= 2;
		}

		return acc;
	}
};

struct Edge
{
	int v, u, weight, id;

	bool operator<(const Edge& other) const
	{
		if(weight != other.weight)
			return weight < other.weight;

		return id < other.id;
	}
};

const int MAX_N = 100000 + 7777;
vector<Edge> g[MAX_N];
Tree dp[MAX_N];
int n, m;
map<Edge, int> pos;
vector<Edge> ord;

void add_edge(int v, int u, int weight)
{
	static int last = 1337;

	Edge ed = {v, u, weight, last++};

	g[v].push_back(ed);
	ord.push_back(ed);
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int v, u, weight;
		cin >> v >> u >> weight;
		--v, --u;

		add_edge(v, u, weight);
	}

	for(int v = 0; v < n; ++v)
	{
		int cnt = len(g[v]);

		sort(g[v].begin(), g[v].end());
		dp[v] = Tree(cnt);

		for(int i = 0; i < cnt; ++i)
		{
			auto ed = g[v][i];
			pos[ed] = i;
		}
	}

	reverse(ord.begin(), ord.end());

	for(auto& ed: ord)
	{
		int v = ed.v;
		int u = ed.u;
		int i = pos[ed];
		dp[v].change(i, 1);

		int fst = upper_bound(g[u].begin(), g[u].end(), (Edge){INT_INF, INT_INF, g[v][i].weight, INT_INF}) - g[u].begin();
		int cnt = len(g[u]);

		if(fst < cnt)
		{
			int value = dp[u].get(fst, cnt - 1) + 1;
			dp[v].change(i, value);

			DBG(value);
			DBG(g[v][i].weight); DBG(g[u][fst].weight);
		}

		DBG(v + 1); DBG(u + 1); DBG(fst); DBG(cnt);
	}

	int answ = 0;

	for(int v = 0; v < n; ++v)
	{
		int cnt = len(g[v]);

		if(cnt > 0)
			answ = max(answ, dp[v].get(0, cnt - 1));
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}