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

struct par {
	int f, l, v;
	bool e;

	par() : e(true) {}

	par(int x) : f(x), l(x), v(1), e(false) {}

	par operator+ (const par& b) const {
		if (e) return b;
		if (b.e) return *this;
		par t;
		t.f = f;
		t.l = b.l;
		t.v = v + b.v - (l == b.f);
		t.e = false;
		return t;
	}

	int operator() () const {
		return v - 1;
	}
};

basic_string<int> e[200005];
int p[200005];
int n, m;

int ep(int x) {
	if (x == p[x]) {
		return x;
	}
	return p[x] = ep(p[x]);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=1; i<=m; i++)
		p[i] = i;

	segtree<par> a(n);

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
		a.update(i, x);
	}

	cout << a(0, n)() << '\n';

	for (int i=0; i<m-1; i++) {
		int x, y;
		cin >> x >> y;
		x = ep(x);
		y = ep(y);
		// spoji x i y
		if (e[x].size() > e[y].size()) {
			swap(x, y);
		}

		p[x] = y;

		for (int i : e[x]) {
			a.update(i, y);
			e[y] += i;
		}

		cout << a(0, n)() << '\n';
	}
}