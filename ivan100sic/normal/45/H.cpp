#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[905], e2[905], g[905], h[905], listovi;
bool mostovi[905][905], sve_grane[905][905];
int bcc[905], kk;

int idx[905], low[905], t;

void dfs(int x, int p) {
	idx[x] = low[x] = ++t;
	for (int y : e[x]) {
		if (y == p)
			continue;
		if (idx[y] == 0) {
			dfs(y, x);
			low[x] = min(low[x], low[y]);
		} else {
			low[x] = min(low[x], idx[y]);
		}
	}
	if (idx[x] == low[x]) {
		mostovi[x][p] = 1;
		mostovi[p][x] = 1;
	}
}

void nadji(int x) {
	for (int y : e2[x]) {
		if (bcc[y] == 0) {
			bcc[y] = bcc[x];
			nadji(y);
		}
	}
}

void drvo(int x, int p) {
	if (g[x].size() == 1)
		listovi += x;
	for (int y : g[x]) {
		if (y != p) {
			drvo(y, x);
		}
	}
}

basic_string<pair<int, int>> sol;

void spoji(int x, int y) {
	for (int u : h[x]) {
		for (int v : h[y]) {
			if (!sve_grane[u][v]) {
				sol += {u, v};
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
		sve_grane[u][v] = 1;
		sve_grane[v][u] = 1;
	}

	dfs(1, 1);
	for (int x=1; x<=n; x++) {
		for (int y : e[x]) {
			if (!mostovi[x][y]) {
				e2[x] += y;
			}
		}
	}

	for (int i=1; i<=n; i++) {
		if (bcc[i] == 0) {
			bcc[i] = ++kk;
			nadji(i);
		}
	}

	// cerr << "dbg\n";
	// for (int i=1; i<=n; i++)
	// 	cerr << i << ' ' << bcc[i] << '\n';

	for (int i=1; i<=n; i++)
		h[bcc[i]] += i;

	if (kk == 1) {
		cout << "0\n";
		return 0;
	} else if (kk == 2) {
		if (n == 2) {
			cout << "-1\n";
			return 0;
		}
	}

	// vrati i napravi stablo
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (!mostovi[i][j])
				continue;
			int x = bcc[i];
			int y = bcc[j];
			g[x] += y;
			g[y] += x;
		}
	}

	drvo(1, 1);

	// for (int x : listovi)
	// 	cerr << "list " << x << '\n';
	// cerr << '\n';

	// spoji redom to sto treba
	if (listovi.size() % 2) {
		spoji(listovi[listovi.size() - 2], listovi[listovi.size() - 1]);
		listovi.pop_back();
	}
	for (int i=0; i<(int)listovi.size() / 2; i++) {
		int x = listovi[i];
		int y = listovi[i + (int)listovi.size() / 2];
		spoji(x, y);
	}
	cout << sol.size() << '\n';
	for (auto p : sol)
		cout << p.first << ' ' << p.second << '\n';
}