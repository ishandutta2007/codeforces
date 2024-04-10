#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>, greater<int>> m;
vector<vector<int>> adj;
int ans = 0;

void bfs(int x, int p, int d) {
	if(m.find(d) == m.end()) m[d] = vector<int>();
	m[d].push_back(x);
	for(int i = 0; i < adj[x].size(); i++) {
		if(abs(adj[x][i]) == p) continue;
		if(adj[x][i] > 0) bfs(abs(adj[x][i]), x, d-1);
		else bfs(abs(adj[x][i]), x, d+1);
	}
}

void dfs(int x, int p) {
	for(int i = 0; i < adj[x].size(); i++) {
		if(abs(adj[x][i]) == p) continue;
		if(adj[x][i] > 0) {
			ans++;
		}
		dfs(abs(adj[x][i]), x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	adj.resize(n+1);
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(-x);
	}
	dfs(1, 0);
	bfs(1, 0, ans);
	for(auto p : m) {
		cout << n - 1 - p.first << '\n';
		sort(p.second.begin(), p.second.end());
		for(int i = 0; i < p.second.size(); i++) cout << p.second[i] << ' ';
		cout << '\n';
		break;
	}
}