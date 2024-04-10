#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
basic_string<int> e[100005];
int a[100005];
int d[100005];
int dub[100005];

int p[18][100005];

void bfs() {
	queue<int> q;
	fill(d+1, d+n+1, 123123123);
	for (int i=1; i<=n; i++) {
		if (a[i]) {
			q.push(i);
			d[i] = 0;
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == 123123123) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}

basic_string<int> extra;

void reset() {
	bfs();
	extra = {};
}

void dfs(int x, int pr) {
	p[0][x] = pr;
	for (int i=1; i<18; i++)
		p[i][x] = p[i-1][p[i-1][x]];
	for (int y : e[x])
		if (y != pr) {
			dub[y] = dub[x] + 1;
			dfs(y, x);
		}
}

int dizi(int x, int y) {
	for (int i=0; i<18; i++)
		if (y & (1 << i))
			x = p[i][x];
	return x;
}

int lca(int x, int y) {
	if (dub[x] > dub[y])
		swap(x, y);
	y = dizi(y, dub[y] - dub[x]);
	if (x == y)
		return x;
	for (int i=17; i>=0; i--) {
		int xx = p[i][x];
		int yy = p[i][y];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return p[0][x];
}

int treedist(int x, int y) {
	return dub[x] + dub[y] - 2 * dub[lca(x, y)];
}

int resi(int x) {
	int z = d[x];
	for (int y : extra) {
		z = min(z, treedist(x, y));
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	const size_t BLOCK = 200;

	dfs(1, 1);
	a[1] = 1;
	bfs();

	while (q--) {
		int t, v;
		cin >> t >> v;
		if (t == 1) {
			extra += v;
			a[v] = 1;
			if (extra.size() == BLOCK) {
				reset();
			}
		} else {
			cout << resi(v) << '\n';
		}
	}
}