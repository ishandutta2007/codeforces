// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

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

struct mem {
	ll v00, v01, v10, v11;

	mem(ll x = 0) {
		v00 = 0;
		v01 = x;
		v11 = 0;
		v10 = -x;
	}

	mem operator+ (const mem& b) const {
		mem rez;
		rez.v00 = max(v00 + b.v00, v01 + b.v10);
		rez.v01 = max(v00 + b.v01, v01 + b.v11);
		rez.v10 = max(v10 + b.v00, v11 + b.v10);
		rez.v11 = max(v10 + b.v01, v11 + b.v11);
		return rez;
	}

	ll val() {
		return max(v00, v01);
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		segtree<mem> d(n);
		for (int i=0; i<n; i++) {
			d.update(i, mem{a[i]});
		}

		cout << d(0, n).val() << "\n";

		while (q--) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			swap(a[l], a[r]);
			d.update(l, mem{a[l]});
			d.update(r, mem{a[r]});
			cout << d(0, n).val() << '\n';
		}
	}
}