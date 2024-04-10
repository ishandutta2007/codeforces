#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct vr {
	int mx, mn, pl, pr, mxid;
	bool neutral;

	vr() {
		neutral = true;
	}

	int getpl() {
		return neutral ? -123123123 : pl;
	}

	int getpr() {
		return neutral ? -123123123 : pr;
	}
};

vr add(vr a, vr b) {
	if (a.neutral) return b;
	if (b.neutral) return a;
	vr c;
	if (a.mx > b.mx) {
		c.mx = a.mx;
		c.mxid = a.mxid;
	} else {
		c.mx = b.mx;
		c.mxid = b.mxid;
	}
	c.mn = min(a.mn, b.mn);
	c.pl = max({a.pl, b.pl, a.mx - 2*b.mn});
	c.pr = max({a.pr, b.pr, b.mx - 2*a.mn});
	c.neutral = false;
	return c;
}

const int maxn = 262144;
vr a[2*maxn];
int b[2*maxn];

void push(int x) {
	if (!b[x]) return;

	if (x < maxn) {
		b[2*x] += b[x];
		b[2*x+1] += b[x];
	}

	a[x].mx += b[x];
	a[x].mn += b[x];
	a[x].pl -= b[x];
	a[x].pr -= b[x];
	
	b[x] = 0;
}

void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x] += v;
		push(x);
		return;
	}
	push(x);
	int xm = (xl+xr) >> 1;
	update(l, r, v, 2*x, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	a[x] = add(a[2*x], a[2*x+1]);
}

vr query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	push(x);
	if (r < xl || xr < l) {
		return vr();
	}
	if (l <= xl && xr <= r) {
		return a[x];
	}
	int xm = (xl+xr) >> 1;
	return add(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
}

int n;

void solve() {
	int x = a[1].mxid;
	int dl = query(0, x-1).getpl();
	int dr = query(x+1, n-1).getpr();
	// cerr << "info " << x << ' ' << a[1].mx << ' ' << dl << ' ' << dr << '\n';
	cout <<  a[1].mx + max(dl, dr) << '\n';

	// for (int i=0; i<=n; i++)
	// 	cerr << query(i, i).mx;
	// cerr << '\n';
	// cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	string s;
	cin >> n >> q >> s;
	s = string(".") + s;
	n = 2*n-2;
	for (int i=0; i<maxn; i++) {
		a[i+maxn].mxid = i;
		a[i+maxn].neutral = false;
	}
	for (int i=maxn-1; i>0; i--) {
		a[i] = add(a[2*i], a[2*i+1]);
	}
	for (int i=1; i<=n; i++) {
		update(i, n, s[i] == '(' ? 1 : -1);
	}
	solve();
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		update(l, r-1, s[l] == '(' ? -2 : 2);
		swap(s[l], s[r]);
		// cerr << s << '\n';
		solve();
	}
}