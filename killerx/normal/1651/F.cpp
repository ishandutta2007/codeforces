#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 1 << 18;

int n, C[mxn], R[mxn];

struct segment_tree {
	std::vector <int> tim[mxn << 1];
	std::vector <i64> sumR[mxn << 1], sumC[mxn << 1];
	std::vector <int> ptr_l[mxn], ptr_r[mxn];

	inline void init() {
		rep(i, n) {
			tim[i + mxn].push_back((C[i] + R[i] - 1) / R[i]);
			sumR[i + mxn].push_back(R[i]);
			sumC[i + mxn].push_back(C[i]);
		}
		for (int i = mxn - 1; i; -- i) {
			for (int p = 0, q = 0; p < (int) tim[i << 1].size() || q < (int) tim[i << 1 | 1].size(); ) {
				if (p < (int) tim[i << 1].size() && (q == (int) tim[i << 1 | 1].size() || tim[i << 1][p] < tim[i << 1 | 1][q])) {
					tim[i].push_back(tim[i << 1][p]);
					sumR[i].push_back(sumR[i << 1][p]);
					sumC[i].push_back(sumC[i << 1][p]);
					++ p;
				} else {
					tim[i].push_back(tim[i << 1 | 1][q]);
					sumR[i].push_back(sumR[i << 1 | 1][q]);
					sumC[i].push_back(sumC[i << 1 | 1][q]);
					++ q;
				}
			}
		}
		for (int i = 1; i < mxn << 1; ++ i) {
			std::vector <i64> s(tim[i].size() + 1);
			rep(j, tim[i].size()) s[j + 1] = s[j] + sumR[i][j];
			sumR[i] = s;
			rep(j, tim[i].size()) s[j + 1] = s[j] + sumC[i][j];
			sumC[i] = s;
		}
		for (int i = 2; i < mxn << 1; ++ i) {
			std::vector <int> ptr;
			int k = 0;
			rep(j, tim[i >> 1].size()) {
				while (k < (int) tim[i].size() && tim[i][k] < tim[i >> 1][j]) ++ k;
				ptr.push_back(k);
			}
			ptr.push_back(tim[i].size());
			if (i & 1) ptr_r[i >> 1] = ptr;
			else ptr_l[i >> 1] = ptr;
		}
	}

	inline i64 __solve(int x, int T, int it) {
		return sumC[x][it] + T * (sumR[x].back() - sumR[x][it]);
	}

	inline i64 __solve(int i, int a, int b, int l, int r, int T, int it) {
		if (l <= a && b <= r) return __solve(i, T, it);
		if (r <= a || b <= l) return 0;
		int m = (a + b) >> 1;
		return __solve(i << 1, a, m, l, r, T, ptr_l[i][it]) + __solve(i << 1 | 1, m, b, l, r, T, ptr_r[i][it]);
	}

	inline i64 solve(int l, int r, int T) {
		auto it = std::upper_bound(tim[1].begin(), tim[1].end(), T) - tim[1].begin();
		return __solve(1, 0, mxn, l, r, T, it);
	}

	inline int __binary_search(int i, int T, int it, i64 &h) {
		if (__solve(i, T, it) < h) { h -= __solve(i, T, it); return -1; }
		if (i >= mxn) return i - mxn;
		int ans = __binary_search(i << 1, T, ptr_l[i][it], h);
		if (!~ans) ans = __binary_search(i << 1 | 1, T, ptr_r[i][it], h);
		return ans;
	}

	inline int __binary_search(int i, int a, int b, int l, int r, int T, int it, i64 &h) {
		if (l <= a && b <= r) return __binary_search(i, T, it, h);
		if (r <= a || b <= l) return -1;
		int m = (a + b) >> 1;
		int ans = __binary_search(i << 1, a, m, l, r, T, ptr_l[i][it], h);
		if (!~ans) ans =__binary_search(i << 1 | 1, m, b, l, r, T, ptr_r[i][it], h);
		return ans;
	}

	inline int binary_search(int l, int r, int T, i64 h) {
		auto it = std::upper_bound(tim[1].begin(), tim[1].end(), T) - tim[1].begin();
		int p = __binary_search(1, 0, mxn, l, r, T, it, h);
		if (!~p) return r;
		return p;
	}
} seg;

struct range {
	int l, r;
	int tp;
	int t, v;

	inline bool operator < (const range &oth) const { return l < oth.l; }
};

int main() {
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &C[i], &R[i]);
	/*
	rep(i, n) eprintf("%d ", C[i]);
	eprintf("\n");
	rep(i, n) eprintf("%d ", R[i]);
	eprintf("\n");
	eprintf("\n");
	*/
	seg.init();
	i64 ans = 0;
	std::set <range> st;
	st.insert({0, n, 1, -0x3f3f3f3f, 0});
	int q;
	scanf("%d", &q);
	while (q --) {
		int T; i64 h;
		scanf("%d %lld", &T, &h);
		/*
		eprintf("%d %lld\n", T, h);
		for (auto x : st) {
			if (x.tp == 0) eprintf("%lld ", std::min(1LL * C[x.l], x.v + 1LL * R[x.l] * (T - x.t)));
			else for (int i = x.l; i < x.r; ++ i) eprintf("%lld ", seg.solve(i, i + 1, T - x.t));
		}
		eprintf("\n");
		*/
		int p = 0;
		while (!st.empty() && h) {
			int l = st.begin()->l, r = st.begin()->r, tp = st.begin()->tp, t = st.begin()->t, v = st.begin()->v;
			st.erase(st.begin());
			if (tp == 0) {
				v = std::min(1LL * C[l], v + 1LL * R[l] * (T - t));
				if (v > h) {
					p = l;
					st.insert({l, r, 0, T, v - h});
					h = 0;
				} else {
					p = r;
					h -= v;
				}
			} else {
				i64 cur = seg.solve(l, r, T - t);
				if (cur > h) {
					p = seg.binary_search(l, r, T - t, h);
					h -= seg.solve(l, p, T - t);
					st.insert({p, p + 1, 0, T, seg.solve(p, p + 1, T - t) - h});
					if (p + 1 < r) st.insert({p + 1, r, 1, t, 0});
					h = 0;
					break;
				} else {
					p = r;
					h -= cur;
				}
			}
		}
		if (p) st.insert({0, p, 1, T, 0});
		ans += h;
		/*
		eprintf("left %lld\n", h);
		for (auto x : st) {
			if (x.tp == 0) eprintf("%lld ", std::min(1LL * C[x.l], x.v + 1LL * R[x.l] * (T - x.t)));
			else for (int i = x.l; i < x.r; ++ i) eprintf("%lld ", seg.solve(i, i + 1, T - x.t));
		}
		eprintf("\n");
		*/
	}
	printf("%lld\n", ans);
	return 0;
}