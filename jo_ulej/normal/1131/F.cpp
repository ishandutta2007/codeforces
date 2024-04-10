#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }

const int MAX_N = 5e5;

vector<int> g[MAX_N];
bool met[MAX_N];
int parent[MAX_N];
int n;

int get_parent(int v)
{
	if(v == parent[v])
		return v;

	return (parent[v] = get_parent(parent[v]));
}

void dfs(int v)
{
	for(auto u: g[v])
		dfs(u);

	if(v < n)
		cout << v + 1 << " ";
}

void solve()
{
	cin >> n;

	for(int i = 0; i < MAX_N; ++i)
		parent[i] = i;

	int lst = n;

	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--v, --u, ++lst;

		v = get_parent(v), u = get_parent(u);

		g[lst].push_back(v);
		g[lst].push_back(u);

		parent[u] = parent[v] = lst;
	}

	dfs(lst);
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}