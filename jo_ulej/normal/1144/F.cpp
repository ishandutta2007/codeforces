#include <bits/stdc++.h>
 
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
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 77;
vector<int> g[MAX_N];
int color[MAX_N];
bool met[MAX_N];
int n, m;

void dfs(int v, int c)
{
	met[v] = true;
	color[v] = c;

	for(auto u: g[v])
		if(!met[u])
			dfs(u, 3 - c);
}

void solve()
{
	cin >> n >> m;
	vector<pii> edges;

	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;

		g[u].push_back(v);
		g[v].push_back(u);

		edges.emplace_back(u, v);
	}

	dfs(0, 1);

	string out;

	for(auto& edge: edges)
	{
		int u = edge.first, v = edge.second;

		if(color[u] == color[v])
		{
			cout << "NO" << endl;
			return;
		}

		out += (color[u] < color[v]) + '0';
	}

	cout << "YES" << endl << out << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}