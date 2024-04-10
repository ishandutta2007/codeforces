#include <bits/stdc++.h>

using namespace std;

bool bad[100001], taken[100001];
int dp[100001];
vector<vector<int>> adj;

int ans = 0, k;

void dfs(int x, int par) {
	// cout << "At " << x << '\n';
	if(bad[x]) {
		if(par == -1) dp[x] = 1;
		else dp[x] = dp[par]+1;
	}
	// cout << "Bad " << dp[x] << '\n';
	if(dp[x] >= k) return;
	if(adj[x].size() == 1 && par > -1) {
		ans++;
	}
	for(int i = 0; i < adj[x].size(); i++) {
		if(adj[x][i] == par) continue;
		dfs(adj[x][i], x);
	}
}

int main() {
	int n;
	cin >> n >> k;
	k++;
	adj.resize(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x) bad[i] = true;
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0, -1);
	cout << ans << '\n';
	return 0;
}