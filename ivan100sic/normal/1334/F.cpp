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

int n, a[500005], b[500005], m;
int p[500005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> p[i];
	cin >> m;
	for (int i=0; i<m; i++)
		cin >> b[i];

	const ll inf = 1e18;
	const ll big = 1e17;

	segtreelazy d(m+5, [](ll x, ll y) { return min(x, y); }, plus<ll>(), plus<ll>(),
 		inf, 0ll, big);

	d.update(0, 1, -big);

	for (int i=0; i<n; i++) {
		int u = lower_bound(b, b+m, a[i]) - b;
		if (u < m && b[u] == a[i]) {
			ll w = d(u, u+1);
			ll z = d(u+1, u+2);
			// ako ga zadrzavas: w -> z, z -> z
			// ako ga brises: z+pi -> z
			d.update(u+1, u+2, min({w, z, z+p[i]}) - z);
			d.update(0, u+1, p[i]);
			if (p[i] < 0) {
				d.update(u+2, 123123123, p[i]);
			}
		} else {
			d.update(0, u+1, p[i]);
			if (p[i] < 0) {
				d.update(u+1, 123123123, p[i]);
			}
		}
	}

	ll z = d(m, m+1);
	if (z > big/2)
		cout << "NO\n";
	else
		cout << "YES\n" << z << '\n';
}

// -46721029004120