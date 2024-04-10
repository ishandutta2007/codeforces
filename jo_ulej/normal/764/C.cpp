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

const int MAX_N = (int)1e5 + 77;

vector<int> g[MAX_N];
int color[MAX_N], dp[MAX_N];
bool met[MAX_N];
int n;
vector<int> tocheck;

void dfs(int v)
{
	met[v] = true;

	for(auto u: g[v])
	{
		if(!met[u])
		{
			dfs(u);

			if(color[v] != color[u])
				++dp[v], ++dp[u];
		}
	}
}

bool check(int v, bool st)
{
	met[v] = true;
	bool ret = true;

	for(auto u: g[v])
	{
		if(!met[u])
		{
			if((color[u] != color[v] && !st) || !check(u, false))
				ret = false;
		}
	}

	return ret;
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

	for(int v = 0; v < n; ++v)
		cin >> color[v];

	dfs(0);
	
	int mxv = 0;

	for(int v = 1; v < n; ++v)
		if(dp[v] > dp[mxv])
			mxv = v;

	memset(met, 0, sizeof(met));

	if(check(mxv, true))
	{
		cout << "YES" << endl;
		cout << mxv + 1 << endl;
		return;
	}

	cout << "NO" << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}