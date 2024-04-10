// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class W, class T = int, class F = plus<T>>
struct persistent_segtree {
	struct node { T v; int l; int r; };
	typedef typename make_unsigned<W>::type Wu;
	static inline W midpoint(W l, W r) { return l + (W)((Wu(r)-l) >> 1); }
	static inline bool is_leaf(W l, W r) { return Wu(r)-l == 1; }
	node dn() { return {e, ~0, ~0}; }
	int cn(int x = 0) { a.emplace_back(a[x]); return a.size() - 1; }

	T e;
	F f;
	W rl, rr;
	vector<node> a;

	persistent_segtree(W rl, W rr, T e = T(), F f = F()) :
		e(e), f(f), rl(rl), rr(rr), a(1, dn()) {}

	template<class L>
	int _au(W p, const T& v, int x, W xl, W xr, L op) {
		x = cn(~x ? x : 0);
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

int n;
int a[100005];
int t[100005];
basic_string<int> e[100005];
persistent_segtree pst(0, 100005, 123123123, [](int x, int y) { return min(x, y); });
int last = 0;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n+1; i++) {
		e[i] += 0;
	}

	for (int i=1; i<=n; i++) {
		last = pst.update(last, i, -1);
		cin >> a[i];
		e[a[i]] += i;
	}

	// meh...
	if (*max_element(a+1, a+n+1) == 1) {
		cout << "1\n";
		return 0;
	}

	for (int i=1; i<=n+1; i++) {
		e[i] += n+1;
	}

	t[0] = last;
	for (int i=1; i<=n; i++) {
		last = pst.update(last, a[i], i);
		t[i] = last;
	}

	for (int x=1; x<=n+1; x++) {
		bool ok = 0;
		for (int j=0; j<(int)e[x].size()-1; j++) {
			int l = e[x][j];
			int r = e[x][j+1];

			if (pst(t[r-1], 1, x) > l) {
				ok = 1;
				break;
			}
		}

		if (!ok) {
			cout << x << '\n';
			return 0;
		}
	}

	cout << n+2 << '\n';
}