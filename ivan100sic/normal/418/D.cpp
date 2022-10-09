#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 262144;

struct segtreelazy {
	vector<int> a, b;

	segtreelazy() : a(2*maxn, 0), b(2*maxn, 0) {}

	void push(int x) {
		if (!b[x])
			return;
		if (x < maxn) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		a[x] += b[x];
		b[x] = 0;
	}

	void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] += v;
			push(x);
			return;
		}
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = max(a[2*x], a[2*x+1]);
	}

	int query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		push(x);
		if (r < xl || xr < l)
			return 0;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return max(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
	}
} drvo;

int p[200005][18];
int d[200005], el[200005], er[200005], et;
int n, q;
int ans[200005];
int cutedge[200005];
vector<int> pitanja[200005];
basic_string<int> e[200005];

void dfs1(int x, int par) {
	el[x] = ++et;
	p[x][0] = par;
	for (int i=1; i<18; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	for (int y : e[x]) {
		if (y == par)
			continue;
		d[y] = d[x] + 1;
		dfs1(y, x);
	}
	er[x] = et;
}

int dizi(int x, int y) {
	for (int i=0; i<18; i++) {
		if (y & (1 << i)) {
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

void dfs2(int x) {
	// obradi
	for (int i : pitanja[x]) {
		int w = cutedge[i], o = 0;
		if (el[w] <= el[x] && er[x] <= er[w]) {
			// ispod
			o = drvo.query(el[w], er[w]);
		} else {
			// nije
			o = max(
				drvo.query(1, el[w]-1),
				drvo.query(er[w]+1, n)
			);
		}
		ans[i] = max(ans[i], o);
	}
	// spusti se
	for (int y : e[x]) {
		if (y != p[x][0]) {
			drvo.update(1, n, +1);
			drvo.update(el[y], er[y], -2);
			dfs2(y);
			drvo.update(el[y], er[y], +2);
			drvo.update(1, n, -1);
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
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs1(1, 1);
	cin >> q;
	for (int i=0; i<q; i++) {
		int u, v;
		cin >> u >> v;
		if (d[u] > d[v])
			swap(u, v);
		int z = lca(u, v);
		int w = dizi(v, (d[u] + d[v] - 2*d[z] - 1)/2);
		cutedge[i] = w;
		pitanja[u].push_back(i);
		pitanja[v].push_back(i);
	}

	for (int i=1; i<=n; i++)
		drvo.update(el[i], el[i], d[i]);

	dfs2(1);
	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}