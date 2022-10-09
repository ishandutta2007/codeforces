#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

static const int W = 100;
static const int MAXN = 262144;
typedef array<int8_t, W> niz;

static inline niz ident() {
	niz t;
	iota(t.begin(), t.end(), 0);
	return t;
}

static inline void inplace_spoji_singl(niz& a, int i, int j) {
	for (int k=0; k<W; k++)
		if (a[k] == i)
			a[k] = j;
}

static inline niz spoji(const niz& a, const niz& b) {
	niz c;
	for (int i=0; i<W; i++)
		c[i] = b[a[i]];
	return c;
}

static niz a[2*MAXN];
static bool dirty[2*MAXN];

static inline void push(int x) {
	if (!dirty[x]) return;
	if (x < MAXN) {
		a[2*x] = spoji(a[2*x], a[x]);
		a[2*x+1] = spoji(a[2*x+1], a[x]);
		a[x] = ident();
		dirty[x] = 0;
		dirty[2*x] = 1;
		dirty[2*x+1] = 1;
	}
}

static void update(int l, int r, int i, int j, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}

	if (l <= xl && xr <= r) {
		inplace_spoji_singl(a[x], i, j);
		dirty[x] = 1;
		push(x);
		return;
	}

	push(x);
	int xm = (xl + xr) >> 1;
	update(l, r, i, j, 2*x, xl, xm);
	update(l, r, i, j, 2*x+1, xm+1, xr);
}

static int n;
static int b[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		b[i] = x-1;
	}

	for (int i=1; i<2*MAXN; i++)
		a[i] = ident();

	int q;
	cin >> q;
	while (q--) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		x--, y--;
		if (x != y) {
			update(l, r, x, y);
		}
	}

	for (int i=1; i<MAXN; i++)
		push(i);

	for (int i=1; i<=n; i++) {
		cout << a[i + MAXN][b[i]] + 1 << ' ';
	}
	cout << '\n';
}