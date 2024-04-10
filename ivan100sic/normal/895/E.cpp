#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 131072;

void ad(ld& b1, ld& c1, ld& b2, ld& c2) {
	ld bt = b1*b2;
	ld ct = b2*c1 + c2;
	b1 = bt;
	c1 = ct;
}

struct segtree {
	vector<ld> a, b, c;

	segtree() : a(2*maxn, 0.0), b(2*maxn, 1.0), c(2*maxn, 0.0) {}

	void push(int x, int xl, int xr) {
		a[x] = a[x] * b[x] + c[x] * (xr-xl+1);
		if (x < maxn) {
			ad(b[2*x], c[2*x], b[x], c[x]);
			ad(b[2*x+1], c[2*x+1], b[x], c[x]);
		}
		b[x] = 1;
		c[x] = 0;
	}

	void update(int l, int r, ld bb, ld cc, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x, xl, xr);
			return;
		}
		if (l <= xl && xr <= r) {
			ad(b[x], c[x], bb, cc);
			push(x, xl, xr);
			return;
		}
		int xm = (xl+xr) >> 1;
		push(x, xl, xr);
		update(l, r, bb, cc, 2*x, xl, xm);
		update(l, r, bb, cc, 2*x+1, xm+1, xr);
		a[x] = a[2*x] + a[2*x+1];
	}

	ld query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		push(x, xl, xr);
		if (r < xl || xr < l)
			return 0;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	}
} drvo;

int n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		drvo.a[i + maxn] = x;
	}

	for (int i=maxn-1; i; i--) {
		drvo.a[i] = drvo.a[2*i] + drvo.a[2*i+1];
	}

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			double sab = drvo.query(a, b);
			double scd = drvo.query(c, d);
			ld n = b-a+1;
			ld m = d-c+1;
			drvo.update(a, b, (n-1)/n, scd/m/n);
			drvo.update(c, d, (m-1)/m, sab/n/m);
		} else {
			int a, b;
			cin >> a >> b;
			cout << drvo.query(a, b) << '\n';
		}
	}
}