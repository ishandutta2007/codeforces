#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[1000005];
const int maxn = 1 << 30;

struct node {
	int l, r, v;
} b[1000005 * 33]; int sz;

void add(int p, int& x, int xl=0, int xr=maxn-1) {
	if (!x) x = ++sz;
	b[x].v++;
	if (xl == xr) return;
	int xm = (xl+xr) >> 1;
	if (p <= xm)
		add(p, b[x].l, xl, xm);
	else
		add(p, b[x].r, xm+1, xr);
}

int seek(int t, int x, int xl=0, int xr=maxn-1, int level = maxn/2) {
	if (!x) return 0;
	if (xl >= k)
		return b[x].v;
	if (xr < k)
		return 0;
	int xm = (xl+xr) >> 1;
	int bit = level & t;
	return seek(t, bit ? b[x].r : b[x].l,   xl, xm, level >> 1)
		 + seek(t, bit ? b[x].l : b[x].r, xm+1, xr, level >> 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	ll sol = 0;
	int xr = 0, root = 0;

	add(0, root);
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		xr ^= x;
		int t = seek(xr, root);
		// cerr << "step " << i << ' ' << t << '\n';
		sol += t;
		add(xr, root);
	}

	cout << sol << '\n';
}