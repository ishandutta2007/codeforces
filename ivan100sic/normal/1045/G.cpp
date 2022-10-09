#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class W, class T = int, class F = plus<T>>
struct implicit_segtree {
	struct node { T v; int l; int r; };
	typedef typename make_unsigned<W>::type Wu;
	static inline W midpoint(W l, W r) { return l + (W)((Wu(r)-l) >> 1); }
	static inline bool is_leaf(W l, W r) { return Wu(r)-l == 1; }
	node dn() { return {e, ~0, ~0}; }
	int nn() { a.emplace_back(dn()); return a.size() - 1; }

	T e;
	F f;
	W rl, rr;
	vector<node> a;

	implicit_segtree(W rl, W rr, T e = T(), F f = F()) :
		e(e), f(f), rl(rl), rr(rr), a(1, dn()) {}

	template<class L>
	int _au(W p, const T& v, int x, W xl, W xr, L op) {
		if (!~x) x = nn();
		if (is_leaf(xl, xr)) {
			op(a[x].v, v);
		} else {
			W xm = midpoint(xl, xr);
			if (p < xm) {
				a[x].l = _au(p, v, a[x].l, xl, xm, op);
			} else {
				a[x].r = _au(p, v, a[x].r, xm, xr, op);
			}
			a[x].v = f(~a[x].l ? a[a[x].l].v : e, ~a[x].r ? a[a[x].r].v : e);
		}
		return x;
	}

	void add(W p, const T& v) {
		_au(p, v, 0, rl, rr, [&](T& x, const T& y) { x = f(x, y); });
	}

	void update(W p, const T& v) {
		_au(p, v, 0, rl, rr, [&](T& x, const T& y) { x = y; });
	}

	T get(W l, W r, int x, W xl, W xr) {
		if (!~x || r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x].v;
		W xm = midpoint(xl, xr);
		return f(get(l, r, a[x].l, xl, xm), get(l, r, a[x].r, xm, xr));
	}

	T operator() (W l, W r) { return get(l, r, 0, rl, rr); }
};

struct robot {
	int x, r, q;
	bool operator< (const robot& b) const {
		return r > b.r;
	}
};

int n, k;
robot a[100005];

struct node {
	node* l, *r;
	int v;

	node() : l(0), r(0), v(0) {}
};

struct drvo : public implicit_segtree<int> {
	drvo() : implicit_segtree<int>(-2.01e9, 2.01e9) {}
};

map<int, drvo> e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].r >> a[i].q;
	sort(a, a+n);
	ll sol = 0;
	for (int i=0; i<n; i++) {
		for (int j=a[i].q-k; j<=a[i].q+k; j++) {
			auto it = e.find(j);
			if (it != e.end())
				sol += it->second(a[i].x - a[i].r, a[i].x + a[i].r + 1);
		}
		e[a[i].q].add(a[i].x, 1);
	}
	cout << sol << '\n';
}