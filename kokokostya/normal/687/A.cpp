#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > g;
vector<char> used;
vector<int> col;
bool is = 1;

void dfs(int v, int val) {
	used[v] = 1;
	col[v] = val;
	val = (val + 1) % 2;
	for (int j = 0; j < g[v].size(); j++) {
		if (!used[g[v][j]]) {
			dfs(g[v][j], val);
		}
		else {
			if (col[g[v][j]] != val) { is = 0; }
		}
	}

	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	col.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) { dfs(i, 0); }
	}
	if (!is) { cout << -1; }
	else {
		vector<int> fir, sec;
		for (int i = 0; i < n; i++) {
			if (col[i]) { fir.push_back(i + 1); }
			else { sec.push_back(i + 1); }
		}
		cout << fir.size() << '\n';
		for (int i = 0; i < fir.size(); i++) {
			cout << fir[i] << ' ';
		}
		cout << '\n';
		cout << sec.size() << '\n';
		for (int i = 0; i < sec.size(); i++) {
			cout << sec[i] << ' ';
		}
	}
	return 0;
}