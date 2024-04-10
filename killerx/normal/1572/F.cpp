#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 1 << 18;

struct BIT {
	i64 s0[mxn], s1[mxn];

	inline void update(int x, int v) {
		i64 v0 = v, v1 = 1LL * x * v;
		for (++ x; x < mxn; x += x & -x) s0[x] += v0, s1[x] += v1;
	}

	inline i64 query(int x) {
		int _ = x;
		i64 ans = 0;
		for (++ x; x; x -= x & -x) ans += 1LL * (_ + 1) * s0[x] - s1[x];
		return ans;
	}

	inline void update(int l, int r, int v) {
		update(l, v);
		update(r, -v);
	}

	inline i64 query(int l, int r) {
		return query(r - 1) - query(l - 1);
	}
} bit;

int max[mxn << 1], semax[mxn << 1];
int tagmax[mxn << 1];
int cnt[mxn << 1], maxcnt[mxn << 1];

inline void init() {
	memset(max, -1, sizeof(max));
	memset(semax, -0x3f, sizeof(semax));
	memset(tagmax, 0, sizeof(tagmax));
	memset(cnt, 0, sizeof(cnt));
	memset(maxcnt, 0, sizeof(maxcnt));
}

inline void pushmax(int x, int v) {
	max[x] += v;
	tagmax[x] += v;
}

inline void pushdown(int x) {
	if (tagmax[x]) {
		if (max[x << 1] + tagmax[x] == max[x]) pushmax(x << 1, tagmax[x]);
		if (max[x << 1 | 1] + tagmax[x] == max[x]) pushmax(x << 1 | 1, tagmax[x]);
		tagmax[x] = 0;
	}
}

inline void pushup(int x) {
	max[x] = std::max(max[x << 1], max[x << 1 | 1]);
	semax[x] = std::max(semax[x << 1], semax[x << 1 | 1]);
	if (max[x << 1] != max[x]) semax[x] = std::max(semax[x], max[x << 1]);
	if (max[x << 1 | 1] != max[x]) semax[x] = std::max(semax[x], max[x << 1 | 1]);
	cnt[x] = cnt[x << 1] + cnt[x << 1 | 1];
	maxcnt[x] = 0;
	if (max[x << 1] == max[x]) maxcnt[x] += maxcnt[x << 1];
	if (max[x << 1 | 1] == max[x]) maxcnt[x] += maxcnt[x << 1 | 1];
}

inline void reg(int x, int v, int i = 1, int a = 0, int b = mxn) {
	if (a + 1 == b) {
		if (max[i] != -1) bit.update(x, max[i], -1);
		max[i] = v;
		bit.update(x, max[i], +1);
		semax[i] = -0x3f3f3f3f;
		cnt[i] = maxcnt[i] = 1;
		return ;
	}
	pushdown(i);
	int m = (a + b) >> 1;
	if (x < m) reg(x, v, i << 1, a, m);
	else reg(x, v, i << 1 | 1, m, b);
	pushup(i);
}

inline void update_min(int l, int r, int v, int i = 1, int a = 0, int b = mxn) {
	if (l <= a && b <= r) {
		if (max[i] <= v) return ;
		else if (semax[i] < v) {
			bit.update(v, max[i], -maxcnt[i]);
			return pushmax(i, v - max[i]);
		}
	}
	if (r <= a || b <= l) return ;
	pushdown(i);
	int m = (a + b) >> 1;
	update_min(l, r, v, i << 1, a, m);
	update_min(l, r, v, i << 1 | 1, m, b);
	pushup(i);
}

int n, q;

int main() {
	scanf("%d %d", &n, &q);
	init();
	rep(i, n) reg(i, i + 1);
	while (q --) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int x, w;
			scanf("%d %d", &x, &w);
			-- x;
			reg(x, std::min(n, w));
			update_min(0, x, x);
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			-- l;
			printf("%lld\n", bit.query(l, r));
		}
	}
	return 0;
}