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

const int MAX_N = (int)1e5 + 777;

vector<int> g[MAX_N];
int met[MAX_N], V, E, cnt = 0;

void add_edge(int v, int u)
{
	g[v].push_back(u);
	g[u].push_back(v);	
}

void dfs(int v)
{
	met[v] = 1;

	for(auto& u: g[v])
	{
		if(met[u])
			continue;

		dfs(u);
		++cnt;
	}
}

void solve()
{
	cin >> V >> E;

	for(int i = 0; i < E; ++i)
	{
		int v, u;
		cin >> v >> u;

		add_edge(v - 1, u - 1);
	}

	for(int v = 0; v < V; ++v)
	{
		if(met[v])
			continue;

		dfs(v);
	}

	cout << (E - cnt) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}