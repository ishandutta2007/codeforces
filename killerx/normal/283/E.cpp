#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 17;

int n, q;
int a[mxn], vec[mxn], cnt;
int deg[mxn];

struct segment_tree {
	bool tag[mxn << 1];
	int sum[mxn << 1][2];

	inline void push(int x) {
		tag[x] ^= 1;
		std::swap(sum[x][0], sum[x][1]);
	}

	inline void pushdown(int x) {
		if (tag[x]) {
			push(x << 1);
			push(x << 1 | 1);
			tag[x] = 0;
		}
	}

	inline void pushup(int x) {
		sum[x][0] = sum[x << 1][0] + sum[x << 1 | 1][0];
		sum[x][1] = sum[x << 1][1] + sum[x << 1 | 1][1];
	}

	inline void init() {
		memset(tag, 0, sizeof(tag));
		memset(sum, 0, sizeof(sum));
		rep(i, n) sum[i + mxn][0] = 1;
		for (int i = mxn - 1; i; -- i) pushup(i);
	}

	inline void update(int l, int r, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return push(i);
		if (r <= a || b <= l) return ;
		pushdown(i);
		int m = a + b >> 1;
		update(l, r, i << 1, a, m);
		update(l, r, i << 1 | 1, m, b);
		pushup(i);
	}

	inline int query(int l, int r, int v, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return sum[i][v];
		if (r <= a || b <= l) return 0;
		pushdown(i);
		int m = a + b >> 1;
		return query(l, r, v, i << 1, a, m) + query(l, r, v, i << 1 | 1, m, b);
	}
} seg;

struct segment_tree_event {
	std::vector <std::pair <int, int> > qwq[mxn << 1];

	void update(int l, int r) {
		int L = l, R = r;
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) qwq[l ++].push_back({L, R});
			if (r & 1) qwq[-- r].push_back({L, R});
		}
	}

	void solve(int i = 1, int a = 0, int b = mxn) {
		for (auto [l, r] : qwq[i]) seg.update(l, r);
		if (a + 1 == b) {
			if (a < n) deg[a] = seg.query(0, a, 0) + seg.query(a + 1, cnt, 1);
		} else {
			int m = a + b >> 1;
			solve(i << 1, a, m);
			solve(i << 1 | 1, m, b);
		}
		for (auto [l, r] : qwq[i]) seg.update(l, r);
	}
} seg_event;

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &a[i]), vec[cnt ++] = a[i];
	std::sort(vec, vec + cnt);
	cnt = std::unique(vec, vec + cnt) - vec;
	static std::vector <std::pair <int, int> > evt[mxn];
	rep(i, q) {
		int l, r;
		scanf("%d %d", &l, &r);
		l = std::lower_bound(vec, vec + cnt, l) - vec;
		r = std::lower_bound(vec, vec + cnt, r + 1) - vec;
		evt[l].push_back({l, r});
		evt[r].push_back({l, r});
	}
	seg.init();
	// seg_event.solve();
	rep(i, n) {
		for (auto [l, r] : evt[i]) {
			seg.update(l, r);
		}
		deg[i] = seg.query(0, i, 0) + seg.query(i + 1, n, 1);
	}
	long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
	rep(i, n) ans -= 1LL * deg[i] * (deg[i] - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}