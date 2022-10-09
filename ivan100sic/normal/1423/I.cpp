// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class U, class F, class G, class H>
struct segtreelazy {
	struct node { T v; U u; };
	int maxn;
	vector<node> a;
	T e; U eu;
	F f; G g; H h;
	// Add two elements
	// Add two updaters
	// Add an element and an update
	// Neutral element
	// Neutral update
	// Bottom level element
	segtreelazy(int n, F f, G g, H h, T e = T(), U eu = U(), T v = T()) :
		e(e), eu(eu), f(f), g(g), h(h)
	{
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, node{v, eu});
		for (int i=maxn-1; i; i--)
			a[i].v = f(a[2*i].v, a[2*i+1].v);
	}

	void push(int x) {
		a[x].v = h(a[x].v, a[x].u);
		if (x < maxn) {
			a[2*x  ].u = g(a[2*x  ].u, a[x].u);
			a[2*x+1].u = g(a[2*x+1].u, a[x].u);
		}
		a[x].u = eu;
	}

	void set(int p, const T& v) {
		int x = 1, xl = 0, xr = maxn;
		while (xr-xl > 1) {
			push(x);
			int xm = (xl+xr) >> 1;
			(p < xm ? xr : xl) = xm;
			x = 2*x + (p >= xm);
		}
		a[x] = {v, eu};
		do {
			push(x^1);
			x >>= 1;
			a[x].v = f(a[2*x].v, a[2*x+1].v);
		} while (x > 1);
	}

	void update(int l, int r, const U& u, int x, int xl, int xr) {
		if (r <= xl || xr <= l)
			return push(x);
		if (l <= xl && xr <= r)
			return a[x].u = g(a[x].u, u), push(x);
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, u, 2*x  , xl, xm);
		update(l, r, u, 2*x+1, xm, xr);
		a[x].v = f(a[2*x].v, a[2*x+1].v);
	}

	T get(int l, int r, int x, int xl, int xr) {
		push(x);
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x].v;
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
	T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
};

struct req {
	ll l, r, v;
};

ll k, q;
req a[200005];
segtreelazy lsb(65536, bit_or<ll>(), bit_or<ll>(), bit_or<ll>(), 0ll, 0ll, 0ll);
segtreelazy msb(65536, bit_or<ll>(), bit_or<ll>(), bit_or<ll>(), 0ll, 0ll, 0ll);

void rc(ll l, ll r, ll u, ll v, ll w) {
	if (l >= r || u >= v) return;
	lsb.update(l, r, w);
	msb.update(u, v, w);
}

void ch(ll l, ll r, ll u, ll v, ll w) {
	if (l >= r || u >= v) return;
	ll x = lsb(l, r);
	ll y = msb(u, v);
	if ((x & y) != w) {
		cout << "impossible\n";
		exit(0);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> k >> q;

	ll modk = (1ll << k) - 1;

	auto go = [&](ll l, ll r, ll v, auto f) {
		if ((l >> k) == (r >> k)) {
			f(l & modk, (r & modk) + 1, l >> k, (l >> k) + 1, v);
		} else {
			f(l & modk, 1ll << k, l >> k, (l >> k) + 1, v);
			f(0, 1 << k, (l >> k) + 1, r >> k, v);
			f(0, (r & modk) + 1, r >> k, (r >> k) + 1, v);
		}
	};

	for (int i=0; i<q; i++) {
		ll l, r, v;
		cin >> l >> r >> v;
		a[i] = {l, r, v};
		go(l, r, v, rc);
	}

	for (int i=0; i<q; i++) {
		auto [l, r, v] = a[i];
		go(l, r, v, ch);
	}

	cout << "possible\n";
	for (int i=0; i<(1ll<<k); i++) {
		cout << lsb(i, i+1) << '\n';
	}
	for (int i=0; i<(1ll<<k); i++) {
		cout << msb(i, i+1) << '\n';
	}
}