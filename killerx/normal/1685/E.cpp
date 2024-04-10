#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 1 << 19;

int n, nn, Q, p[mxn], ip[mxn];

namespace checker {
	inline bool chk(int x) {
		std::vector <int> dp(nn + 1, 0x3f3f3f3f);
		rep(i, nn) {
			int v = p[(x + i) % nn];
			*std::lower_bound(dp.begin(), dp.end(), v) = v;
		}
		return int(std::lower_bound(dp.begin(), dp.end(), nn) - dp.begin()) <= n;
	}
}

inline int sgn(int x) {
	return x < n ? -1 : x == n ? 0 : +1;
}

struct item {
	int sum, mnsum, mnsump;
	item(): sum(0), mnsum(1 << 30), mnsump(-1) {}
	item(int _sum, int _mnsum, int _mnsump): sum(_sum), mnsum(_mnsum), mnsump(_mnsump) {}
	inline item operator + (const item &o) const {
		return item(sum + o.sum, std::min(mnsum, sum + o.mnsum), mnsum < sum + o.mnsum ? mnsump : o.mnsump);
	}
};

struct segment_tree {
	item t[mxn << 1];
	inline void update(int x, int v) {
		t[x + mxn] = item(v, std::min(v, 0), v < 0 ? x + 1 : x);
		for (x += mxn; x >>= 1; t[x] = t[x << 1] + t[x << 1 | 1]);
	}
	inline item query(int l, int r) {
		item ansl, ansr;
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ansl = ansl + t[l ++];
			if (r & 1) ansr = t[-- r] + ansr;
		}
		return ansl + ansr;
	}
} seg;

i64 buc1 = 0, buc2 = 0;

inline void pos_update(int x, int v) {
	if (x <= n) {
		buc1 -= (ip[x] + nn - ip[(x + (n + 1) - 1) % (n + 1)]) % nn;
		buc1 -= (ip[(x + 1) % (n + 1)] + nn - ip[x]) % nn;
	}
	if (x >= n) {
		buc2 -= (ip[x] + nn - ip[n + (x - n + (n + 1) - 1) % (n + 1)]) % nn;
		buc2 -= (ip[n + (x - n + 1) % (n + 1)] + nn - ip[x]) % nn;
	}
	ip[x] = v;
	if (x <= n) {
		buc1 += (ip[x] + nn - ip[(x + (n + 1) - 1) % (n + 1)]) % nn;
		buc1 += (ip[(x + 1) % (n + 1)] + nn - ip[x]) % nn;
	}
	if (x >= n) {
		buc2 += (ip[x] + nn - ip[n + (x - n + (n + 1) - 1) % (n + 1)]) % nn;
		buc2 += (ip[n + (x - n + 1) % (n + 1)] + nn - ip[x]) % nn;
	}
}

int main() {
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d %d", &n, &Q);
	nn = n * 2 + 1;
	rep(i, nn) scanf("%d", &p[i]), -- p[i], ip[p[i]] = i;
	rep(i, nn * 2) seg.update(i, sgn(p[i % nn]));
	rep(i, n + 1) {
		int j = (i + 1) % (n + 1);
		buc1 += (ip[j] + nn - ip[i]) % nn;
		buc2 += (ip[n + j] + nn - ip[n + i]) % nn;
	}
	while (Q --) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		int a = p[u], b = p[v];
		seg.update(u, sgn(b)), seg.update(u + nn, sgn(b));
		seg.update(v, sgn(a)), seg.update(v + nn, sgn(a));
		pos_update(a, v), pos_update(b, u);
		std::swap(p[u], p[v]);
		int ans = -1;
		int ps = seg.query(0, nn).mnsump % nn;
		int z = ip[n] < ps ? ip[n] + nn : ip[n];
		if (seg.query(ps, z).sum != 0) ans = ps;
		else if (buc1 != nn) ans = (ip[n] + 1) % nn;
		else if (buc2 != nn) ans = ip[n];
		if (ans == nn) ans = 0;
		printf("%d\n", ans);
#ifdef DEBUG
		// rep(i, nn) eprintf("%d ", p[(ans + i) % nn]); eprintf("\n");
		if (~ans) assert(checker::chk(ans));
#endif
	}
	return 0;
}