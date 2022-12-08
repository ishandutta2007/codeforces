#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int col;
vector<int> colors;
vector<int> used;
vector<vector<int>> g;

void dfs(int v) {
	colors[v] = col;
	for (int i : g[v]) {
		if (colors[i] == 0) {
			dfs(i);
		}
	}
}


bool check(int start, int cur) {
	used[cur] = 1;
	if (g[cur].size() != 2) return false;
	if (used[g[cur][0]] == 1 and used[g[cur][1]] == 1) {
		if(g[cur][0] == start or g[cur][1] == start) return true;
		return false;
	}
	if (used[g[cur][0]] == 1) return check(start, g[cur][1]);
	return check(start, g[cur][0]);
}



int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	int t1, t2;
	colors.resize(n + 1);
	used.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	col = 1;
	for (int i = 1; i <= n; i++) {
		if (colors[i] == 0) {
			dfs(i);
			col++;
		}
	}
	set<int> a;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a.find(colors[i]) == a.end()) {
			bool fl = check(i, i);
			if (fl) ans++;
			a.insert(colors[i]);
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}