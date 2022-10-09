#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	ll lz, mx;
	int id;

	node operator+ (const node& b) const {
		return mx > b.mx ? *this : b;
	}
};

const int maxn = 1 << 20;

node a[2*maxn];

void push(int x) {
	if (a[x].lz == 0)
		return;
	if (x < maxn) {
		a[2*x].lz += a[x].lz;
		a[2*x+1].lz += a[x].lz;
	}
	a[x].mx += a[x].lz;
	a[x].lz = 0;
}

void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}

	if (l <= xl && xr <= r) {
		a[x].lz += v;
		push(x);
		return;
	}

	push(x);
	int xm = (xl+xr) >> 1;
	update(l, r, v, 2*x, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	a[x] = a[2*x] + a[2*x+1];
}

node query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	push(x);
	if (r < xl || xr < l)
		return node();
	if (l <= xl && xr <= r)
		return a[x];
	int xm = (xl+xr) >> 1;
	return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
}

int n;
int u[1000005];
int x[500005], y[500005], c[500005];
basic_string<int> e[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int k = 0;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i] >> c[i];
		if (x[i] > y[i])
			swap(x[i], y[i]);
		u[k++] = x[i];
		u[k++] = y[i];
	}

	for (int i=0; i<maxn; i++)
		a[i+maxn].id = i;

	sort(u, u+k);
	k = unique(u, u+k) - u;
	for (int i=0; i<k; i++)
		update(i, i, u[i]);

	for (int i=0; i<n; i++) {
		int j = lower_bound(u, u+k, y[i]) - u;
		e[j] += i;
	}

	ll sol = 0;
	int l=1.1e9, r=1.1e9;

	for (int i=0; i<k; i++) {
		// ubaci sve tacke koje imaju y <= i
		for (int p : e[i]) {
			int xx = lower_bound(u, u+k, x[p]) - u;
			update(0, xx, c[p]);
		}

		auto rez = query(0, i);
		if (rez.mx - u[i] > sol) {
			sol = rez.mx - u[i];
			l = u[rez.id];
			r = u[i];
		}
	}

	cout << sol << '\n';
	cout << l << ' ' << l << ' ' << r << ' ' << r << '\n';
}