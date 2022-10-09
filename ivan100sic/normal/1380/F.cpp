// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

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

const int mod = 998'244'353;
typedef modint<mod> mint;

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

mint br(int x, int y) {
	x = 10*x + y;
	if (x <= 9) {
		return 0;
	} else if (x <= 18) {
		return 19-x;
	} else {
		return 0;
	}
}

struct elem {
	mint ceo, levi, desni, rupica;
	int prvi, zadnji;
	bool prazno;

	elem() : prazno(true) {}

	elem(int x) : ceo(x+1), levi(1), desni(1), rupica(0),
		prvi(x), zadnji(x), prazno(false) {}

	elem operator+ (const elem& b) const {
		if (prazno) return b;
		if (b.prazno) return *this;

		elem rez;
		rez.prvi = prvi;
		rez.zadnji = b.zadnji;
		rez.prazno = false;

		mint kros = br(zadnji, b.prvi);

		rez.ceo = ceo * b.ceo + kros * levi * b.desni;
		rez.levi = ceo * b.levi + kros * levi * b.rupica;
		rez.desni = desni * b.ceo + kros * rupica * b.desni;
		rez.rupica = desni * b.levi + kros * rupica * b.rupica;

		return rez;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	segtree<elem> d(n);
	for (int i=0; i<n; i++) {
		d.update(i, s[i] - '0');
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		d.update(x-1, y);
		cout << d(0, n).ceo() << '\n';
	}

}