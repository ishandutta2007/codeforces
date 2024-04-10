// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

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

pair<int, int> pars() {
	string s;
	cin >> s;
	int t = s.find('/');
	return {stoi(s.substr(0, t)), stoi(s.substr(t+1))};
}

int n;
ll p, q, u, v;
ll x[100005], y[100005];
int sx[100005], sy[100005];

// ahahahaha stosicu retardu

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;

	tie(p, q) = pars();
	tie(u, v) = pars();

	// cerr << p << ' ' << q << '\n';
	// cerr << u << ' ' << v << '\n';
	// cerr << q*u - p*v << '\n';
	// cerr << "~~\n";

	for (int i=0; i<n; i++) {
		ll k, l;
		cin >> k >> l;
		x[i] = k*u - l*v;
		y[i] = l*q - k*p;

		// cerr << x[i] << ' ' << y[i] << '\n';
	}

	iota(sx, sx+n, 0);
	sort(sx, sx+n, [&](int i, int j) {
		if (x[i] != x[j]) {
			return x[i] < x[j];
		}
		return y[i] > y[j];
	});

	implicit_segtree g(ll(-5e10), ll(5e10), -123123123, [](int x, int y) { return max(x, y); });

	int sol = 0;
	for (int i=0; i<n; i++) {
		int j = sx[i];
		int v = g(0, y[j]) + 1;
		if (x[j] > 0 && y[j] > 0) {
			v = max(v, 1);
		}

		g.update(y[j], v);
		sol = max(sol, v);
	}

	cout << sol << '\n';
}