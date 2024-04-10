#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;

bool f1 = false, f2 = false;

void dfs(int v, int d, int pr) {
	if (g[v].size() == 1) {
		if (d % 2) f1 = true;
		else f2 = true;
	}
	for (auto el : g[v]) if (el != pr) dfs(el, d + 1, v);
}

int main() {
	int n, k;
	cin >> n;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		if (g[i].size() > 1) k = i;
	}
	dfs(k, 0, -1);
	if (f2 && f1) {
		cout << 3 << " ";
	}
	else cout << 1 << " ";
	int res = n - 1;
	vector<bool> used(n, false);
	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1) {
			res--;
			used[g[i][0]] = true;
		}
	}
	for (auto x : used) res += x;
	cout << res;
}