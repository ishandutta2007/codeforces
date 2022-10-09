#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 262144;

struct node {
	int l, r, v;
} b[20 * 2 * maxn]; int sz;

int init(int xl=0, int xr=maxn-1) {
	int x = ++sz;
	if (xl == xr)
		return x;
	int xm = (xl+xr) >> 1;
	b[x].l = init(xl, xm);
	b[x].r = init(xm+1, xr);
	return x;
}

int add(int p, int x, int xl=0, int xr=maxn-1) {
	int y = ++sz;
	b[y] = b[x];
	b[y].v++;
	if (xl == xr)
		return y;

	int xm = (xl+xr) >> 1;
	if (p <= xm)
		b[y].l = add(p, b[y].l, xl, xm);
	else
		b[y].r = add(p, b[y].r, xm+1, xr);
	return y;
}

int sum(int x, int l, int r, int xl=0, int xr=maxn-1) {
	if (!x || r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return b[x].v;
	int xm = (xl+xr) >> 1;
	return sum(b[x].l, l, r, xl, xm) + sum(b[x].r, l, r, xm+1, xr);
}

int roots[200005];
int n;
int a[200005], inv[200005];

int c[2*maxn];

int query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return c[x];
	int xm = (xl+xr) >> 1;
	return max(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
}

bool range_contains(int l, int r, int x) {
	return sum(roots[r], x, x) != sum(roots[l-1], x, x);
}

int sol = 0;

void solve(int l, int r) {
	if (l > r)
		return;
	int p = inv[query(l, r)];
	int v = a[p];
	if (p-l < r-p) {
		for (int i=l; i<p; i++) {
			if (range_contains(p+1, r, v - a[i]))
				sol++;
		}
	} else {
		for (int i=p+1; i<=r; i++) {
			if (range_contains(l, p-1, v - a[i]))
				sol++;
		}
	}
	solve(l, p-1);
	solve(p+1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	roots[0] = init();
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		inv[a[i]] = i;
		c[i + maxn] = a[i];
		roots[i] = add(a[i], roots[i-1]);
	}
	for (int i=maxn-1; i>0; i--)
		c[i] = max(c[2*i], c[2*i+1]);
	solve(1, n);
	cout << sol << '\n';
}