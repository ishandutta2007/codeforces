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

struct elem {
	int x, l;
};

segtreelazy lz(
	200005,
	[](elem a, elem b) {
		return elem{a.x ^ b.x, a.l ^ b.l};
	},
	bit_xor<int>(),
	[](elem a, int b) {
		if (a.l) {
			a.x ^= b;
		}
		return a;
	},
	elem{0, 0},
	0,
	elem{0, 0}
);

int n, m, q;
vector<pair<int, int>> e[262144];
string ans;

void rek(int mask, int b) {
	for (auto [r, id] : e[mask]) {
		// cerr << "solving " << mask << ' ' << r << ' ' << lz(mask, r+1).x << '\n';
		// cerr << "all tree:\n";
		// for (int i=mask; i<=m; i++) {
		// 	cerr << lz(i, i+1).x << " ";
		// }
		// cerr << '\n';
		ans[id] = lz(mask, r+1).x ? 'A' : 'B';
	}
	for (int i=b; i<=17; i++) {
		auto go = [&]() {
			for (int j=mask+(1<<i); j<=m; j+=(1<<i)) {
				lz.update(j, j+(1<<i), (j-mask)^(j-mask-(1<<i)));
			}
		};

		go();
		rek(mask+(1<<i), i+1);
		go();
	}
}

int c[200005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		c[x] ^= 1;
  }

	for (int i=1; i<=m; i++) {
		if (c[i]) {
			lz.set(i, elem{i, 1});
		}
	}

  cin >> q;
  ans = string(q, 0);
  for (int i=0; i<q; i++) {
    int l, r;
    cin >> l >> r;
    e[l].emplace_back(r, i);
  }

	// cerr << "all tree:\n";
	// for (int i=0; i<=m; i++) {
	// 	cerr << lz(i, i+1).x << " ";
	// }
	// cerr << '\n';

	rek(0, 0);
	cout << ans << '\n';

	// for (int l=1; l<=m; l++) {
	// 	for (auto [r, id] : e[l]) {
	// 		int x = 0;
	// 		for (int j=l; j<=r; j++) {
	// 			if (c[j]) {
	// 				x ^= j-l;
	// 			}
	// 		}
	// 		char ex = x ? 'A' : 'B';
	// 		if (ex != ans[id]) {
	// 			cerr << "wrong answer: " << l << ' ' << r << '\n';
	// 		}
	// 	}
	// }
}