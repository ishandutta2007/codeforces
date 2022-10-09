#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
vector<int> e[300005], f[300005];
set<pair<int, int>> g;

int idx[300005], low[300005], t;

void most(int x, int p) {
	t++;
	idx[x] = low[x] = t;
	for (int y : e[x]) {
		if (y == p)
			continue;
		if (idx[y] == 0) {
			most(y, x);
			low[x] = min(low[x], low[y]);
		} else {
			low[x] = min(low[x], idx[y]);
		}
	}

	// cerr << x << ' ' << idx[x] << ' ' << low[x] << '\n';

	if (low[x] == idx[x] && x != p) {
		// most
		g.insert({x, p});
		// cerr << "most " << x << ' ' << p << '\n';
	}
}

int cc[300005], ccc;

void oboji() {
	for (int i=1; i<=n; i++) {
		if (cc[i] == 0) {
			ccc++;
			cc[i] = ccc;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int x = q.front(); q.pop();
				for (int y : e[x])
					if (cc[y] == 0 && !g.count({x, y}) && !g.count({y, x})) {
						q.push(y);
						cc[y] = ccc;
					}
			}
		}
	}
}

vector<int> h[300005];

void daj_stablo() {
	for (int i=1; i<=n; i++) {
		for (int j : e[i]) {
			if (cc[j] != cc[i])
				h[cc[j]].push_back(cc[i]); // obrat posle
		}
	}
}

int dub[300005];

void dfs(int x, int p, int d) {
	dub[x] = d;
	for (int y : h[x])
		if (y != p)
			dfs(y, x, d+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	most(1, 1);
	oboji();
	daj_stablo();

	dfs(1, 1, 0);
	int r = max_element(dub+1, dub+ccc+1) - dub;
	dfs(r, r, 0);
	cout << *max_element(dub+1, dub+ccc+1) << '\n';

}