#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<pair<int, int>> e[1005];
int w[1005], p[1005], d[1005];
basic_string<int> listovi[1005];

void dfs(int x, int par) {
	int ch = 0;
	for (auto [y, z] : e[x]) {
		if (y == par)
			continue;
		ch++;
		w[y] = z;
		p[y] = x;
		d[y] = d[x] + 1;
		dfs(y, x);
		listovi[x] += listovi[y];
	}
	if (!ch)
		listovi[x] += x;
}

vector<tuple<int, int, int>> sol;

void path_add(int x, int y, int z) {
	sol.emplace_back(x, y, z);
	while (x != y && x && y) {
		if (d[x] < d[y])
			swap(x, y);
		w[x] += z;
		x = p[x];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}

	for (int i=1; i<=n; i++)
		if (e[i].size() == 2) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";

	int root = -1;
	for (int i=1; i<=n; i++)
		if (e[i].size() == 1)
			root = i;
	dfs(root, root);

	for (int i=1; i<=n; i++) {
		if (e[i].size() == 1 && i != root) {
			path_add(i, root, -w[i]);
		}
	}

	basic_string<int> sd;
	for (int i=1; i<=n; i++) {
		if (e[i].size() > 1) {
			sd += i;
		}
	}
	sort(sd.begin(), sd.end(), [&](int x, int y) {
		return d[x] > d[y];
	});

	for (int i : sd) {
		if (e[i].size() > 1) {
			int u = listovi[i].front();
			int v = listovi[i].back();
			// cerr << i << ' ' << u << ' ' << v << '\n';
			int t = w[i];
			path_add(root, u, -t/2);
			path_add(root, v, -t/2);
			path_add(u, v, t/2);
		}
	}

	// cerr << "Root = " << root << '\n';
	// for (int i=1; i<=n; i++) {
	// 	cerr << i << ' ' << w[i] << '\n';
	// }

	cout << sol.size() << '\n';
	for (auto [x, y, z] : sol)
		cout << x << ' ' << y << ' ' << -z << '\n';

}