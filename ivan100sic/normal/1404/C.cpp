// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int inf = 1012012012;

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

	void set(int p, const T& v) {
		int x = 1, xl = 0, xr = maxn;
		while (xr-xl > 1) {
			push(x);
			int xm = (xl+xr) >> 1;
			(p < xm ? xr : xl) = xm;
			x = 2*x + (p >= xm);
		}
		a[x] = {v, eu};
		do {
			push(x^1);
			x >>= 1;
			a[x].v = f(a[2*x].v, a[2*x+1].v);
		} while (x > 1);
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

template<class W, class T = int, class F = plus<T>>
struct persistent_segtree {
	struct node { T v; int l; int r; };
	typedef typename make_unsigned<W>::type Wu;
	static inline W midpoint(W l, W r) { return l + (W)((Wu(r)-l) >> 1); }
	static inline bool is_leaf(W l, W r) { return Wu(r)-l == 1; }
	node dn() { return {e, ~0, ~0}; }
	int nn() { a.emplace_back(dn()); return a.size() - 1; }
	int cn(int x) { a.emplace_back(a[x]); return a.size() - 1; }

	T e;
	F f;
	W rl, rr;
	vector<node> a;

	persistent_segtree(W rl, W rr, T e = T(), F f = F()) :
		e(e), f(f), rl(rl), rr(rr), a(1, dn()) {}

	template<class L>
	int _au(W p, const T& v, int x, W xl, W xr, L op) {
		x = ~x ? cn(x) : nn();
		if (is_leaf(xl, xr)) {
			op(a[x].v, v);
			return x;
		} else {
			W xm = midpoint(xl, xr);
			if (p < xm) {
				a[x].l = _au(p, v, a[x].l, xl, xm, op);
			} else {
				a[x].r = _au(p, v, a[x].r, xm, xr, op);
			}
			a[x].v = f(~a[x].l ? a[a[x].l].v : e, ~a[x].r ? a[a[x].r].v : e);
			return x;
		}
	}

	int add(int x, W p, const T& v) {
		return _au(p, v, x, rl, rr, [&](T& x, const T& y) { x = f(x, y); });
	}

	int update(int x, W p, const T& v) {
		return _au(p, v, x, rl, rr, [&](T& x, const T& y) { x = y; });
	}

	T get(W l, W r, int x, W xl, W xr) {
		if (!~x || r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x].v;
		W xm = midpoint(xl, xr);
		return f(get(l, r, a[x].l, xl, xm), get(l, r, a[x].r, xm, xr));
	}

	T operator() (int x, W l, W r) { return get(l, r, x, rl, rr); }
};

int n, q;
int a[300005];
int ver[300005], low;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> q;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] -= i + 1;
	}

	segtreelazy d(n,
		[](auto x, auto y) { return max(x, y); },
		plus<int>(),
		[](pair<int, int> x, int y) { return pair(x.first + y, x.second); },
		pair(-inf, -1),
		0,
		pair(-inf, -1)
	);

	persistent_segtree ps(0, n, 0);
	int latest = 0, low = n;

	for (int i=0; i<n; i++) {
		if (a[i] <= 0) {
			d.set(i, pair(a[i], i));
		}
	}

	while (1) {
		auto [v, idx] = d(0, n);
		d.set(idx, pair(-inf, -1));
		d.update(idx, n, 1);
		if (v >= 0) {
			latest = ps.add(latest, idx, 1);
			low = min(low, idx);
			ver[low] = latest;
		} else {
			break;
		}
	}

	for (int i=n-1; i>=0; i--) {
		if (!ver[i]) {
			ver[i] = ver[i+1];
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << ps(ver[l], 0, n-r) << '\n';
	}
}