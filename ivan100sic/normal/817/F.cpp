// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class U, class F, class G, class H>
struct segtreelazy {
	struct node { T v; U u; };
	int maxn;
	vector<node> a;
	T e; U eu;
	F f; G g; H h;
	// Add two elements
	// Add two updaters
	// Add an element and an update
	// Neutral element
	// Neutral update
	// Bottom level element
	segtreelazy(int n, F f, G g, H h, T e = T(), U eu = U(), T v = T()) :
		e(e), eu(eu), f(f), g(g), h(h)
	{
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, node{v, eu});
		for (int i=maxn-1; i; i--)
			a[i].v = f(a[2*i].v, a[2*i+1].v);
	}

	void push(int x) {
		a[x].v = h(a[x].v, a[x].u);
		if (x < maxn) {
			a[2*x  ].u = g(a[2*x  ].u, a[x].u);
			a[2*x+1].u = g(a[2*x+1].u, a[x].u);
		}
		a[x].u = eu;
	}

	void update(int l, int r, const U& u, int x, int xl, int xr) {
		if (r <= xl || xr <= l)
			return push(x);
		if (l <= xl && xr <= r)
			return a[x].u = g(a[x].u, u), push(x);
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, u, 2*x  , xl, xm);
		update(l, r, u, 2*x+1, xm, xr);
		a[x].v = f(a[2*x].v, a[2*x+1].v);
	}

	T get(int l, int r, int x, int xl, int xr) {
		push(x);
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x].v;
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
	T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
};

struct qry {
	int t;
	ll l, r;
};

struct elem {
	int v0, v1;
};

enum update {
	ZERO, ONE, NONE, INVERT
};

int q, k;
qry a[100005];
ll g[800005];

template<class T>
int seek(T& d, int x, int xl, int xr) {
	if (xr - xl == 1) {
		return xl;
	}

	int xm = (xl + xr) >> 1;

	d.push(x);
	d.push(2*x);

	if (d.a[2*x].v.v0) {
		return seek(d, 2*x, xl, xm);
	} else {
		return seek(d, 2*x + 1, xm, xr);
	}
}

template<class T>
int seek(T& d) {
	return seek(d, 1, 0, d.maxn);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int q;
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> a[i].t >> a[i].l >> a[i].r;
		for (ll x : {a[i].l, a[i].r}) {
			for (int d : {0, 1, 2, 3}) {
				g[k++] = x + d;
			}
		}
	}

	g[k++] = 0;
	g[k++] = 1;
	g[k++] = 2;
	g[k++] = 3;
	sort(g, g+k);
	k = unique(g, g+k) - g;

	segtreelazy drvo(k+5,
		[](elem x, elem y) -> elem {
			return {x.v0 + y.v0, x.v1 + y.v1};
		},
		[](update x, update y) -> update {
			if (y == NONE) return x;
			if (y == INVERT) {
				if (x == ONE) return ZERO;
				if (x == ZERO) return ONE;
				if (x == NONE) return INVERT;
				if (x == INVERT) return NONE;
			}
			return y;
		},
		[](elem x, update u) -> elem {
			if (u == NONE) return x;
			if (u == INVERT) return {x.v1, x.v0};
			if (u == ONE) return {0, x.v0 + x.v1};
			return {x.v0 + x.v1, 0};
		},
		elem{0, 0},
		NONE,
		elem{1, 0}
	);

	drvo.update(0, 1, INVERT);

	for (int i=0; i<q; i++) {
		auto [t, l, r] = a[i];
		l = lower_bound(g, g+k, l) - g;
		r = lower_bound(g, g+k, r+1) - g;
		if (t == 1) {
			drvo.update(l, r, ONE);
		} else if (t == 2) {
			drvo.update(l, r, ZERO);
		} else {
			drvo.update(l, r, INVERT);
		}

		cout << g[seek(drvo)] << '\n';
	}


}