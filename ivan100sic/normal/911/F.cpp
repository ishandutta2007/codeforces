#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];
int d1[200005], p[200005], d2[200005], f, g, h;

void bfs(int x, int* d) {
	queue<int> q;
	q.push(x);
	fill(d+1, d+n+1, -1);
	d[x] = 0;
	p[x] = -1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				p[y] = x;
				q.push(y);
			}
		}
	}
}

bool on_diam[200005];

ll z;
basic_string<pair<int, int>> sol;

void dfs_brate(int x, int p) {
	for (int y : e[x]) {
		if (y != p) {
			dfs_brate(y, x);
		}
	}
	if (!on_diam[x]) {
		if (d1[x] > d2[x]) {
			z += d1[x];
			sol += {x, f};
		} else {
			z += d2[x];
			sol += {x, g};
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	bfs(1, d1);
	f = max_element(d1+1, d1+n+1) - d1;
	bfs(f, d1);
	g = max_element(d1+1, d1+n+1) - d1;
	int diam = d1[g];
	h = g;
	basic_string<int> dnodes;
	for (int i=0; i<diam; i++) {
		on_diam[h] = 1;
		dnodes += h;
		h = p[h];
	}
	on_diam[f] = 1;
	bfs(g, d2);

	dfs_brate(f, f);

	for (int i=0; i<diam; i++) {
		z += diam - i;
		sol += {dnodes[i], f};
	}

	cout << z << '\n';
	for (auto [x, y] : sol)
		cout << x << ' ' << y << ' ' << x << '\n';
}