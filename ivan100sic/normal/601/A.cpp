#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[405][405];
int d[405];

int bfs(int e) {
	queue<int> q;
	fill(d+1, d+n+1, -1);
	q.push(1);
	d[1] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y=1; y<=n; y++) {
			if (a[x][y] == e && d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	return d[n];
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
		a[u][v] = true;
		a[v][u] = true;
	}

	cout << bfs(1 - a[1][n]);
}