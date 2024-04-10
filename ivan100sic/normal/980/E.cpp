#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, k;

vector<int> e[1000005];
int parent[20][1000005];
int b[1000005];

void dfs(int x, int p) {
	parent[0][x] = p;
	for (int i = 1; i < 20; i++) {
		parent[i][x] = parent[i - 1][parent[i - 1][x]];
	}
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x);
		}
	}
}

int put(int x) {
	int z = 1;
	if (b[x]) {
		return 0;
	}
	for (int i = 19; i >= 0; i--) {
		int y = parent[i][x];
		if (!b[y]) {
			z += 1 << i;
			x = y;
		}
	}
	return z;
}

void markiraj(int x) {
	while (!b[x]) {
		b[x] = 1;
		x = parent[0][x];
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	k = n - k;

	dfs(n, n);
	b[n] = 1;

	k--;

	for (int i = n - 1; i >= 1; i--) {
		int pt = put(i);
		if (pt <= k) {
			k -= pt;
			markiraj(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!b[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}

int main() {
	solve();
	// system("pause");
}