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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 777;

int parent[MAX_N], cnt[MAX_N];
ll cur_value = 0;

int n, m;

void init_dsu()
{
	for(int v = 0; v < n; ++v)
	{
		parent[v] = v;
		cnt[v] = 1;
	}
}

int get_parent(int v)
{
	for(; parent[v] != v; v = parent[v]);

	return v;	
}

inline void connect(int v, int u)
{
	v = get_parent(v);
	u = get_parent(u);

	DBG(v); DBG(u);

	if(v != u)
	{
		if(cnt[v] > cnt[u]) // make sure cnt[v] <= cnt[u]
			swap(v, u);

		cur_value -= (cnt[v] * 1LL * (cnt[v] - 1)) / 2;
		cur_value -= (cnt[u] * 1LL * (cnt[u] - 1)) / 2;

		parent[v] = u;
		cnt[u] += cnt[v];

		cur_value += (cnt[u] * 1LL * (cnt[u] - 1)) / 2;
	}	
}

struct Edge
{
	int v, u, weight;

	bool operator<(const Edge& other) const
	{
		return weight < other.weight;
	}
};

struct Query
{
	int index, q;

	bool operator<(const Query& other) const
	{
		return q < other.q;
	}
};

Edge edges[MAX_N];
Query queries[MAX_N];

ll answ[MAX_N];

void solve()
{
	cin >> n >> m;
	init_dsu();

	for(int i = 0; i < n - 1; ++i)
	{
		cin >> edges[i].v >> edges[i].u >> edges[i].weight;
		--edges[i].v, --edges[i].u;
	}

	for(int i = 0; i < m; ++i)
	{
		cin >> queries[i].q;
		queries[i].index = i;
	}

	sort(edges, edges + n - 1);
	sort(queries, queries + m);

	int last = 0;

	for(int i = 0; i < m; ++i)
	{
		DBG(edges[last].weight);
		DBG(edges[last].v);
		DBG(edges[last].u);
		DBG(queries[i].q);

		while(last < n - 1 && edges[last].weight <= queries[i].q)
		{
			connect(edges[last].v, edges[last].u);
			++last;
		}

		answ[queries[i].index] = cur_value;
	}

	for(int i = 0; i < m; ++i)
		cout << answ[i] << " ";

	cout << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}