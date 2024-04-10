#include <bits/stdc++.h>

using namespace std;

int c = 0;

vector<vector<int>> adj, adj2, adj3;
vector<vector<int>> ccs;
vector<int> vis;
bool taken[200001];
int cc[200001];

void dfs(int n, int p) {
	taken[n] = true;
	for(int i = 0; i < adj[n].size(); i++) {
		if(taken[adj[n][i]]) continue;
		dfs(adj[n][i], n);
	}
	vis.push_back(n);
}

void dfs2(int n, int p) {
	taken[n] = true;
	for(int i = 0; i < adj2[n].size(); i++) {
		if(taken[adj2[n][i]]) continue;
		dfs2(adj2[n][i], n);
	}
	cc[n] = c;
	// cout << n << ' ' << cc[n] << '\n';
}

bool dfs3(int n, int p) {
	taken[n] = true;
	bool ans = false;
	if(ccs[cc[n]].size() > 1) ans = true;
	for(int i = 0; i < adj3[n].size(); i++) {
		if(taken[adj3[n][i]]) continue;
		ans |= dfs3(adj3[n][i], n);
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	int ans = n;
	adj.resize(n);
	adj2.resize(n);
	adj3.resize(n);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj2[y].push_back(x);
		adj3[x].push_back(y);
		adj3[y].push_back(x);
	}
	for(int i = 0; i < n; i++) {
		if(taken[i]) continue;
		dfs(i, -1);
	}
	for(int i = 0; i < n; i++) taken[i] = false;
	for(int i = n-1; i >= 0; i--) {
		if(taken[vis[i]]) continue;
		dfs2(vis[i], -1);
		c++;
	}
	ccs.resize(c);
	for(int i = 0; i < n; i++) ccs[cc[i]].push_back(i);
	for(int i = 0; i < n; i++) taken[i] = false;
	for(int i = 0; i < n; i++) {
		if(taken[i]) continue;
		if(!dfs3(i, -1)) ans--;
	}
	cout << ans << '\n';
}