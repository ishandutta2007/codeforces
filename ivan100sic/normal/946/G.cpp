#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int LO = -1'000'000;
const int HI = 1'010'000'000;

struct node {
	node* l, *r;
	int v;

	node() : l(0), r(0), v(LO) {}
};

node buf[400005 * 32];
int used;

int daj(node* x, int l, int r, int xl=0, int xr=HI) {
	if (!x || r < xl || xr < l)
		return LO;
	if (l <= xl && xr <= r)
		return x->v;
	int xm = (xl+xr) / 2;
	return max(daj(x->l, l, r, xl, xm), daj(x->r, l, r, xm+1, xr));
}

node* add(node* x, int p, int v, int xl=0, int xr=HI) {
	node* y = buf+(used++);
	if (x) *y = *x;
	y->v = max(y->v, v);
	int xm = (xl+xr) / 2;
	if (xl == xr)
		return y;
	if (p <= xm)
		y->l = add(y->l, p, v, xl, xm);
	else
		y->r = add(y->r, p, v, xm+1, xr);
	return y;
}

int a[200005], n, sol;
node* d0[200005];
node* d1[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i], a[i] += n;
	for (int i=0; i<n; i++) {
		int v0 = max(1, 1 + daj(d0[i], LO, a[i] - i));
		int v1 = max(1, 1 + daj(d1[i], LO, a[i] - i));
		if (i > 0)
			v1 = max({v1, 2, 2 + daj(d0[i-1], LO, a[i] - i + 1)});
		d0[i+1] = add(d0[i], a[i] - i, v0);
		d1[i+1] = add(d1[i], a[i] - i, v1);
		sol = max({sol, v0, v1});
		if (i+1 < n)
			sol = max(sol, v0 + 1);
	}
	cout << n - sol << '\n';
}