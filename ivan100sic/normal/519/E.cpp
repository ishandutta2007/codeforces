#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int d[100005], p[100005][18], s[100005];
basic_string<int> e[100005];

void dfs(int x, int par) {

	p[x][0] = par;
	for (int i=1; i<18; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	s[x] = 1;

	for (int y : e[x]) {
		if (y == par)
			continue;
		d[y] = d[x] + 1;
		dfs(y, x);
		s[x] += s[y];
	}
}

int dizi(int x, int k) {
	for (int i=0; i<18; i++) {
		if (k & (1 << i)) {
			x = p[x][i];
		}
	}
	return x;
}

int lca(int x, int y) {
	if (d[x] > d[y])
		swap(x, y);
	y = dizi(y, d[y] - d[x]);
	if (x == y)
		return x;
	for (int i=17; i>=0; i--) {
		int xx = p[x][i];
		int yy = p[y][i];

		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return p[x][0];
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

	dfs(1, 1);

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;

		if (x == y) {
			cout << n << '\n';
			continue;
		}

		int z = lca(x, y);
		int l = d[x] + d[y] - 2*d[z];
		if (l % 2 == 1) {
			cout << "0\n";
			continue;
		}

		if (d[x] == d[y]) {
			int xx = dizi(x, d[x]-d[z]-1);
			int yy = dizi(y, d[y]-d[z]-1);
			cout << n - s[xx] - s[yy] << '\n';
		} else if (d[x] > d[y]) {
			int zz = dizi(x, l/2);
			int xx = dizi(x, l/2-1);
			cout << s[zz] - s[xx] << '\n';
		} else {
			int zz = dizi(y, l/2);
			int yy = dizi(y, l/2-1);
			cout << s[zz] - s[yy] << '\n';
		}
	}
}