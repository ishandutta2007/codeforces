#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, s, t;
int ds[1005], dt[1005];
int adj[1005][1005];
basic_string<int> e[1005];

void bfs(int x, int* d) {
	fill(d+1, d+n+1, 123123123);
	d[x] = 0;
	basic_string<int> q = {x};
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (d[y] == 123123123) {
				d[y] = d[x] + 1;
				q += y;
			}
		}
	}
}

bool moze(int x, int y) {
	if (adj[x][y])
		return false;

	int nsp = min(ds[x] + 1 + dt[y], ds[y] + 1 + dt[x]);
	if (nsp < ds[t])
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s >> t;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
		adj[u][v] = adj[v][u] = 1;
	}

	bfs(s, ds);
	bfs(t, dt);

	int z = 0;

	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (moze(i, j))
				z++;
		}
	}

	cout << z << '\n';
}