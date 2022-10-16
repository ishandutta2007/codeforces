#include <bits/stdc++.h>

using namespace std;

//#define int long long


vector<int> g[300000];

vector<int> used1(300000);

void dfs(int v) {
	used1[v] = true;
	for (auto u: g[v]) {
		if (!used1[u]) {
			dfs(u);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<bool> used(n);
	vector<bool> good(n);
	vector<int> cnt(n);
	vector<vector<int>> all(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		all[x].push_back(i);
		all[y].push_back(i);
		cnt[x]++;
		cnt[y]++;
		if (x == y) {
			good[x] = true;
			used[i] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		used1[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			continue;
		}
		int now = 0;
		int lol;
		for (auto u: all[i]) {
			if (!used[u]) {
				lol = u;
				now++;
			}
		}
		if (now == 1) {
			good[i] = true;
			used[lol] = true;
			ans++;
		}
		if (now == 2) {
		}
	}

	int ll = 0;
	while (true) {
		bool was = false;
		for (int i = n - 1; i >= 0; i--) {
			if (good[i]) {
				continue;
			}
			int now = 0;
			int lol;
			for (auto u: all[i]) {
				if (!used[u]) {
					lol = u;
					now++;
				}
			}
			if (now == 1) {
				was = true;
				good[i] = true;
				used[lol] = true;
				ans++;
			}
		}
		if (!was) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (good[i]) {
			continue;
		}
		int now = 0;
		int lol;
		for (auto u: all[i]) {
			if (!used[u]) {
				lol = u;
				now++;
			}
		}
		if (now == 2) {
			ll++;
			int a = all[i][0];
			int b = all[i][1];
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}
	int sz = 0;
	for (int i = 0; i < m; i++) {
		if (!used[i] && !used1[i]) {
			dfs(i);
			sz++;
		}
	}
	//cout << ans << " " << ll << " " << sz << endl;
	if (ll == 0) {
		cout << ans << endl;
	} else {
		cout << ans + ll + sz << endl;
	}
}
signed main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}