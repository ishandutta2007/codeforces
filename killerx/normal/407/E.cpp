#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 18;

struct segment_tree {
	int sz;
	int mx[mxn << 1], tag[mxn << 1];

	inline void init(int _n) {
		for (sz = 1; sz < _n; sz <<= 1);
		rep(i, sz << 1) mx[i] = tag[i] = 0;
	}

	inline void push(int x, int v) { tag[x] += v, mx[x] += v; }

	inline void pushdown(int x) { if (tag[x]) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = 0; }

	inline void pushup(int x) { mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]); }

	inline void update(int l, int r, int v, int i, int a, int b) {
		if (l <= a && b <= r) return push(i, v);
		if (r <= a || b <= l) return ;
		pushdown(i);
		int m = (a + b) >> 1;
		update(l, r, v, i << 1, a, m);
		update(l, r, v, i << 1 | 1, m, b);
		pushup(i);
	}

	inline int __query(int v, int i, int a, int b) {
		if (mx[i] < v) return -1;
		if (a + 1 == b) return a;
		pushdown(i);
		int m = (a + b) >> 1;
		int ans = -1;
		ans = __query(v, i << 1 | 1, m, b);
		if (~ans) return ans;
		ans = __query(v, i << 1, a, m);
		if (~ans) return ans;
		return -1;
	}

	inline int query(int l, int r, int v, int i, int a, int b) {
		if (mx[i] < v) return -1;
		if (l <= a && b <= r) return __query(v, i, a, b);
		if (r <= a || b <= l) return -1;
		pushdown(i);
		int m = (a + b) >> 1;
		int ans = -1;
		ans = query(l, r, v, i << 1 | 1, m, b);
		if (~ans) return ans;
		ans = query(l, r, v, i << 1, a, m);
		if (~ans) return ans;
		return -1;
	}

	inline int get(int x, int i, int a, int b) {
		if (a + 1 == b) return mx[i];
		pushdown(i);
		int m = (a + b) >> 1;
		if (x < m) return get(x, i << 1, a, m);
		else return get(x, i << 1 | 1, m, b);
	}

	inline void update(int l, int r, int v) { update(l, r, v, 1, 0, sz); }
	inline int query(int l, int r, int v) { return query(l, r, v, 1, 0, sz); }
	inline int get(int x) { return get(x, 1, 0, sz); }
} seg;

struct answer {
	int l, r;
};

inline bool operator < (const answer &i, const answer &j) {
	return i.r - i.l != j.r - j.l ? i.r - i.l < j.r - j.l : i.l > j.l;
}

answer ans = {0, -1};

int n, k, d;
int a[mxn], b[mxn];

inline void solve(int L, int R) {
	// eprintf("solve: [%d, %d)\n", L + 1, R + 1);
	const int N = R - L;
	static int v[mxn];
	for (int i = R - 1; i >= L; -- i)
		v[i - L] = (a[i] - b[i]) / d;
	// eprintf("v: ");
	// rep(i, n) eprintf("%d ", v[i]);
	// eprintf("\n");
	seg.init(N);
	rep(i, N) seg.update(i, i + 1, i);
	static int sl[mxn], ss[mxn];
	int tl = 0, ts = 0;
	int right = N;
	std::map <int, int> nex;
	for (int i = N - 1; ~i; -- i) {
		if (nex.find(v[i]) != nex.end()) right = std::min(right, nex[v[i]]);
		nex[v[i]] = i;
		while (tl && v[sl[tl - 1]] < v[i]) {
			-- tl;
			if (tl) seg.update(sl[tl], sl[tl - 1], +v[sl[tl]]);
			else seg.update(sl[tl], N, +v[sl[tl]]);
		}
		if (tl) seg.update(i, sl[tl - 1], -v[i]);
		else seg.update(i, N, -v[i]);
		sl[tl ++] = i;
		while (ts && v[ss[ts - 1]] > v[i]) {
			-- ts;
			if (ts) seg.update(ss[ts], ss[ts - 1], -v[ss[ts]]);
			else seg.update(ss[ts], N, -v[ss[ts]]);
		}
		if (ts) seg.update(i, ss[ts - 1], +v[i]);
		else seg.update(i, N, +v[i]);
		ss[ts ++] = i;
		// eprintf("%d: ", L + i + 1);
		// for (int x = i; x < right; ++ x) eprintf("%d", seg.get(x) >= i - k);
		// eprintf("\n");
		int j = seg.query(i, right, i - k);
		if (~j) ans = std::max(ans, (answer){L + i, L + j});
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &d);
	rep(i, n) scanf("%d", &a[i]);
	if (d == 0) {
		rep(i, n) {
			int j = i;
			while (j < n && a[i] == a[j]) ++ j;
			ans = std::max(ans, (answer){i, j - 1});
			i = j - 1;
		}
		printf("%d %d\n", ans.l + 1, ans.r + 1);
		return 0;
	}
	rep(i, n) b[i] = (a[i] % d + d) % d;
	rep(i, n) {
		int j = i;
		while (j < n && b[j] == b[i]) ++ j;
		solve(i, j);
		i = j - 1;
	}
	printf("%d %d\n", ans.l + 1, ans.r + 1);
	return 0;
}