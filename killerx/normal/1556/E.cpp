#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
const int mxlg = 17;

int n, q;
int a[mxn], b[mxn];
long long va[mxn];
int lg[mxn];
long long max[mxn][mxlg], min[mxn][mxlg];

long long qmax(int l, int r) {
	int k = lg[r - l + 1];
	return std::max(max[l][k], max[r - (1 << k) + 1][k]);
}

long long qmin(int l, int r) {
	int k = lg[r - l + 1];
	return std::min(min[l][k], min[r - (1 << k) + 1][k]);
}

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	rep(i, n) va[i] = a[i] - b[i];
	rep(i, n) if (i) va[i] += va[i - 1];
	rep(i, mxn) if (i >= 2) lg[i] = lg[i >> 1] + 1;
	rep(i, n) max[i][0] = min[i][0] = va[i];
	rep(j, mxlg - 1) rep(i, n - (1 << (j + 1)) + 1) {
		max[i][j + 1] = std::max(max[i][j], max[i + (1 << j)][j]);
		min[i][j + 1] = std::min(min[i][j], min[i + (1 << j)][j]);
	}
	while (q --) {
		int l, r;
		scanf("%d %d", &l, &r);
		-- l, -- r;
		long long base = l ? va[l - 1] : 0;
		if (qmax(l, r) - base > 0) printf("-1\n");
		else if (va[r] - base < 0) printf("-1\n");
		else printf("%lld\n", -(qmin(l, r) - base));
	}
	return 0;
}