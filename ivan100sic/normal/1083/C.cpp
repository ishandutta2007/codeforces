#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];
int p[200005], pinv[200005];

namespace lca {
	const int MAX_N = 262144;

	int dub[MAX_N];
	int l[MAX_N], r[MAX_N], lrt;
	int flat[5 * MAX_N];

	void dfs(int x, int par) {
		l[x] = ++lrt;
		flat[lrt] = dub[x];

		for (int y : e[x]) {
			if (y != par) {
				dub[y] = dub[x] + 1;
				dfs(y, x);
				flat[++lrt] = dub[x];
			}
		}

		r[x] = ++lrt;
		flat[lrt] = dub[x];
	}

	const int T = 1 << 20;
	const int W = 20;

	int g[W][T], l22[T];

	void pripremi_rmq() {
		for (int i=0; i<T; i++) {
			g[0][i] = flat[i];
			if (i > 1)
				l22[i] = l22[i >> 1] + 1;
		}
		for (int j=1; j<W; j++) {
			int h = 1 << (j-1);
			for (int i=0; i<T-h-h; i++)
				g[j][i] = min(g[j-1][i], g[j-1][i+h]);
		}
	}

	int rmq(int l, int r) {
		int w = l22[r-l+1];
		int z = min(g[w][l], g[w][r-(1<<w)+1]);

		// cerr << l << ' ' << r << '\n';
		// for (int i=l; i<=r; i++)
		// 	cerr << flat[i] << ' ';
		// cerr << '\n';
		// for (int i=l; i<=r; i++)
		// 	cerr << g[1][i] << ' ';
		// cerr << '\n';
		// for (int i=l; i<=r; i++)
		// 	cerr << g[2][i] << ' ';
		// cerr << '\n';
		// for (int i=l; i<=r; i++)
		// 	cerr << g[3][i] << ' ';
		// cerr << '\n';
		// cerr << " a ja naso " << z << " sa " << w << '\n';
		// cerr << "delovi: " << g[w][l] << " " << g[w][r-(1<<w)+1] << '\n';
		return z;
	}

	int dist(int a, int b) {
		if (a == b)
			return 0;
		if (l[a] > l[b])
			swap(a, b);
		if (r[b] < r[a])
			return dub[b] - dub[a];
		return dub[a] + dub[b] - 2 * rmq(l[a], r[b]);
	}

	bool kolinear(int a, int b, int c) {
		if (a == b || b == c || a == c)
			return true;
		return dist(a, b) + dist(b, c) == dist(a, c);
	}
}

template<int MAXN>
struct segtree {

	struct node_t {
		/* DATA MEMBERS */
		int tip;
		int x, y, dc;

		/* CONSTRUCTOR */
		node_t() : tip(0), x(0), y(0) {}

		node_t(int x) : tip(1), x(x), y(x), dc(0) {}

		node_t(int t, int x, int y, int dc) :
			tip(t), x(x), y(y), dc(dc) {}

		node_t& operator+= (const node_t& other) {
			if (tip == 2 || other.tip == 2)
				return *this = {2, 0, 0, 0};
			if (tip == 0)
				return *this = other;
			if (other.tip == 0)
				return *this;
			// proveri
			int dxx = lca::dist(x, other.x);
			int dxy = lca::dist(x, other.y);
			int dyx = lca::dist(y, other.x);
			int dyy = lca::dist(y, other.y);
			int dja = dc;
			int don = other.dc;

			int mx = max({dxx, dxy, dyx, dyy, dja, don});

			int ex = -1, ey = -1;

			if (mx == dxx)
				ex = x, ey = other.x;
			if (mx == dxy)
				ex = x, ey = other.y;
			if (mx == dyx)
				ex = y, ey = other.x;
			if (mx == dyy)
				ex = y, ey = other.y;
			if (mx == dja)
				ex = x, ey = y;
			if (mx == don)
				ex = other.x, ey = other.y;

			bool ok = true;
			if (ok) ok &= lca::kolinear(ex, x, ey);
			if (ok) ok &= lca::kolinear(ex, y, ey);
			if (ok) ok &= lca::kolinear(ex, other.x, ey);
			if (ok) ok &= lca::kolinear(ex, other.y, ey);

			if (!ok) {
				return *this = {2, 0, 0, 0};
			} else {
				return *this = {1, ex, ey, mx};
			}
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	vector<node_t> a;
	bool dirty;
	int seek_cache;

	segtree() {}

	segtree(int _) {
		dirty = true;
		a.resize(2*MAXN);
		for (int i=0; i<n; i++) {
			a[i+MAXN] = node_t(pinv[i]);
		}
		for (int i=n; i<MAXN; i++)
			a[i+MAXN] = node_t();
		for (int i=MAXN-1; i>=1; i--)
			a[i] = a[2*i] + a[2*i+1];
	}

	int seek__(int x = 1, node_t prefix = node_t(), int xl = 0, int xr = MAXN) {
		if ((prefix + a[x]).tip < 2)
			return xr;
		if (x >= MAXN)
			return xl;
		int xm = (xl + xr) >> 1;
		int z = seek__(2*x, prefix, xl, xm);
		if (z < xm)
			return z;
		return seek__(2*x+1, prefix + a[2*x], xm, xr);
	}

	int seek() {
		if (dirty) {
			seek_cache = seek__();
			dirty = false;
		}
		return seek_cache;
	}

	// samo za debug
	node_t get(int l, int r, int x = 1, int xl = 0, int xr = MAXN-1) {
		if (r < xl || xr < l)
			return {};
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl + xr) >> 1;
		return get(l, r, 2*x, xl, xm) + get(l, r, 2*x+1, xm+1, xr);
	}

	void set(int pos, node_t val) {
		dirty = true;
		pos += MAXN;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<262144> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
		pinv[p[i]] = i;
	}
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x] += i;
		e[i] += x;
	}
	lca::dfs(1, 1);
	lca::pripremi_rmq();

	// for (int i=1; i<=n; i++) {
	// 	for (int j=1; j<=n; j++) {
	// 		cerr << lca::dist(i, j) << ' ';
	// 	}
	// 	cerr << '\n';
	// }

	drvo = segtree<262144>(0);
	int t;
	cin >> t;
	while (t--) {
		int tt;
		cin >> tt;
		if (tt == 1) {
			int i, j;
			cin >> i >> j;
			int x = p[i];
			int y = p[j];
			swap(p[i], p[j]);
			swap(pinv[x], pinv[y]);
			drvo.set(x, j);
			drvo.set(y, i);	
		} else {
			int z = drvo.seek();
			z = min(z, n);
			cout << z << '\n';
		}
	}
}