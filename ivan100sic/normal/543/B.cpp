#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int da[3005], db[3005], dc[3005], dd[3005], du[3005];
int a, b, c, d, k, l, n, m;
basic_string<int> e[3005];

void bfs(int x0, int* d) {
	fill(d+1, d+n+1, -1);
	d[x0] = 0;
	queue<int> q;
	q.push(x0);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
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
	}

	cin >> a >> c >> k;
	cin >> b >> d >> l;

	bfs(a, da);
	bfs(b, db);
	bfs(c, dc);
	bfs(d, dd);

	if (da[c] <= k && db[d] <= l) {
		int sol = da[c] + db[d];
		for (int u=1; u<=n; u++) {
			bfs(u, du);
			for (int v=1; v<=n; v++) {
				int p = da[u] + du[v] + dc[v];
				int q = db[u] + du[v] + dd[v];
				int r = du[v];
				if (p <= k && q <= l) {
					sol = min(sol, p+q-r);
				}
			}
		}

		swap(b, d);
		bfs(b, db);
		bfs(d, dd);

		for (int u=1; u<=n; u++) {
			bfs(u, du);
			for (int v=1; v<=n; v++) {
				int p = da[u] + du[v] + dc[v];
				int q = db[u] + du[v] + dd[v];
				int r = du[v];
				if (p <= k && q <= l) {
					sol = min(sol, p+q-r);
				}
			}
		}

		cout << m - sol << '\n';
	} else {
		cout << "-1\n";
	}
}