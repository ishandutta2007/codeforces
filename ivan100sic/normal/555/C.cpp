#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int l, r, x, u;
} a[200000 * 80]; int sz;

void update(int l, int r, int v, int& x, int xl, int xr) {
	if (r < xl || xr < l)
		return;

	if (!x) x = ++sz;

	if (l <= xl && xr <= r) {
		a[x].u = max(a[x].u, v);
		return;
	}

	int xm = (xl + xr) >> 1;
	update(l, r, v, a[x].l, xl, xm);
	update(l, r, v, a[x].r, xm+1, xr);
	a[x].x = max({a[a[x].l].x, a[a[x].r].x, a[x].u});
}

int query(int l, int r, int x, int xl, int xr) {
	if (!x || r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return max(a[x].x, a[x].u);
	int xm = (xl + xr) >> 1;
	return max({
		a[x].u,
		query(l, r, a[x].l, xl, xm),
		query(l, r, a[x].r, xm+1, xr)
	});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	cin >> n >> q;
	set<int> h, v;
	h.insert(0);
	v.insert(0);

	int v_root = 0, h_root = 0;

	while (q--) {
		int x, y;
		char d;
		cin >> x >> y >> d;
		if (d == 'U') {
			int z = query(x, x, h_root, 1, n);
			cout << y-z << '\n';
			update(x, x, y, h_root, 1, n);
			update(z, y, x, v_root, 1, n);
		} else {
			int z = query(y, y, v_root, 1, n);
			cout << x-z << '\n';
			update(y, y, x, v_root, 1, n);
			update(z, x, y, h_root, 1, n);
		}
	}
}