// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct blok {
	bool neut;
	ll cena, a0, b0, a1, b1;

	template<class T>
	auto operator+ (const T& b) const {
		if (neut) return b;
		if (b.neut) return *this;
		blok t;
		t.neut = false;
		t.a0 = a0, t.b0 = b0;
		t.a1 = b.a1, t.b1 = b.b1;
		t.cena = cena + b.cena - min(b1, b.a0);
		return t;
	}
};

template<class T = int, class F = plus<T>>
struct segtree {
	int maxn;
	vector<T> a;
	T e;
	F f;

	segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, v);
		for (int i=maxn-1; i; i--)
			a[i] = f(a[2*i], a[2*i+1]);
	}

	void add(int p, const T& v) {
		p += maxn;
		a[p] = f(a[p], v);
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	void update(int p, const T& v) {
		p += maxn;
		a[p] = v;
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	T get(int l, int r, int x, int xl, int xr) const {
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	T operator() (int l, int r) const {
		return get(l, r, 1, 0, maxn);
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		segtree<blok> c(2*n);
		for (int i=0; i<n; i++) {
			ll a, b;
			cin >> a >> b;
			blok t {false, a, a, b, a, b};
			c.update(i, t);
			c.update(i+n, t);
		}

		ll sol = 8e18;
		for (int i=0; i<n; i++) {
			sol = min(sol, c(i, i+n).cena);
		}

		cout << sol << '\n';
	}
}