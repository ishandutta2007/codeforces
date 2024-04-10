#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int sz[3000][3000];
int par[3000][3000];
vvi g;
ll dp[3000][3000];

void dfs(int start, int v, int p) {
	sz[start][v] = 1;
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(start, u, v);
		sz[start][v] += sz[start][u];
	}
	par[start][v] = p;
}

ll calc_dp(int v, int u) {
	//cout << v << ' ' << u << endl;
	if(v > u) {
		swap(v, u);
	}
	if(v == u) {
		return 0;
	}
	if(dp[v][u] != 0 || v == u) {
		return dp[v][u];
	}
	ll here = max(calc_dp(v, par[v][u]), calc_dp(u, par[u][v]));
	dp[v][u] = here + (ll)sz[v][u] * sz[u][v];
	return dp[v][u];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    for(int i = 0; i < n; i++) {
    	dfs(i, i, -1);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
    	for(int j = i + 1; j < n; j++) {
    		ans = max(ans, calc_dp(i, j));
    	}
    }
    cout << ans;
}