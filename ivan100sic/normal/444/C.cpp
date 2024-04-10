#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;

struct node {
	int u, v, w, z, s;
	ll g, q;

	node operator+ (const node& b) const {
		return {min(u, b.u), max(v, b.v), w+b.w, 0, 0, g+b.g, 0};
	}
};

const int maxn = 131072;

struct drvo {
	vector<node> a;

	drvo(int n) : a(2*maxn) {
		for (int i=0; i<maxn; i++) {
			auto& b = a[i+maxn];
			b.u = b.v = b.z = b.s = b.g = b.q = 0;
			b.w = 1;
		}

		for (int i=1; i<=n; i++) {
			auto& b = a[i+maxn];
			b.u = b.v = i;
		}
		
		for (int i=maxn-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	void pushq(int x) {
		a[x].g += a[x].q * a[x].w;
		if (x < maxn) {
			a[2*x].q += a[x].q;
			a[2*x+1].q += a[x].q;
		}
		a[x].q = 0;
	}

	void push(int x) {
		if (a[x].z) {
			if (a[x].u == a[x].v) {
				a[x].q += abs(a[x].u - a[x].z);
				if (x < maxn) {
					a[2*x].z = 0;
					a[2*x].s = a[x].z;

					a[2*x+1].z = 0;
					a[2*x+1].s = a[x].z;
				}
				a[x].u = a[x].v = a[x].z;
				pushq(x);
				a[x].z = a[x].s = 0;
			} else {
				pushq(x);
				a[2*x].z = a[2*x+1].z = a[x].z;
				push(2*x);
				push(2*x+1);
				a[x] = a[2*x] + a[2*x+1];
			}
		} else if (a[x].s) {
			pushq(x);
			a[x].u = a[x].v = a[x].s;
			if (x < maxn) {
				a[2*x].z = 0;
				a[2*x].s = a[x].s;

				a[2*x+1].z = 0;
				a[2*x+1].s = a[x].s;
			}
			a[x].s = 0;
		} else {
			pushq(x);
		}
	}

	void update(int l, int r, int c, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}

		if (l <= xl && xr <= r) {
			push(x);
			a[x].z = c;
			push(x);
			return;
		}

		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, c, 2*x, xl, xm);
		update(l, r, c, 2*x+1, xm+1, xr);
		a[x] = a[2*x] + a[2*x+1];
	}

	ll query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		push(x);
		if (r < xl || xr < l)
			return 0;
		if (l <= xl && xr <= r)
			return a[x].g;

		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	drvo d(n);
	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			d.update(l, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << d.query(l, r) << '\n';
		}
	}
}