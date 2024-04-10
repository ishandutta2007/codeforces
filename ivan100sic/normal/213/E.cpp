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

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod1 = 1459859861;
const int mod2 = 1359859861;
const int base = 123465414;
typedef modint<mod1> mint1;
typedef modint<mod2> mint2;

int n, m;

int a[200005], b[200005], binv[200005];

struct hsh {
	mint1 ap, aq;
	mint2 bp, bq;

	hsh operator+ (const hsh& o) const {
		return {
			ap * o.ap, aq + ap * o.aq,
			bp * o.bp, bq + bp * o.bq,
		};
	}
};

const hsh h0 {1, 0, 1, 0};

segtree hst(200005, h0, plus<hsh>(), h0);

void ad(int i) {
	hst.update(binv[i], hsh{base, i, base, i});
}

void rm(int i) {
	hst.update(binv[i], h0);
}

int sol;

hsh diff, arr;

void chk(int k) {
	auto g = hst(0, 200005);
	if (g.aq - diff.aq*k == arr.aq && g.bq - diff.bq*k == arr.bq) {
		sol++;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	diff = arr = h0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		arr = arr + hsh{base, a[i], base, a[i]};
		diff = diff + hsh{base, 1, base, 1};
	}

	for (int i=1; i<=m; i++) {
		cin >> b[i];
		binv[b[i]] = i;
	}

	for (int i=1; i<=n; i++) {
		ad(i);
	}

	for (int i=n; i<=m; i++) {
		chk(i-n);
		if (i < m) {
			rm(i-n+1);
			ad(i+1);
		}
	}

	cout << sol << '\n';
}