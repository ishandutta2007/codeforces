#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
basic_string<int> e[100005];
int l[100005], r[100005], t, d[100005], doo[1000005], ioo[1000005];

void dfs(int x) {
	l[x] = ++t;
	doo[t] = d[x];
	ioo[t] = x;
	for (int y : e[x]) {
		d[y] = d[x] + 1;
		dfs(y);
		doo[++t] = d[x];
		ioo[t] = x;
	}
	r[x] = t;
}

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int lo, hi, il, ih;

		/* CONSTRUCTOR */
		node_t(int lo = 123123123, int hi = -1, int il = -1, int ih = -1)
			: lo(lo), hi(hi), il(il), ih(ih) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (other.lo < lo) {
				lo = other.lo;
				il = other.il;
			}
			if (other.hi > hi) {
				hi = other.hi;
				ih = other.ih;
			}
			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

template<int MAXN>
struct segtree2 {
	
	struct node_t {
		/* DATA MEMBERS */
		int x, i;

		/* CONSTRUCTOR */
		node_t(int x = 123123123, int i = -1) : x(x), i(i) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (other.x < x) {
				x = other.x;
				i = other.i;
			}

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void add(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] += val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<131072> drvo;
segtree2<(1 << 20)> drvo2;

int range_lca(int u, int v) {
	if (u > v)
		return -1;
	auto g = drvo.get(u, v);
	auto b = drvo2.get(g.lo, g.hi);
	return b.i;
}

int remove_lca(int u, int x, int v) {
	int x1 = range_lca(u, x-1);
	int x2 = range_lca(x+1, v);

	if (x1 == -1)
		return d[x2];
	if (x2 == -1)
		return d[x1];

	int lele = min(l[x1], l[x2]);
	int rere = max(r[x1], r[x2]);
	return drvo2.get(lele, rere).x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x] += i;
	}

	dfs(1);

	for (int i=1; i<=n; i++) {
		drvo.set(i, {l[i], r[i], i, i});
	}
	for (int i=1; i<=t; i++)
		drvo2.set(i, {doo[i], ioo[i]});

	while (q--) {
		int u, v;
		cin >> u >> v;

		auto g = drvo.get(u, v);

		int lx = g.il;
		int rx = g.ih;

		int sol1 = remove_lca(u, lx, v);
		int sol2 = remove_lca(u, rx, v);

		if (sol1 > sol2)
			cout << lx << ' ' << sol1 << '\n';
		else
			cout << rx << ' ' << sol2 << '\n';
	}
}