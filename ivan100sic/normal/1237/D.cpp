#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1000000000;

struct node {
	int l, r, v;
	node() : l(0), r(0), v(inf) {}
} b[9876543]; int bsz;

int add(int p, int v, int x, int xl=0, int xr=inf) {
	if (!x) x = ++bsz;
	if (xl == xr) {
		b[x].v = v;
	} else {
		int xm = (xl+xr) >> 1;
		if (p <= xm)
			b[x].l = add(p, v, b[x].l, xl, xm);
		else
			b[x].r = add(p, v, b[x].r, xm+1, xr);
		b[x].v = min(b[x].v, v);
	}
	return x;
}

int query(int l, int r, int x, int xl=0, int xr=inf) {
	if (r < xl || xr < l || !x)
		return inf;
	if (l <= xl && xr <= r)
		return b[x].v;
	int xm = (xl+xr) >> 1;
	return min(query(l, r, b[x].l, xl, xm), query(l, r, b[x].r, xm+1, xr));
}

int a[300005], d[300005], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	copy(a, a+n, a+n);
	copy(a, a+n, a+n+n);

	int root = 0;
	for (int i=3*n; i>=0; i--) {
		int u = query(0, (a[i]-1)/2, root);
		int v = query(a[i], inf, root);
		if (u == inf && v == inf)
			d[i] = inf;
		else if (u < v)
			d[i] = u-i;
		else
			d[i] = d[v]+v-i;
		root = add(a[i], i, root);
	}
	for (int i=0; i<n; i++)
		cout << (d[i] >= 2*n ? -1 : d[i]) << " \n"[i == n-1];
}