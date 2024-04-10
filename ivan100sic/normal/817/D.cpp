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

int n;
int a[1000005];

struct seg {
	ll sum;
	int len;

	seg() : sum(0), len(0) {}
	seg(int) : sum(0), len(1) {}
	seg(ll s, int l) : sum(s), len(l) {}

	seg operator+ (const seg& b) const {
		return {sum + b.sum, len + b.len};
	}
};

struct niz {
	int l, r, v;
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	segtreelazy drvo(
		n+1,
		plus<seg>(),
		plus<ll>(),
		[](seg s, ll q) {
			return seg{ s.sum + s.len * q, s.len};
		},
		seg(),
		0ll,
		seg(1)
	);

	vector<niz> mx, mn;

	ll sol = 0;

	for (int i=0; i<n; i++) {
		int v = a[i];

		int vl = i, vr = i+1;
		while (mx.size() && v > mx.back().v) {
			auto [l, r, v] = mx.back();
			drvo.update(l, r, -v);
			vl = l;
			mx.pop_back();
		}

		drvo.update(vl, vr, v);
		mx.push_back({vl, vr, v});

		vl = i, vr = i+1;
		while (mn.size() && v < mn.back().v) {
			auto [l, r, v] = mn.back();
			drvo.update(l, r, v);
			vl = l;
			mn.pop_back();
		}

		drvo.update(vl, vr, -v);
		mn.push_back({vl, vr, v});

		sol += drvo(0, i+1).sum;
	}

	cout << sol << "\n";
}