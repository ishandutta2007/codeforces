#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<10;
int n, m, W, _b, _w, vis[maxn], b[maxn], w[maxn];
vector<int> g[maxn];
vector<array<int, 2>> items;
vector<vector<array<int, 2>>> mitems;
void dfs(int v) {
	vis[v] = 1;
	mitems.back().push_back({b[v], w[v]});
	_b += b[v];
	_w += w[v];
	for(auto &i : g[v]) if(!vis[i]) dfs(i);
}
int dp[maxn][maxn];
void solve() {
	memset(dp, -0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < items.size(); i++) {
		for(int j = 0; j <= W; j++) {
			if(dp[i][j] < 0) continue;
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
			if(j + items[i][1] <= W)
				dp[i+1][j + items[i][1]] = max(dp[i+1][j + items[i][1]], items[i][0] + dp[i][j]);
		}
		for(auto [b, w] : mitems[i])
		for(int j = 0; j <= W; j++) {
			if(dp[i][j] < 0) continue;
			if(j + w <= W)
				dp[i+1][j + w] = max(dp[i+1][j + w], b + dp[i][j]);
		}
	}
	cout << dp[items.size()][W] << endl;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> W;
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		_b = 0, _w = 0;
		mitems.push_back({});
		dfs(i);
		items.push_back({_b, _w});
	}
	solve();
}
//?VK
//??V
//K?