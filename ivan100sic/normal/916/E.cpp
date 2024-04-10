#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];

namespace lca {
	const int MAX_LOG = 18;
	const int MAX_N = 100005;

	int p[MAX_LOG][MAX_N];
	int dub[MAX_N];
	int sz[MAX_N], l[MAX_N], r[MAX_N], lrt;

	void dfs(int x, int par) {
		p[0][x] = par;
		for (int i=1; i<MAX_LOG; i++) {
			p[i][x] = p[i-1][p[i-1][x]];
		}

		sz[x] = 1;
		l[x] = ++lrt;

		for (int y : e[x]) {
			if (y != par) {
				dub[y] = dub[x] + 1;
				dfs(y, x);
				sz[x] += sz[y];
			}
		}

		r[x] = lrt;
	}

	int dizi(int x, int v) {
		for (int i=0; i<MAX_LOG; i++) {
			if (v & (1 << i)) {
				x = p[i][x];
			}
		}
		return x;
	}

	bool ispod(int a, int b) {
		return l[b] <= l[a] && r[a] <= r[b];
	}

	int lca(int a, int b) {
		if (dub[a] > dub[b]) {
			a = dizi(a, dub[a] - dub[b]);
		}
		if (dub[b] > dub[a]) {
			b = dizi(b, dub[b] - dub[a]);
		}

		if (a == b) {
			return a;
		}

		for (int i=MAX_LOG-1; i>=0; i--) {
			int aa = p[i][a];
			int bb = p[i][b];

			if (aa != bb) {
				a = aa;
				b = bb;
			}
		}

		return p[0][a];
	}

	int dist(int a, int b) {
		int c = lca(a, b);
		return dub[a] + dub[b] - 2*dub[c];
	}

	bool kolinear(int a, int b, int c) {
		return dist(a, b) + dist(b, c) == dist(a, c);
	}

	int kth(int a, int b, int k) {
		int c = lca(a, b);
		if (k <= dub[a] - dub[c]) {
			return dizi(a, k);
		} else {
			return dizi(b, (dub[a] + dub[b] - 2*dub[c]) - k);
		}
	}
}

using namespace lca;

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		ll x;

		updater(ll x = 0) : x(x) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x += other.x;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		ll s, len;

		/* CONSTRUCTOR */
		node_t(ll s = 0, ll len = 0) : s(s), len(len) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			s += other.s;
			len += other.len;

			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			s += other.x * len;

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];
	updater b[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t(0, 1);
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	void push(int i) {
		if (b[i]) {
			a[i] += b[i];
			if (i < MAXN) {
				b[2*i] += b[i];
				b[2*i+1] += b[i];
			}
			b[i] = updater();
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void update(int l, int r, updater val, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			b[node] += val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		update(l, r, val, 2*node, nl, nm);
		update(l, r, val, 2*node+1, nm+1, nr);
		a[node] = a[2*node] + a[2*node+1];
	}
};

segtree_lazy<131072> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> n >> q;
	vector<ll> zasto(n+1);
	for (int i=1; i<=n; i++)
		cin >> zasto[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	drvo.init();
	dfs(1, 1);
	for (int i=1; i<=n; i++)
		drvo.update(l[i], l[i], zasto[i]);
	int root = 1;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> root;
		} else if (t == 3) {
			int x;
			cin >> x;
			if (x == root) {
				cout << drvo.get(1, n).s << '\n';
			} else if (ispod(root, x)) {
				int y = dizi(root, dub[root] - dub[x] - 1);
				cout << drvo.get(1, n).s - drvo.get(l[y], r[y]).s << '\n';
			} else {
				cout << drvo.get(l[x], r[x]).s << '\n';
			}
		} else {
			int u, v, x;
			cin >> u >> v >> x;

			int z1 = lca::lca(u, v);
			int z2 = lca::lca(u, root);
			int z3 = lca::lca(v, root);

			int middle = -1;
			if (kolinear(u, z1, root) && kolinear(v, z1, root))
				middle = z1;
			else if (kolinear(u, z2, v) && kolinear(root, z2, v))
				middle = z2;
			else
				middle = z3;

			if (middle == root) {
				drvo.update(1, n, x);
			} else if (ispod(root, middle)) {
				int y = dizi(root, dub[root] - dub[middle] - 1);
				drvo.update(1, n, x);
				drvo.update(l[y], r[y], -x);
			} else {
				drvo.update(l[middle], r[middle], x);
			}
		}
	}
}