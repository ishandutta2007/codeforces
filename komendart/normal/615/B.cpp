#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector< vector<int> > graph(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	long long res = 0;
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (auto j: graph[i]) {
			if (j < i) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i] * (long long) graph[i].size());
	}
	
	cout << res << '\n';
}