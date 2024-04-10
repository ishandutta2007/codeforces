#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];
int d[200005];
int par[200005][18];

void dfs(int x, int p) {
	par[x][0] = p;
	for (int i=1; i<18; i++)
		par[x][i] = par[par[x][i-1]][i-1];

	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + 1;
		dfs(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<18; i++)
		if (k & (1 << i))
			x = par[x][i];
	return x;
}

int lca(int x, int y) {
	if (d[x] > d[y])
		swap(x, y);
	y = dizi(y, d[y] - d[x]);
	if (x == y)
		return x;
	for (int i=17; i>=0; i--) {
		int xx = par[x][i], yy = par[y][i];
		if (xx != yy)
			x = xx, y = yy;
	}
	return par[x][0];
}

int dist(int x, int y) {
	int z = lca(x, y);
	return d[x] + d[y] - 2*d[z];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int _m;
	cin >> n >> _m;
	for (int i=2; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs(1, 1);

	int u = 1, v = 1, duv = 0;
	for (int i=2; i<=n; i++) {
		int du = dist(i, u);
		int dv = dist(i, v);
		if (du == max(du, dv) && du > duv) {
			v = i;
			duv = du;
		} else if (dv == max(du, dv) && dv > duv) {
			u = i;
			duv = dv;
		}
	}
	cout << duv << '\n';
}