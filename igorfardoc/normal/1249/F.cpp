#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi dp, g;
int n, k;
vi a;

void dfs(int v, int p) {
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v);
	}
	for(int i = 0; i <= k; i++) {
		if(i == 0) {
			int here = a[v];
			for(int u : g[v]) {
				if(u == p) continue;
				here += dp[u][k];
			}
			dp[v][i] = here;
		}
		if(g[v].size() == 1 && g[v][0] == p) {
			continue;
		}
		if(g[v].size() == 1 && p == -1) {
			dp[v][i] = max(dp[v][i], dp[g[v][0]][max(0, i - 1)]);
			continue;
		}
		if(g[v].size() == 2 && p != -1) {
			for(int u : g[v]) {
				if(u == p) continue;
				dp[v][i] = max(dp[v][i], dp[u][max(0, i - 1)]);
			}
			continue;
		}
		for(int u1 : g[v]) {
			if(u1 == p) continue;
			for(int j = max(i - 1, 0); j <= k; j++) {
				int min1 = max(max(i - 1, k - j - 1), 0);
				if(min1 < j) min1 = j;
				int here = 0;
				for(int u : g[v]) {
					if(u == p) continue;
					if(u == u1) {
						here += dp[u][j];
						continue;
					}
					here += dp[u][min1];
				}
				dp[v][i] = max(dp[v][i], here);
			}

		}
	}
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
    cin >> n >> k;
    a.resize(n);
    g.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    dp.assign(n, vi(k + 1, 0));
    for(int i = 0; i < n - 1; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    dfs(0, -1);
    cout << dp[0][0];
}