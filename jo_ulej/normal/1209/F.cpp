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

#define queue __Abacaba

#ifdef __LOCAL
	const int MAX_N = 1000;
#else
	const int MAX_N = (int)1e6 + 777;
#endif

const int MOD = (int)1e9 + 7;

int add(int x, int y)
{
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int mult(int x, int y)
{
	return (x * 1LL * y) % MOD;
}

vector<pii> g[MAX_N];
int n, m, last;
int dist[MAX_N], queue[MAX_N], head = 0;
int answ[MAX_N], met[MAX_N];

vector<int> layers[MAX_N];
int cls[MAX_N];
pii pr[MAX_N];

void add_edge(int v, int u, int digit)
{
	g[v].emplace_back(u, digit);
}

void build_long_edge(int v, int u, int id)
{
	vector<int> digits;

	for(; id > 0; id /= 10)
		digits.push_back(id % 10);

	reverse(digits.begin(), digits.end());

	vector<int> path = {v};

	for(int i = 0; i < len(digits) - 1; ++i)
		path.push_back(last++);

	path.push_back(u);

	for(int i = 0; i + 1 < len(path); ++i)
		add_edge(path[i], path[i + 1], digits[i]);
}

void run_bfs(int src)
{
	for(int v = 0; v < last; ++v)
		dist[v] = INT_INF;

	dist[src] = 0;
	queue[head++] = src;
	layers[0].push_back(src);

	for(int j = 0; j < head; ++j)
	{
		int v = queue[j];

		for(auto& ed: g[v])
		{
			int u = ed.first;

			if(dist[u] > dist[v] + 1)
			{
				dist[u] = dist[v] + 1;
				layers[dist[u]].push_back(u);
				queue[head++] = u;
			}
		}
	}
}

void build_cls()
{
	for(int lay = 1; !layers[lay].empty(); ++lay)
	{
		for(auto& v: layers[lay])
			pr[v] = make_pair(INT_INF, INT_INF);

		for(auto& parent: layers[lay - 1])
		{
			for(auto& ed: g[parent])
			{
				int v = ed.first;

				if(dist[v] == lay)
					pr[v] = min(pr[v], make_pair(cls[parent], ed.second));
			}
		}

		vector<pii> ord;

		for(auto& v: layers[lay])
			ord.push_back(pr[v]);

		sort(ord.begin(), ord.end());

		for(auto& v: layers[lay])
			cls[v] = lower_bound(ord.begin(), ord.end(), pr[v]) - ord.begin();
	}
}

void build_answ(int v, int cur)
{
	met[v] = 1;
	answ[v] = cur;

	for(auto& ed: g[v])
	{
		int u = ed.first;

		if(dist[u] != dist[v] + 1 || met[u])
			continue;

		if(pr[u] == make_pair(cls[v], ed.second))
			build_answ(u, add(mult(cur, 10), ed.second));
	}
}

void solve()
{
	cin >> n >> m;
	last = n;

	for(int i = 0; i < m; ++i)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;

		build_long_edge(v, u, i + 1);
		build_long_edge(u, v, i + 1);
	}

	run_bfs(0);
	build_cls();
	build_answ(0, 0);

	for(int v = 1; v < n; ++v)
		cout << answ[v] << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}