#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const int mxn = 1 << 19;
const i64 linf = 1LL << 60;

int n, q;
int L[mxn], R[mxn], cost[mxn];
i64 s1[mxn], s2[mxn], s3[mxn];

struct val_t {
	i64 mxa, mxb, res;
};

inline val_t operator + (const val_t &a, const val_t &b) {
	return {std::max(a.mxa, b.mxa), std::max(a.mxb, b.mxb), std::max(std::max(a.res, b.res), a.mxa + b.mxb)};
}

struct segment_tree_base {
	val_t va[mxn << 1];

	inline void init(int n, i64 A[], i64 B[]) {
		rep(i, n) va[i + mxn] = {A[i], B[i], A[i] + B[i]};
		for (int i = mxn - 1; i; -- i) va[i] = va[i << 1] + va[i << 1 | 1];
	}

	inline val_t query(int l, int r) {
		val_t ansl = {-linf, -linf, -linf}, ansr = {-linf, -linf, -linf};
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ansl = ansl + va[l ++];
			if (r & 1) ansr = va[-- r] + ansr;
		}
		return ansl + ansr;
	}
} segb;

struct segment_tree_dp {
	i64 mx[mxn << 1];

	inline void init() {
		memset(mx, -0x3f, sizeof(mx));
	}

	inline void update(int x, i64 v) {
		x += mxn;
		for (; x; x >>= 1) mx[x] = std::max(mx[x], v);
	}

	inline i64 query(int l, int r) {
		l = std::max(l, 0);
		r = std::min(r, mxn);
		i64 ans = -linf;
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = std::max(ans, mx[l ++]);
			if (r & 1) ans = std::max(ans, mx[-- r]);
		}
		return ans;
	}
} f;

struct segment_tree_gg {
	i64 mx[mxn << 1], tag[mxn << 1];

	inline void init() {
		memset(tag, 0, sizeof(tag));
		rep(i, mxn) mx[i + mxn] = f.query(i - 1, i);
		for (int i = mxn - 1; i; -- i) mx[i] = std::max(mx[i << 1], mx[i << 1 | 1]);
	}

	inline void push(int x, i64 v) {
		tag[x] += v;
		mx[x] += v;
	}

	inline void pushdown(int x) {
		if (tag[x]) {
			push(x << 1, tag[x]);
			push(x << 1 | 1, tag[x]);
			tag[x] = 0;
		}
	}

	inline void pushup(int x) {
		mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
	}

	inline void update(int l, int r, i64 v, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return push(i, v);
		if (r <= a || b <= l) return ;
		int m = (a + b) >> 1;
		pushdown(i);
		update(l, r, v, i << 1, a, m);
		update(l, r, v, i << 1 | 1, m, b);
		pushup(i);
	}

	inline i64 query(int l, int r, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return mx[i];
		if (r <= a || b <= l) return -linf;
		int m = (a + b) >> 1;
		pushdown(i);
		return std::max(query(l, r, i << 1, a, m), query(l, r, i << 1 | 1, m, b));
	}
} seggg;

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) {
		int x;
		scanf("%d", &x);
		s1[i + 1] = s1[i] + x;
	}
	rep(i, n) {
		int x;
		scanf("%d", &x);
		s2[i + 1] = s2[i] + x;
	}
	rep(i, n) {
		int x;
		scanf("%d", &x);
		s3[i + 1] = s3[i] + x;
	}
	static i64 A[mxn], B[mxn];
	rep(i, n) A[i] = -s2[i] + s1[i + 1];
	rep(i, n) B[i] = s2[i + 1] + s3[n] - s3[i];
	segb.init(n, A, B);
	rep(i, q) {
		scanf("%d %d %d", &L[i], &R[i], &cost[i]);
		-- L[i], -- R[i];
	}
	std::vector <int> id(q);
	std::iota(id.begin(), id.end(), 0);
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return R[i] < R[j]; });
	f.init();
	i64 ans = -linf;
	for (int i : id) {
		ans = std::max(ans, segb.query(L[i], R[i] + 1).res - cost[i]);
		f.update(R[i], std::max(segb.query(L[i], R[i] + 1).mxa, f.query(L[i] - 1, R[i])) - cost[i]);
	}
	seggg.init();
	static std::vector <int> VV[mxn];
	for (int i : id) VV[R[i]].push_back(i);
	static int stk[mxn], top;
	top = 0;
	rep(p, n) {
		while (top && B[stk[top - 1]] < B[p]) {
			-- top;
			seggg.update(top ? stk[top - 1] + 1 : 0, stk[top] + 1, -B[stk[top]]);
		}
		seggg.update(top ? stk[top - 1] + 1 : 0, p + 1, B[p]);
		stk[top ++] = p;
		for (int i : VV[p]) {
			ans = std::max(ans, seggg.query(L[i], R[i] + 1) - cost[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}