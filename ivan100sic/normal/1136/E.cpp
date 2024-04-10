#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], k[100005];
ll zk[100005], zzk[100005];

const ll U = -1.7e13;

const int MAXN = 131072;
ll zb[2*MAXN], hi[2*MAXN], lo[2*MAXN], lz[2*MAXN];

void init() {
	for (int i=MAXN; i<2*MAXN; i++)
		zb[i] = hi[i] = lz[i] = lo[i] = U;
	for (int i=MAXN-1; i>=1; i--) {
		zb[i] = zb[2*i] + zb[2*i+1];
		hi[i] = lz[i] = lo[i] = U;
	}
}

void recalc(int x) {
	zb[x] = zb[2*x] + zb[2*x+1];
	lo[x] = min(lo[2*x], lo[2*x+1]);
	hi[x] = max(hi[2*x], hi[2*x+1]);
}

void push(int x, int xl, int xr) {
	if (lz[x] <= lo[x])
		return;
	if (lz[x] >= hi[x]) {
		zb[x] = lz[x] * (xr-xl+1);
		lo[x] = hi[x] = lz[x];
		if (x < MAXN) {
			lz[2*x] = max(lz[2*x], lz[x]);
			lz[2*x+1] = max(lz[2*x+1], lz[x]);
		}
		lz[x] = U;
	} else {
		if (x < MAXN) {
			lz[2*x] = max(lz[2*x], lz[x]);
			lz[2*x+1] = max(lz[2*x+1], lz[x]);
			int xm = (xl + xr) >> 1;
			push(2*x, xl, xm);
			push(2*x+1, xm+1, xr);
			recalc(x);
		} else {
			lo[x] = hi[x] = zb[x] = lz[x];
			lz[x] = U;
		}
	}
}

void update(int l, int r, ll v, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l) {
		push(x, xl, xr);
		return;
	}
	if (l <= xl && xr <= r) {
		lz[x] = max(lz[x], v);
		push(x, xl, xr);
		return;
	}

	int xm = (xl+xr) >> 1;
	push(x, xl, xr);
	update(l, r, v, 2*x, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	recalc(x);
}

ll query(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	push(x, xl, xr);
	if (r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return zb[x];
	int xm = (xl+xr) >> 1;
	return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		cin >> k[i];
		zk[i] = zk[i-1] + k[i];
		zzk[i] = zzk[i-1] + zk[i];
	}

	init();

	for (int i=1; i<=n; i++)
		update(i, i, a[i] - zk[i-1]);

	int q;
	cin >> q;
	while (q--) {
		char t; int x, y;
		cin >> t >> x >> y;
		if (t == '+') {
			ll vr = query(x, x);
			update(x, n, vr+y);
		} else {
			ll vr = query(x, y);
			cout << vr + zzk[y-1] - (x == 1 ? 0 : zzk[x-2]) << '\n';
		}
	}
}