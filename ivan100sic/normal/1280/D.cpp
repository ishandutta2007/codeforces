#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
ll v[3005];
basic_string<int> e[3005];

vector<pair<int, ll>> dfs(int x, int p) {
	vector<pair<int, ll>> dp = {{0, v[x]}};

	for (int y : e[x]) {
		if (y == p)
			continue;
		auto v = dfs(y, x);

		vector<pair<int, ll>> tmp(dp.size() + v.size() - 1, {-1, -1});
		for (int i=0; i<(int)dp.size(); i++) {
			for (int j=0; j<(int)v.size(); j++) {
				tmp[i+j] = max(tmp[i+j],
					{dp[i].first + v[j].first, dp[i].second + v[j].second});
			}
		}

		swap(tmp, dp);
	}

	dp.emplace_back(-1, -1);
	for (int i=0; i<(int)dp.size()-1; i++) {
		dp[i+1] = max(dp[i+1], {dp[i].first + (dp[i].second > 0), 0});
	}

	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=n; i++) {
			cin >> v[i];
			e[i].clear();
		}
		for (int i=1; i<=n; i++) {
			int x;
			cin >> x;
			v[i] = x - v[i];
		}
		for (int i=1; i<n; i++) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
			e[v] += u;
		}

		auto v = dfs(1, 1);
		int x = v[m-1].first + (v[m-1].second > 0);
		cout << x << '\n';
	}	
}