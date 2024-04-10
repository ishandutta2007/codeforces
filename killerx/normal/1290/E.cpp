#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 1 << 18;

i64 max[mxn << 1], semax[mxn << 1];
i64 sum[mxn << 1];
i64 tag[mxn << 1], tagmax[mxn << 1];
int cnt[mxn << 1], maxcnt[mxn << 1];

inline void init() {
	memset(max, 0, sizeof(max));
	memset(semax, -0x3f, sizeof(semax));
	memset(sum, 0, sizeof(sum));
	memset(tag, 0, sizeof(tag));
	memset(tagmax, 0, sizeof(tagmax));
	memset(cnt, 0, sizeof(cnt));
	memset(maxcnt, 0, sizeof(maxcnt));
}

inline void push(int x, i64 v) {
	tag[x] += v;
	max[x] += v;
	semax[x] += v;
	sum[x] += v * cnt[x];
}

inline void pushmax(int x, i64 v) {
	max[x] += v;
	tagmax[x] += v;
	sum[x] += v * maxcnt[x];
}

inline void pushdown(int x) {
	if (tag[x]) {
		push(x << 1, tag[x]);
		push(x << 1 | 1, tag[x]);
		tag[x] = 0;
	}
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
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
	cnt[x] = cnt[x << 1] + cnt[x << 1 | 1];
	maxcnt[x] = 0;
	if (max[x << 1] == max[x]) maxcnt[x] += maxcnt[x << 1];
	if (max[x << 1 | 1] == max[x]) maxcnt[x] += maxcnt[x << 1 | 1];
}

inline void reg(int x, i64 v, int i = 1, int a = 0, int b = mxn) {
	if (a + 1 == b) {
		max[i] = v;
		semax[i] = -(1LL << 60);
		sum[i] = v;
		cnt[i] = maxcnt[i] = 1;
		return ;
	}
	pushdown(i);
	int m = (a + b) >> 1;
	if (x < m) reg(x, v, i << 1, a, m);
	else reg(x, v, i << 1 | 1, m, b);
	pushup(i);
}

inline i64 get(int x, int i = 1, int a = 0, int b = mxn) {
	if (a + 1 == b) return sum[i];
	pushdown(i);
	int m = (a + b) >> 1;
	if (x < m) return get(x, i << 1, a, m);
	else return get(x, i << 1 | 1, m, b);
}

inline void update_tag(int l, int r, i64 v, int i = 1, int a = 0, int b = mxn) {
	if (l <= a && b <= r) return push(i, v);
	if (r <= a || b <= l) return ;
	pushdown(i);
	int m = (a + b) >> 1;
	update_tag(l, r, v, i << 1, a, m);
	update_tag(l, r, v, i << 1 | 1, m, b);
	pushup(i);
}

inline void update_min(int l, int r, i64 v, int i = 1, int a = 0, int b = mxn) {
	if (l <= a && b <= r) {
		if (max[i] <= v) return ;
		else if (semax[i] < v) return pushmax(i, v - max[i]);
	}
	if (r <= a || b <= l) return ;
	pushdown(i);
	int m = (a + b) >> 1;
	update_min(l, r, v, i << 1, a, m);
	update_min(l, r, v, i << 1 | 1, m, b);
	pushup(i);
}

inline i64 query() {
	return sum[1];
}

int s[mxn];

inline void insert(int x) {
	for (++ x; x < mxn; x += x & -x) s[x] += 1;
}

inline int rank(int x) {
	int ans = 0;
	for (++ x; x; x -= x & -x) ans += s[x];
	return ans;
}

int n, a[mxn], ia[mxn];

void solve(i64 ans[]) {
	rep(i, n) ia[a[i]] = i;
	init();
	memset(s, 0, sizeof(s));
	rep(_, n) {
		int i = ia[_];
		int ri = rank(i);
		insert(i);
		reg(i, _);
		update_tag(i, n, 1);
		update_min(0, i, ri);
		ans[_] = query() - 1LL * (_ + 1) * (_ + 2) / 2;
//		rep(i, n) eprintf("%lld ", get(i));
//		eprintf("\n");
	}
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]), -- a[i];
	static i64 L[mxn], R[mxn];
	solve(R);
	std::reverse(a, a + n);
	solve(L);
	rep(i, n) printf("%lld\n", L[i] + R[i] + (i + 1));
	return 0;
}