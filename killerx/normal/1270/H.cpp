#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 20, mxlg = 20;

int n, q, a[mxn];

struct segment_tree {
	struct item {
		int mn, mncnt;

		friend inline item operator + (const item &a, const item &b) {
			if (!a.mncnt) return b;
			if (!b.mncnt) return a;
			item c;
			c.mn = std::min(a.mn, b.mn);
			c.mncnt = (a.mn == c.mn) * a.mncnt + (b.mn == c.mn) * b.mncnt;
			return c;
		}
	};

	int tag[mxn << 1];
	item val[mxn << 1];

	inline void push(int x, int t) {
		tag[x] += t;
		val[x].mn += t;
	}

	inline void pushdown(int x) {
		if (tag[x]) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = 0;
	}

	inline void pushup(int x) {
		val[x] = val[x << 1] + val[x << 1 | 1];
	}

	inline void init() {
		static int pre[mxn];
		rep(i, mxn) pre[i] = 0;
		rep(i, n - 1) {
			if (a[i + 1] < a[i]) pre[a[i + 1] + 1] += 1, pre[a[i] + 1] -= 1;
			if (a[i] < a[i + 1]) pre[a[i] + 1] += 1, pre[a[i + 1] + 1] -= 1;
		}
		rep(i, mxn) if (i) pre[i] += pre[i - 1];
		static bool vis[mxn];
		rep(i, mxn) vis[i] = 0;
		for (int i = 1; i < n - 1; ++ i) vis[a[i]] = 1;
		rep(i, mxn << 1) tag[i] = 0, val[i] = {mxn, 0};
		rep(i, mxn) val[i + mxn] = {pre[i], vis[i]};
		for (int i = mxn - 1; i; -- i) pushup(i);
	}

	inline void update(int l, int r, int t, int i, int a, int b) {
		if (l <= a && b <= r) return push(i, t);
		int m = (a + b) >> 1;
		pushdown(i);
		if (l < m) update(l, r, t, i << 1, a, m);
		if (r > m) update(l, r, t, i << 1 | 1, m, b);
		pushup(i);
	}

	inline void update(int l, int r, int t) { if (l < r) update(l, r, t, 1, 0, mxn); }

	inline void set(int x, int tp) {
		x += mxn;
		for (int i = mxlg; i; -- i) pushdown(x >> i);
		val[x].mncnt = tp;
		for (int i = 1; i <= mxlg; ++ i) pushup(x >> i);
	}
} seg;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	n += 2;
	a[0] = 1e6 + 1; a[n - 1] = 0;
	seg.init();
	while (q --) {
		int p, v;
		scanf("%d %d", &p, &v);
		seg.set(a[p], 0);
		seg.update(std::min(a[p - 1], a[p]) + 1, std::max(a[p - 1], a[p]) + 1, -1);
		seg.update(std::min(a[p], a[p + 1]) + 1, std::max(a[p], a[p + 1]) + 1, -1);
		a[p] = v;
		seg.set(a[p], 1);
		seg.update(std::min(a[p - 1], a[p]) + 1, std::max(a[p - 1], a[p]) + 1, +1);
		seg.update(std::min(a[p], a[p + 1]) + 1, std::max(a[p], a[p + 1]) + 1, +1);
		printf("%d\n", (seg.val[1].mn == 1) * seg.val[1].mncnt);
	}
	return 0;
}