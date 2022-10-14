#include <bits/stdc++.h>

using namespace std;

vector<long long> full;
vector<long long> prof;
vector<long long> cost;
vector<vector<pair<int, long long>>> g;

void dfs(int v = 1, int p = -1) {
	prof[v] = 0;
	full[v] = 0;
	for(auto& u : g[v]) {
		int to = u.first;
		if(to == p)
			continue;
		dfs(to, v);
		if(prof[v] < (cost[v] - u.second + max(cost[to], prof[to]))) {
			full[v] = prof[v];
			prof[v] = (cost[v] - u.second + max(cost[to], prof[to]));
		} else if(full[v] < (cost[v] - u.second + max(cost[to], prof[to]))){
			full[v] = (cost[v] - u.second + max(cost[to], prof[to]));
		}
	}
	full[v] += prof[v] - (full[v] != 0 ? cost[v] : 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, u, v, c;
	cin >> n;
	full.resize(n + 1);
	prof.resize(n + 1);
	cost.resize(n + 1);
	g.resize(n + 1);

	for(size_t i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for(size_t i = 1; i < n; i++) {
		cin >> u >> v >> c;
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}

	dfs();

	cout << max({*max_element(prof.begin(), prof.end()), *max_element(full.begin(), full.end()), *max_element(cost.begin(), cost.end())});
}