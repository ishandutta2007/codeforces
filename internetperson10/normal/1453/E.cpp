#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<vector<int>> adj;
vector<int> dep, mindep; // deepest child depth
int ans;

pair<int, int> dfs(int n, int par=-1) {
	int deepest = 0, shalest = 999999;
	for(int i : adj[n]) {
		if(i == par) continue;
		auto d = dfs(i, n);
		deepest = max(deepest, d.first);
		shalest = min(shalest, d.second);
	}
	if(shalest == 999999) shalest = 0;
	dep[n] = deepest; mindep[n] = shalest;
	// cout << n << ' ' << dep[n] << ' ' << mindep[n] << '\n';
	return {deepest+1, shalest+1};
}

int snack(int n, int par=-1) {
	// cout << n << '\n';
	vector<pair<int, int>> child;
	for(int i : adj[n]) {
		if(i != par) child.push_back({mindep[i], i});
	}
	sort(child.begin(), child.end());
	int prev = 0;
	if(par == -1) {
		reverse(child.begin(), child.end());
	}
	for(auto p : child) {
		int s = snack(p.second, n);
		if(p != child[0]) ans = max(ans, s+1);
		else if(par == -1) ans = max(ans, s);
	}
	return mindep[n]+1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ans = 0;
		int n;
		cin >> n;
		adj.resize(n);
		dep.resize(n);
		mindep.resize(n);
		for(int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(0);
		snack(0);
		cout << ans << '\n';
		vector<vector<int>>().swap(adj);
		vector<int>().swap(dep);
		vector<int>().swap(mindep);
	}
}