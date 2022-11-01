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

const int MAX_N = (int)3e5 + 777;
vector<int> g[MAX_N];
int leaves[MAX_N];
int type[MAX_N];
int dp[MAX_N];
int n;

void prepare(int v)
{
	vector<int> ng;

	for(auto u: g[v])
	{
		prepare(u);

		if(type[u] != type[v])
		{
			ng.push_back(u);
		}
		else
		{
			for(auto w: g[u])
				ng.push_back(w);
		}
	}

	g[v] = ng;
}

void dfs(int v)
{
	if(g[v].empty())
	{
		leaves[v] = dp[v] = 1;
		return;
	}
	else
	{
		for(auto u: g[v])
		{
			dfs(u);
			leaves[v] += leaves[u];
		}
	}

	DBG(leaves[v]);

	if(type[v])
	{
		for(auto u: g[v])
		{
			dp[v] = max(dp[v], dp[u] - leaves[u] + leaves[v]);
			DBG(dp[u] - leaves[u] + leaves[v]);
			DBG(dp[u]);
		}
	}
	else
	{
		dp[v] = leaves[v];

		for(auto u: g[v])
			dp[v] -= leaves[u] - dp[u] + 1;

		++dp[v];
	}
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> type[i];

	for(int v = 1; v < n; ++v)
	{
		int par;
		cin >> par;
		--par;

		g[par].push_back(v);
	}

	//prepare(0);
	dfs(0);

	cout << dp[0] << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}