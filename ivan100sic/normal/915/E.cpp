#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAXN = 1 << 20;
int a[2 * MAXN], b[2 * MAXN], len[2 * MAXN];
int u[MAXN], uu;
int ql[300005], qr[300005], qk[300005];

void init() {
	for (int i=0; i<uu-1; i++)
		len[i + MAXN] = u[i+1] - u[i];
	for (int i=MAXN-1; i>0; i--)
		len[i] = len[2*i] + len[2*i+1];
	fill(b, b+2*MAXN, -1);
}

void push(int x) {
	if (b[x] == -1)
		return;
	if (x < MAXN) {
		b[2*x] = b[x];
		b[2*x+1] = b[x];
	}
	a[x] = len[x] * b[x];
	b[x] = -1;
}

void update(int l, int r, int v, int x, int xl, int xr) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x] = v;
		push(x);
		return;
	}
	push(x);
	int xm = (xl+xr) >> 1;
	update(l, r, v, 2*x, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	a[x] = a[2*x] + a[2*x+1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for (int i=0; i<q; i++) {
		cin >> ql[i] >> qr[i] >> qk[i];
		ql[i]--;
		u[uu++] = ql[i];
		u[uu++] = qr[i];
	}
	u[uu++] = 0;
	u[uu++] = n;
	sort(u, u+uu);
	uu = unique(u, u+uu) - u;

	init();
	for (int i=0; i<q; i++) {
		int l = lower_bound(u, u+uu, ql[i]) - u;
		int r = lower_bound(u, u+uu, qr[i]) - u;
		update(l, r-1, 2-qk[i], 1, 0, MAXN-1);
		cout << n - a[1] << '\n';
	}
}