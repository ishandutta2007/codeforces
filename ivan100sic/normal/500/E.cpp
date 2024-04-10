#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1'000'000'000;

struct node {
	int l, r, v, lzy;
} b[200000 * 63]; int sz;

void push_value(int x, int xl, int xr) {
	if (!b[x].lzy) return;
	if (b[x].lzy == 1)
		b[x].v = xr-xl;
	else
		b[x].v = 0;
}

void push_down(int x, int xl, int xr) {
	if (!b[x].lzy) return;
	if (xl != xr) {
		if (!b[x].l) b[x].l = ++sz;
		if (!b[x].r) b[x].r = ++sz;
		b[b[x].l].lzy = b[x].lzy;
		b[b[x].r].lzy = b[x].lzy;
	}
	b[x].lzy = 0;
}

void update(int l, int r, int lzy, int& x, int xl=0, int xr=inf) {
	if (r <= xl || xr <= l) {
		if (x) push_value(x, xl, xr);
		return;
	}
	if (!x) x = ++sz;
	if (l <= xl && xr <= r) {
		b[x].lzy = lzy;
		push_value(x, xl, xr);
		return;
	}
	push_value(x, xl, xr);
	push_down(x, xl, xr);
	int xm = (xl+xr) >> 1;
	update(l, r, lzy, b[x].l, xl, xm);
	update(l, r, lzy, b[x].r, xm, xr);
	b[x].v = 0;
	if (b[x].l) b[x].v += b[b[x].l].v;
	if (b[x].r) b[x].v += b[b[x].r].v;
}

int query(int l, int r, int x, int xl=0, int xr=inf) {
	if (!x || r <= xl || xr <= l)
		return 0;
	push_value(x, xl, xr);
	if (l <= xl && xr <= r)
		return b[x].v;
	push_down(x, xl, xr);
	int xm = (xl+xr) >> 1;
	return query(l, r, b[x].l, xl, xm)
		+  query(l, r, b[x].r, xm, xr);
}

int n;
int p[200005], l[200005];
int xp[200005], yp[200005], ans[200005]; 
basic_string<int> plan[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> p[i] >> l[i];
	int q;
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> xp[i] >> yp[i];
		plan[xp[i]] += i;
	}

	int root = 0;
	update(0, p[n], 1, root);

	for (int i=n; i>=1; i--) {
		// dodaj u drvo
		// cerr << "adding " << i << '\n';
		update(p[i], p[i]+l[i], -1, root);
		for (int j : plan[i]) {
			int y = yp[j];
			// cerr << "answering " << j << '\n';
			ans[j] = query(p[i], p[y], root);
		}
	}

	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}