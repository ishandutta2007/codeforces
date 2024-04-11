#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 20, mlg = 18, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct edge {
	ll from, to, cost, i;
};
vector<edge> g[1100];
int col[maxn], h[maxn], dp[maxn], cst[maxn], n, m, s, t, ban, used;
vi check;
ll best = 0;
void findtree(int v) {
	for (auto i : g[v]) {
		if (h[i.to])
			continue;
		h[i.to] = h[v] + 1;
		findtree(i.to);
		check.pb(i.i);
	}
}
bool dfs(int v, ll w, int u) {
	dp[v] = 0;
	bool ge = v==t;
	for (auto i : g[v]) {
		if(i.i==ban) continue;
		int nxt = i.to;
		if (h[nxt] == 0) { /* edge to child */
			h[nxt] = h[v] + 1;
			ge|=dfs(nxt, i.cost, i.i);
			dp[v] += dp[nxt];
		} else if (h[nxt] < h[v]) { /* edge upwards */
			dp[v]++;
		} else if (h[nxt] > h[v]) { /* edge downwards */
			dp[v]--;
		}
	}

	/* the parent edge isn't a back-edge, subtract 1 to compensate */
	dp[v]--;
	if (h[v] > 1 && ge && dp[v] == 0) {
		best = min(best, w);
		if(best==w) used=u;
	}
	return ge;
}
void solve() {
	memset(col, 0, sizeof col);
	memset(dp, 0, sizeof dp);
	memset(h, 0, sizeof h);
	used = -1;
	h[s] = 1;
	col[t] = 1;
	best = 1ll << 40;
	if (!dfs(s, -1, -1))
		best = 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		cst[i] = c;
		g[f].pb( { f, t, c, i });
		g[t].pb( { t, f, c, i });
	}
	h[s] = 1;
	findtree(s);
	pair<ll, vi> sol = { 1ll << 40, { } };
	check.pb(-1);
	for (auto i : check) {
		ban = i;
		solve();
		best += cst[i];
		pair<ll, vi> cur = { best, vi() };
		if (i != -1)
			cur.second.pb(i);
		if (used != -1)
			cur.second.pb(used);
		sol = min(sol, cur);
	}
	if (sol.first == (1ll << 40))
		return cout << -1, 0;
	cout << sol.first << "\n";
	cout << sol.second.size() << "\n";
	for (auto i : sol.second)
		cout << i + 1 << " ";
	return 0;
}