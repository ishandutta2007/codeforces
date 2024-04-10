// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T>
struct compressor {
	vector<T*> v;
	void operator+=(T& x) { v.push_back(&x); }

	T operator() (T init = T()) {
		sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
		T last = 0, q = 0;
		for (size_t i=0; i<v.size(); i++) {
			if (!i || *v[i] != last) q++;
			last = *v[i];
			*v[i] = q - 1 + init;
		}
		return q;
	}
};

struct seg {
	int l, r, t;

	template<class T>
	auto operator< (const T& b) const {
		return l < b.l;
	}
};

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

struct updater {
	bool issetter;
	int val;

	updater operator+ (const updater& b) const {
		if (!b.issetter) {
			return {issetter, val + b.val};
		} else {
			return b;
		}
	}
};

int n;
seg a[200005];
const int inf = 100;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;

	int w = 2*n+5;
	compressor<int> c;

	for (int i=0; i<n; i++) {
		cin >> a[i].l >> a[i].r >> a[i].t;
		c += a[i].l;
		c += a[i].r;
	}

	c(1);

	sort(a, a+n);

	segtreelazy d1(
		w,
		[](int x, int y) { return max(x, y); },
		plus<updater>(),
		[](int x, updater u) { return u.issetter ? u.val : x + u.val; },
		-inf,
		updater{false, 0},
		-inf
	);

	d1.update(0, 1, updater{true, 0});

	auto d2 = d1;

	for (int i=0; i<n; i++) {
		auto [l, r, t] = a[i];
		if (t == 1) {
			// int v1 = d1(0, w);
			int v1p = d1(0, r+1);
			int v2 = d2(0, l);
			d1.update(r+1, w, updater{false, 1});
			d1.update(r, r+1, updater{true, max(v1p, v2) + 1});
		} else {
			// int v2 = d2(0, w);
			int v2p = d2(0, r+1);
			int v1 = d1(0, l);
			d2.update(r+1, w, updater{false, 1});
			d2.update(r, r+1, updater{true, max(v2p, v1) + 1});
		}

		// for (int i=0; i<w; i++) cerr << d1(i, i+1) << " \n"[i == w-1];
		// for (int i=0; i<w; i++) cerr << d2(i, i+1) << " \n"[i == w-1];
		// cerr << '\n';
	}

	cout << max(d1(0, w), d2(0, w)) << '\n';

}