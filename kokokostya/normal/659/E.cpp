#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector< vector<int> > g;
vector<char> used;
bool is = 1;

void dfs(int v, int p) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		if (g[v][i] != p) {
			if (used[g[v][i]]) { is = 1; }
			else { dfs(g[v][i], v); }
		}
	}

	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			is = 0;
			dfs(i, -1);
			if (!is) { ans++; }
		}
	}
	cout << ans;
	return 0;
}