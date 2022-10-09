#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m;
int a[100005];
vector<int> c[100005];

vector<pair<int, int>> e[100005];

int vis[100005];

void dfs(int x, int d) {
	vis[x] = d;
	for (auto p : e[x]) {
		if (vis[p.first] == -1) {
			dfs(p.first, d ^ p.second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=m; i++) {
		int sz;
		cin >> sz;
		while (sz--) {
			int x;
			cin >> x;
			c[x].push_back(i);
		}
	}

	for (int i=1; i<=n; i++) {
		int u = c[i][0];
		int v = c[i][1];
		int w = 1 - a[i];

		// cerr << u << ' ' << v << ' ' << w << '\n';

		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}

	fill(vis+1, vis+m+1, -1);

	for (int i=1; i<=m; i++) {
		if (vis[i] == -1) {
			dfs(i, 0);
		}
	}

	/*
	for (int i=1; i<=m; i++) {
		cerr << vis[i] << '\n';
	}
	*/

	for (int i=1; i<=n; i++) {
		int u = c[i][0];
		int v = c[i][1];
		int w = 1 - a[i];		

		if (vis[u] ^ vis[v] ^ w) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";






}