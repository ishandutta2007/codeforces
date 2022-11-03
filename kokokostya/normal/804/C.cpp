#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>

using namespace std;

vector<int> col;
vector< vector<int> > a;
vector< vector<int> > g;
vector<bool> used;
bool taked[300007];

void dfs(int v) {
	used[v] = 1;
	for (int i : a[v])
		if (col[i - 1] != -1)
			taked[col[i - 1]] = 1;
	int cnt = 1;
	for (int i : a[v]) {
		if (col[i - 1] == -1) {
			while (taked[cnt])
				cnt++;
			col[i - 1] = cnt;
			taked[cnt] = 1;
		}
	}
	for (int i : a[v])
		if (col[i - 1] != -1)
			taked[col[i - 1]] = 0;
	for (int i : g[v]) {
		if (!used[i])
			dfs(i);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	col.resize(m, -1);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		int sz;
		cin >> sz;
		a[i].resize(sz);
		for (int j = 0; j < sz; j++)
			cin >> a[i][j];
	}
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	used.resize(n);
	dfs(0);
	int mx = 1;
	for (int i = 0; i < m; i++)
		mx = max(mx, col[i]);
	cout << mx << '\n';
	for (int i = 0; i < m; i++)
		if (col[i] == -1)
			col[i] = 1;
	for (int i : col)
		cout << i << ' ';
	return 0;
}