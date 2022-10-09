#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, l, s;
int a[100005];
int lvl[100005];
int mx[17][100005], mn[17][100005];

int getrange(int l, int r) {
	int w = r-l;
	int q = lvl[w];
	return max(mx[q][l], mx[q][r-(1<<q)])
		- min(mn[q][l], mn[q][r-(1<<q)]);
}

const int MAXN = 131072;
int d[2*MAXN];

void postavi(int x, int v) {
	x += MAXN;
	d[x] = v;
	while (x > 1) {
		x >>= 1;
		d[x] = min(d[2*x], d[2*x+1]);
	}
}

int citaj(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l)
		return 123123123;
	if (l <= xl && xr <= r)
		return d[x];
	int xm = (xl+xr) >> 1;
	return min(
		citaj(l, r, 2*x, xl, xm),
		citaj(l, r, 2*x+1, xm+1, xr)
	);
}

int extenduj(int g) {
	int lo=l, hi=g, o = -1;
	while (lo <= hi) {
		int mid = (lo+hi) >> 1;
		if (getrange(g-mid, g) <= s) {
			o = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(d, 63, sizeof(d));

	cin >> n >> s >> l;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=2; i<=n; i++)
		lvl[i] = lvl[i >> 1] + 1;

	for (int i=0; i<n; i++)
		mx[0][i] = mn[0][i] = a[i];

	for (int k=1; k<17; k++) {
		for (int i=0; i<n; i++) {
			int j = i + (1 << (k-1));
			mn[k][i] = mn[k-1][i];
			mx[k][i] = mx[k-1][i];
			if (j < n) {
				mn[k][i] = min(mn[k][i], mn[k-1][j]);
				mx[k][i] = max(mx[k][i], mx[k-1][j]);
			}
		}
	}

	postavi(0, 0);
	for (int i=1; i<=n; i++) {
		int w = extenduj(i);
		// cerr << "ex " << i << ' ' << w << '\n';
		if (w != -1) {
			int v = citaj(i-w, i-l) + 1;
			postavi(i, v);
		}
	}

	int r = d[n + MAXN];
	if (r > n)
		r = -1;
	cout << r << '\n';
}