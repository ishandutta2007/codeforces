#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

vector< vector<int> > g;
vector<bool> used;

void dfs(int v) {
	used[v] = 1;
	for (int i : g[v]) {
		if (!used[i])
			dfs(i);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		g[i].push_back(p[i] - 1);
		g[p[i] - 1].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}