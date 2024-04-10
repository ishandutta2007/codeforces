// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct sieve {
	const int maxn;
	vector<int> f, primes;

	sieve(int maxn) : maxn(maxn), f(maxn) {
		for (int i=2; i<maxn; i++) {
			if (f[i] == 0) {
				f[i] = i;
				primes.push_back(i);
			}

			for (int p : primes) {
				if (p > f[i] || i * p >= maxn) {
					break;
				}

				f[i*p] = p;
			}
		}
	}

 	auto factor_small(int x) const {
		vector<pair<int, int>> v;
		while (x > 1) {
			int p = f[x], c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.emplace_back(p, c);
		}
		return v;
	}

	template<class T>
	auto factor(T x) const {
		vector<pair<T, int>> v;
		for (int p : primes) {
			if ((ll)p*p > x) {
				break;
			}

			if (x % p == 0) {
				int c = 0;
				while (x % p == 0) {
					x /= p;
					c++;
				}
				v.emplace_back(p, c);
			}
		}

		if (x > 1) {
			v.emplace_back(x, 1);
		}

		return v;
	}
};

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

const int mod = 1'000'000'007;
typedef modint<mod> mint;

struct entry {
	int f, q, e;
};

int a[100005], n;
vector<entry> w[200005];
persistent_segtree pst(-1, 100005, mint(1), multiplies<mint>());
int ps_last = 0;
int ps_handle[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	pst.a.reserve(41666666);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	sieve sv(200005);

	for (int i=1; i<=n; i++) {
		auto f = sv.factor_small(a[i]);
		for (auto [p, e] : f) {
			while (w[p].size() && w[p].back().e <= e) {
				auto [ff, qq, ee] = w[p].back();
				w[p].pop_back();
				ps_last = pst.add(ps_last, ff, mint(p) ^ (mod - 1 - ee));
				if (qq != -1) ps_last = pst.add(ps_last, qq, mint(p) ^ ee);
			}

			int q = -1;
			if (w[p].size()) {
				q = w[p].back().f;
				ps_last = pst.add(ps_last, w[p].back().f, mint(p) ^ (mod - 1 - e));
			}

			ps_last = pst.add(ps_last, i, mint(p) ^ e);
			w[p].push_back({i, q, e});
		}

		ps_handle[i] = ps_last;

		// for (int j=1; j<=i; j++) {
		// 	cerr << pst(ps_last, j, 123123123)() << " \n"[j == i];
		// }
	}

	int q, ans = 0;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x = (x + ans) % n + 1;
		y = (y + ans) % n + 1;
		if (x > y) swap(x, y);

		ans = pst(ps_handle[y], x, 123123123)();
		cout << ans << '\n';
	}



}