#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,avx")

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

const int MAX_N  = (int)5e5;
const int N_COLS = 26;

vector<int> g[MAX_N];
int n, m;
int tin[MAX_N], tout[MAX_N];
char col[MAX_N];
int curcolor = 0;

vector<pair<int, char>> verts[MAX_N]; // pairs (tin, color) of vertices by depth
vector<int> prefsum[MAX_N];

inline int getsum(int h, int c, int l, int r)
{
	int ret = (l == 0 ? prefsum[h][r] : prefsum[h][r] ^ prefsum[h][l - 1]);

	return (ret >> c) & 1;
}

void dfs(int v, int d)
{
	static int timer = 1;

	tin[v] = timer++;

	verts[d].emplace_back(tin[v], col[v]);

	for(auto u: g[v])
		if(!tin[u])
			dfs(u, d + 1);

	tout[v] = timer++;
}

void solve()
{
	cin >> n >> m;

	for(int v = 1; v < n; ++v)
	{
		int u;
		cin >> u;
		--u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	{
		string c;
		cin >> c;

		for(int v = 0; v < n; ++v)
			col[v] = c[v] - 'a';
	}

	dfs(0, 0);

	for(int i = 0; i < n; ++i)
	{
		g[i].clear();
		g[i].shrink_to_fit();
	}

	for(int i = 0; i < n; ++i)
		verts[i].shrink_to_fit();

	for(int h = 0; h < MAX_N; ++h)
	{
		if(verts[h].empty())
			break;

		prefsum[h].resize(verts[h].size());
		prefsum[h].shrink_to_fit();

		prefsum[h][0] = (1 << verts[h][0].second);

		for(int i = 1; i < prefsum[h].size(); ++i)
			prefsum[h][i] = (1 << verts[h][i].second) ^ prefsum[h][i - 1];
	}

	for(int i = 0; i < m; ++i)
	{
		int v, h;
		cin >> v >> h;
		--v, --h;

		auto left  = lower_bound(verts[h].begin(), verts[h].end(), (pair<int, char>){tin[v], -1});
		auto right = lower_bound(verts[h].begin(), verts[h].end(), (pair<int, char>){tout[v], -1});

		int l = left - verts[h].begin();
		int r = right - verts[h].begin();
		--r;

		int ans = 0;

		if(l <= r && l < verts[h].size())
			for(int c = 0; c < N_COLS; ++c)
				ans += !!(getsum(h, c, l, r) & 1);

		cout << (ans > 1 ? "No\n" : "Yes\n");
	}
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}