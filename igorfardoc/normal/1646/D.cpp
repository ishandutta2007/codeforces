#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
vvi g;
vi w;
pair<int, ll> dp[200000][2];

void dfs(int v, int p) {
	pair<int, ll> sum1 = {0, 0};
	pair<int, ll> sum2 = sum1;
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v);
		sum1.first += dp[u][1].first;
		sum1.second += dp[u][1].second;
		auto here = max(dp[u][1], dp[u][0]);
		sum2.first += here.first;
		sum2.second += here.second;
	}
	dp[v][0] = {1 + sum1.first, sum1.second - g[v].size()};
	dp[v][1] = {sum2.first, sum2.second - 1};
}

void dfs2(int v, int p, int mod) {
	if(mod == 0) {
		w[v] = g[v].size();
		for(int u : g[v]) {
			if(u == p) continue;
			dfs2(u, v, 1);
		}
	} else {
		w[v] = 1;
		for(int u : g[v]) {
			if(u == p) continue;
			if(dp[u][0] > dp[u][1]) {
				dfs2(u, v, 0);
			} else {
				dfs2(u, v, 1);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	if(n == 2) {
		cout << "2 2\n1 1";
		return 0;
	}
	g.resize(n);
	w.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		--v;
		--u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	if(dp[0][0] > dp[0][1]) {
		cout << dp[0][0].first << ' ' << -dp[0][0].second << '\n';
		dfs2(0, -1, 0);
	} else {
		cout << dp[0][1].first << ' ' << -dp[0][1].second << '\n';
		dfs2(0, -1, 1);
	}
	for(const auto& el : w) {
		cout << el << ' ';
	}
}