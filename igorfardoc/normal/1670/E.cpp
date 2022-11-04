#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
vector<vector<pair<int, int>>> g;
vi ans1, ans2;
int now;
int n;

void dfs(int v, int p, bool d) {
	for(auto& u1 : g[v]) {
		int u = u1.first;
		int w = u1.second;
		if(u == p) continue;
		ans2[w] = now + n;
		ans1[u] = now;
		if(d) swap(ans2[w], ans1[u]);
		++now;
		dfs(u, v, !d);
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
		int p;
		cin >> p;
		n = 1 << p;
		g.assign(n, {});
		ans1.resize(n);
		ans2.resize(n - 1);
		now = 1;
		for(int i = 0; i < n - 1; i++) {
			int v, u;
			cin >> v >> u;
			--v;
			--u;
			g[v].push_back({u, i});
			g[u].push_back({v, i});
		}
		ans1[0] = n;
		dfs(0, -1, false);
		cout << 1 << '\n';
		for(const auto& el : ans1) {
			cout << el << ' ';
		}
		cout << '\n';
		for(const auto& el : ans2) {
			cout << el << ' ';
		}
		cout << '\n';
	}
}