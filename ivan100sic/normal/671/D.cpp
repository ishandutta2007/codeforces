#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct offer {
	int c, d;
};

void mn(ll& x, ll y) {
	x = min(x, y);
}

void no() {
	cout << "-1\n";
	exit(0);
}

int n, m;
basic_string<int> e[300005];
vector<offer> g[300005];
int p[300005][19];
int dub[300005];

void dfs1(int x, int pa) {
	p[x][0] = pa;
	for (int i=1; i<19; i++) {
		p[x][i] = p[p[x][i-1]][i-1];
	}
	for (int y : e[x]) {
		if (y == pa)
			continue;
		dub[y] = dub[x] + 1;
		dfs1(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<19; i++) {
		if (k & (1 << i)) {
			x = p[x][i];
		}
	}
	return x;
}

int lca(int x, int y) {
	if (dub[x] > dub[y])
		swap(x, y);
	y = dizi(y, dub[y] - dub[x]);
	if (x == y)
		return x;
	for (int i=18; i>=0; i--) {
		int xx = p[x][i];
		int yy = p[y][i];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return p[x][0];
}

const ll inf = 1e18;
const int hi = 300005;

struct node {
	int l, r;
	ll v, lz;
	node() : l(0), r(0), v(inf), lz(0) {}
} b[300005 * 20]; int bsz;

void push(int x) {
	if (!x) return;
	ll& z = b[x].lz;
	if (!z) return;
	if (b[x].l) b[b[x].l].lz += z;
	if (b[x].r) b[b[x].r].lz += z;
	b[x].v += z;
	z = 0;
}

int update(int x, int p, ll v, int xl=0, int xr=hi) {
	if (!x) x = ++bsz;
	push(x);
	mn(b[x].v, v);
	if (xl == xr)
		return x;
	int xm = (xl+xr) >> 1;
	if (p <= xm)
		b[x].l = update(b[x].l, p, v, xl, xm);
	else
		b[x].r = update(b[x].r, p, v, xm+1, xr);
	return x;
}

ll query(int x, int l, int r, int xl=0, int xr=hi) {
	push(x);
	if (!x || r < xl || xr < l)
		return inf;
	if (l <= xl && xr <= r)
		return b[x].v;
	int xm = (xl+xr) >> 1;
	return min(
		query(b[x].l, l, r, xl, xm),
		query(b[x].r, l, r, xm+1, xr));
}

int spoji(int x, int y) {
	push(x);
	push(y);
	if (!x) return y;
	if (!y) return x;
	b[x].l = spoji(b[x].l, b[y].l);
	b[x].r = spoji(b[x].r, b[y].r);
	b[x].v = min({b[x].v, b[y].v, b[b[x].l].v, b[b[x].r].v});
	return x;
}

void dump(int x, int xl=0, int xr=hi) {
	if (!x) return;
	push(x);
	if (b[x].v >= inf / 2)
		return;
	if (xl == xr) {
		cerr << "dump " << xl << ' ' << b[x].v << '\n';
	} else {
		int xm = (xl+xr) >> 1;
		dump(b[x].l, xl, xm);
		dump(b[x].r, xm+1, xr);
	}
}

ll dp[300005];

int solve(int x, int p) {
	int r = ++bsz;
	ll a = 0;
	for (int y : e[x]) {
		if (y == p)
			continue;
		int t = solve(y, x);
		ll q = query(t, 0, dub[x]);
		a += q;
		if (a >= inf / 2)
			no();
		b[t].lz -= q;
		r = spoji(r, t);
	}
	dp[x] = a;
	for (auto [c, d] : g[x])
		r = update(r, d, c);
	b[r].lz += a;

	// cerr << "dumping " << x << '\n';
	// dump(r);
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs1(1, 1);

	for (int i=0; i<m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		int w = lca(u, v);
		if (w != u) {
			g[u].push_back({c, dub[w]});
		}
	}

	solve(1, 1);

	// for (int i=1; i<=n; i++) {
	// 	cerr << i << ": " << dp[i] << '\n';
	// }

	cout << dp[1] << '\n';
}