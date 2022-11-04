#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
vvi g;
vi ans;

void dfs(int v, int p, int s) {
	ans[v] = s * g[v].size();
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v, -s);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		g.assign(n, {});
		ans.resize(n);
		for(int i = 0; i < n - 1; i++) {
			int v, u;
			cin >> v >> u;
			--v;
			--u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		dfs(0, -1, 1);
		for(const auto& el : ans) {
			cout << el << ' ';
		}
		cout << '\n';
	}
}