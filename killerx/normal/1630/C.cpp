#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 18;
int n, a[mxn], b[mxn], m, l[mxn], r[mxn], dp[mxn];

int mn[mxn << 1];

inline void update(int x, int v) {
	x += mxn; mn[x] = std::min(mn[x], v);
	for (; x >>= 1; mn[x] = std::min(mn[x << 1], mn[x << 1 | 1]));
}

inline int query(int l, int r) {
	int ans = mxn;
	for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans = std::min(ans, mn[l ++]);
		if (r & 1) ans = std::min(ans, mn[-- r]);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	memset(l, -1, sizeof(l));
	rep(i, n) {
		if (!~l[a[i]]) l[a[i]] = i;
		r[a[i]] = i;
	}
	rep(i, n) if (i == l[a[i]] || i == r[a[i]]) {
		b[m ++] = a[i];
	}
	int ans = n;
	memset(l, -1, sizeof(l));
	rep(i, m) {
		if (!~l[b[i]]) l[b[i]] = i;
		r[b[i]] = i;
	}
	memset(mn, 0x3f, sizeof(mn));
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	rep(i, m) if (i == r[b[i]]) {
		dp[i + 1] = std::min(dp[i + 1], dp[l[b[i]]] + 1 + (l[b[i]] != r[b[i]]));
		dp[i + 1] = std::min(dp[i + 1], query(l[b[i]] + 1, r[b[i]] + 1) + 1);
		update(i + 1, dp[i + 1]);
	}
	ans -= dp[m];
	printf("%d\n", ans);
	return 0;
}