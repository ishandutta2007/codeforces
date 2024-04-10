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

int n, q;
int l[400005], r[400005], c[400005], dt;
basic_string<int> e[400005];

void dfs(int x, int p) {
	l[x] = dt++;
	for (int y : e[x])
		if (y != p)
			dfs(y, x);
	r[x] = dt;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> q;
	vector<int> c0(n+1);
	for (int i=1; i<=n; i++)
		cin >> c0[i];

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	segtreelazy drvo(
		n+5,
		[](ull x, ull y) { return x | y; },
		[](int x, int y) { return y ? y : x; },
		[](ull x, int y) { return y ? 1ull << y : x; },
		0ull,
		0,
		0ull
	);

	dfs(1, 1);
	for (int i=1; i<=n; i++) {
		drvo.update(l[i], l[i] + 1, c0[i]);
	}

	while (q--) {
		int t, x, c;
		cin >> t;
		if (t == 1) {
			cin >> x >> c;
			drvo.update(l[x], r[x], c);
		} else {
			cin >> x;
			cout << __builtin_popcountll(drvo(l[x], r[x])) << '\n';
		}
	}
}