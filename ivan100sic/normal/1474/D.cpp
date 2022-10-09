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

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n), z(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (i) {
				z[i] = a[i] - z[i-1];
			} else {
				z[i] = a[i];
			}
		}

		ll inf = 1e18;
		int we = (n+1)/2;
		int wo = n - we;

		segtreelazy se(we, [](ll x, ll y) { return min(x, y); }, plus<ll>(), plus<ll>(), inf, 0ll, 0ll);
		segtreelazy so(wo, [](ll x, ll y) { return min(x, y); }, plus<ll>(), plus<ll>(), inf, 0ll, 0ll);

		for (int i=0; i<n; i++) {
			if (i % 2) {
				so.update(i/2, i/2+1, z[i]);
			} else {
				se.update(i/2, i/2+1, z[i]);
			}
		}

		z = {};

		auto ad = [&](int i, ll v) {
			a[i] += v;
			if (i % 2) {
				so.update(i/2, wo, v);
				se.update(i/2+1, we, -v);
			} else {
				se.update(i/2, we, v);
				so.update(i/2, wo, -v);
			}
		};

		auto sw = [&](int i, int j) {
			ll x = a[i], y = a[j];
			ad(i, y-x);
			ad(j, x-y);
		};

		auto ok = [&]() {
			bool r = se(0, we) >= 0 && so(0, wo) >= 0;
			if ((n-1) % 2) {
				r &= so(wo-1, wo) == 0;
			} else {
				r &= se(we-1, we) == 0;
			}
			return r;
		};

		auto dbg = [&]() {
			cerr << "info\n";
			for (int j=0; j<n; j++) {
				if (j % 2) {
					cerr << so(j/2, j/2+1) << ' ';
				} else {
					cerr << se(j/2, j/2+1) << ' ';
				}
			}
			cerr << '\n';
		};

		if (ok()) {
			cout << "YES\n";
			continue;
		}

		bool found = false;
		for (int i=0; i<n-1; i++) {
			sw(i, i+1);

			// dbg();

			if (ok()) {
				cout << "YES\n";
				found = true;
				break;
			} else {
				sw(i, i+1);
				// dbg();
			}
		}

		if (!found) {
			cout << "NO\n";
		}
	}
}