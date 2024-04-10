#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 1 << 23;

struct segtree {
	vector<int> a,  b;
	
	segtree() : a(2*maxn), b(2*maxn) {}
	
	void push(int x) {
		if (!b[x])
			return;
		if (x < maxn) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		a[x] += b[x];
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
		a[x] = max(a[2*x], a[2*x+1]);
	}

	int query() {
		push(1);
		return a[1];
	}
};

int n, r;

struct event {
	int t, l, r, d;
	bool operator< (const event& b) const {
		return make_pair(t, -d) < make_pair(b.t, -b.d);
	}
};

event e[600005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> r;
	for (int i=0; i<n; i++) {
		int u, v, x, y;
		cin >> u >> v;
		x = u+v + 2000000;
		y = u-v + 2000000;
		e[2*i] = {x-r, y-r, y+r, +1};
		e[2*i+1] = {x+r, y-r, y+r, -1};
	}
	sort(e, e+2*n);
	int sol = 0;
	segtree drvo;
	for (int i=0; i<2*n; i++) {
		drvo.update(e[i].l, e[i].r, e[i].d);
		sol = max(sol, drvo.query());
	}
	cout << sol << '\n';
}