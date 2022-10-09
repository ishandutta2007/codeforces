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

template<class T = int, class F = plus<T>>
struct fenwick {
	vector<T> a;
	T e;
	F f;

	fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

	void add(int p, const T& v) {
		for (p++; p <= (int)a.size(); p += p & -p)
			a[p-1] = f(a[p-1], v);
	}

	T operator() (int p) const {
		T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

ll n, k, m;
set<pair<ll, ll>> s;

const int maxn = 524288;
const ll inf = 3e8;
const ll llinf = 1e18;

segtreelazy drvo(
	maxn,
	[](ll x, ll y) { return max(x, y); },
	plus<ll>(),
	plus<ll>(),
	-llinf,
	0ll,
	-inf);

fenwick<ll> f(maxn);

void dodaj(ll z) {
	f.add(z, 1);
	drvo.update(0, z, 1);
	if (f(z+1) - f(z) == 1) {
		ll old = drvo(z, z+1);
		ll nu = z + f(maxn) - f(z+1);
		drvo.update(z, z+1, nu-old);
	} else {
		drvo.update(z, z+1, 1);
	}
}

ll vr() {
	if (f(maxn) == 0) {
		return 0;
	} else {
		return drvo(0, maxn);
	}
}

void brisi(ll z) {
	f.add(z, -1);
	drvo.update(0, z, -1);
	if (f(z+1) - f(z) == 0) {
		ll old = drvo(z, z+1);
		ll nu = -inf;
		drvo.update(z, z+1, nu-old);
	} else {
		drvo.update(z, z+1, -1);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k >> m;
	while (m--) {
		ll x, y;
		cin >> x >> y;
		ll z = y + abs(k-x);
		if (s.count({x, y})) {
			s.erase({x, y});
			brisi(z);
		} else {
			s.insert({x, y});
			dodaj(z);
		}
		cout << max(0ll, vr()-n) << '\n';
	}
}