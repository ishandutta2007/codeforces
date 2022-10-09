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

	void update_hold(int p, const T& v) {
		p += maxn;
		a[p] = v;
	}

	void propagate() {
		for (int i=maxn-1; i; i--)
			a[i] = f(a[2*i], a[2*i+1]);
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

const int mod = 1992450947;
typedef modint<mod> mint;
const mint base = 5394581;

mint p[100005];

typedef int node_handle;

struct node {
	node_handle l, r;
	int s;
	mint h;
};

const int buff_max_size = 100005 * 155;
node b[buff_max_size];
int buff_head;

node_handle new_node() {
	int x = ++buff_head;
	b[x].l = b[x].r = b[x].s = 0;
	b[x].h = 0;
	return x;
}

mint hash_combine(mint hl, int sl, mint hr, int sr) {
	return hl * p[sr] + hr;
}

mint hash_combine(bool fwd, mint hl, int sl, mint hr, int sr) {
	return fwd ? hash_combine(hl, sl, hr, sr) : hash_combine(hr, sr, hl, sl);
}

pair<mint, int> get_hash(bool fwd, node_handle x, int l, int r) {
	if (r <= 0 || l >= b[x].s)
		return {0, 0};
	if (l <= 0 && b[x].s <= r)
		return {b[x].h, b[x].s};

	int d = b[b[x].l].s;
	auto [hl, sl] = get_hash(fwd, b[x].l, l, r);
	auto [hr, sr] = get_hash(fwd, b[x].r, l-d, r-d);

	return {hash_combine(fwd, hl, sl, hr, sr), sl + sr};
}

node_handle join_nodes(bool fwd, node_handle xl, node_handle xr) {
	if (!xl) return xr;
	if (!xr) return xl;

	node_handle x = new_node();
	b[x].l = xl;
	b[x].r = xr;
	b[x].s = b[xl].s + b[xr].s;
	b[x].h = hash_combine(fwd, b[xl].h, b[xl].s, b[xr].h, b[xr].s);
	return x;
}

node_handle splice(bool fwd, node_handle x, int l, int r) {
	if (r <= 0 || l >= b[x].s)
		return 0;
	if (l <= 0 && b[x].s <= r)
		return x;

	int d = b[b[x].l].s;
	node_handle xl = splice(fwd, b[x].l, l, r);
	node_handle xr = splice(fwd, b[x].r, l-d, r-d);

	return join_nodes(fwd, xl, xr);
}

struct monoid {
	node_handle l, r;

	monoid() : l(0), r(0) {}
	monoid(bool) : l(-1), r(-1) {}

	monoid(int x) {
		if (x < 0) {
			l = -x;
			r = 0;
		} else {
			l = 0;
			r = x;
		}
	}

	monoid(node_handle l, node_handle r) : l(l), r(r) {}

	monoid operator+ (const monoid& o) const {
		if (l == -1 || o.l == -1) return false;
		if (l == 0 && r == 0) return o;
		if (o.l == 0 && o.r == 0) return *this;

		int len = min(b[r].s, b[o.l].s);

		auto h1 = get_hash(false, r, b[r].s - len, b[r].s);
		auto h2 = get_hash(true, o.l, 0, len);

		if (h1 != h2)
			return false;

		node_handle xl = join_nodes(true, l, splice(true, o.l, len, b[o.l].s));
		node_handle xr = join_nodes(false, splice(false, r, 0, b[r].s-len), o.r);

		return monoid(xl, xr);
	}

	bool empty() {
		return l == 0 && r == 0;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution uid(2, mod-2);

	// init
	p[0] = 1;
	for (int i=1; i<100005; i++)
		p[i] = p[i-1] * base;

	// read
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=k; i++) {
		b[i].h = uid(eng);
		b[i].s = 1;
	}
	buff_head = k;

	segtree d(n, monoid());

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		d.update_hold(i, monoid(x));
	}
	d.propagate();

	// process
	int q;
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		x--;
		if (t == 2) {
			int guard = buff_head;
			monoid info = d(x, y);
			cout << (info.empty() ? "Yes\n" : "No\n");
			buff_head = guard;
		} else {
			d.update(x, monoid(y));
		}
	}
}