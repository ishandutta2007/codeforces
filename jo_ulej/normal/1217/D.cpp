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

const int MAX_V = 5777;
const int MAX_E = 5777;

vector<int> g[MAX_V];
pii edges[MAX_E];
int n, m;
int dag = 1;
int used[MAX_V];

void dfs(int v)
{
	used[v] = 1;

	for(auto& u: g[v])
	{
		if(used[u] == 1)
		{
			dag = 0;
		}		
		else if(used[u] == 0)
		{
			dfs(u);
		}
	}

	used[v] = 2;	
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;

		edges[i] = {v, u};
		g[v].push_back(u);
	}

	for(int v = 0; v < n; ++v)
	{
		if(!used[v])
			dfs(v);
	}

	DBG(dag);

	if(dag)
	{
		cout << "1" << endl;

		for(int i = 0; i < m; ++i)
			cout << "1 ";

		cout << endl;	
	}
	else
	{
		cout << "2" << endl;

		for(int i = 0; i < m; ++i)
			cout << (edges[i].first > edges[i].second ? "1 " : "2 ");

		cout << endl;
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}