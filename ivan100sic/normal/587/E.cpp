#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct gaus {
	int a[31];

	gaus() {
		memset(a, 0, sizeof(a));
	}

	void add(int x) {
		for (int i=0; i<31; i++) {
			if (x & (1 << i)) {
				if (a[i] == 0) {
					a[i] = x;
					return;
				} else {
					x ^= a[i];
				}
			}
		}
	}

	gaus change(int x) const {
		gaus b;
		for (int i=0; i<31; i++) {
			if (a[i]) {
				if (a[i] & (1 << 30))
					b.add(a[i] ^ x);
				else
					b.add(a[i]);
			}
		}
		return b;
	}

	gaus operator+ (const gaus& b) const {
		gaus c = *this;
		for (int i=0; i<31; i++)
			c.add(b.a[i]);
		return c;
	}

	int dim() {
		gaus t;
		int c = 0;
		for (int i=0; i<31; i++)
			t.add(a[i] & ((1 << 30) - 1));
		for (int i=0; i<30; i++)
			c += !!t.a[i];
		return c;
	}

	void dump() {
		cerr << "dump\n";
		for (int i=0; i<31; i++) {
			if (a[i] != 0) {
				cerr << "digit " << i << " val " << a[i] << '\n';
			}
		}
		cerr << "end dump\n";
	}
};

const int maxn = 262144;

struct segtree {
	gaus a[2*maxn];
	int b[2*maxn];

	void push(int x) {
		if (!b[x])
			return;
		a[x] = a[x].change(b[x]);
		if (x < maxn) {
			b[2*x] ^= b[x];
			b[2*x+1] ^= b[x];
		}
		b[x] = 0;
	}

	void init(vector<int> c) {
		for (int i=0; i<(int)c.size(); i++)
			a[i+maxn+1].add(c[i] ^ (1 << 30));
		for (int i=maxn-1; i; i--)
			a[i] = a[2*i] + a[2*i+1];
	}

	void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] ^= v;
			push(x);
			return;
		}
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = a[2*x] + a[2*x+1];
	}

	gaus query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		push(x);
		if (r < xl || xr < l)
			return gaus();
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	}
} drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	drvo.init(a);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			drvo.update(l, r, k);
		} else {
			int l, r;
			cin >> l >> r;
			auto g = drvo.query(l, r);
			cout << (1 << g.dim()) << '\n';
		}
	}
}