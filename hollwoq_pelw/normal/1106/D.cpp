#include <bits/stdc++.h>
using namespace std;

const int N = 550000;

vector<int> adj[N];
set<int> S;
int vis[N];
	
int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cur = 1;
	vector<int> ans;
	while (true) {
		ans.push_back(cur);
		vis[cur] = 1;
		if (ans.size() == n) break;
		for (int v : adj[cur]) if (!vis[v]) S.insert(v);
		cur = *S.begin();
		S.erase(cur);
	}
	for (int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}