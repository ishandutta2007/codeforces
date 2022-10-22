#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 1e5 + 5;
const i64 linf = 1LL << 60;

struct point {
	int x, y;
	inline int level() const {
		return std::max(x, y) - 1;
	}
	inline i64 dist(const point &o) const {
		assert(level() == o.level());
		return std::abs(x - o.x) + std::abs(y - o.y);
	}
	inline point go(int d) {
		return {x + (d == 0), y + (d == 1)};
	}
};

int n;
point P[mxn][2];

struct matrix {
	i64 a[2][2];
	matrix() {
		memset(a, 0x3f, sizeof(a));
	}
	matrix(i64 x) {
		memset(a, 0x3f, sizeof(a));
		a[0][0] = a[1][1] = x;
	}
	inline matrix operator * (const matrix &o) const {
		matrix z;
		rep(i, 2) rep(j, 2) rep(k, 2) {
			z.a[i][k] = std::min(z.a[i][k], a[i][j] + o.a[j][k]);
		}
		return z;
	}
};

struct segment_tree {
	static const int mxsz = 1 << 17;
	matrix t[mxsz << 1];
	inline void build(int i, int a, int b) {
		if (a + 1 == b) {
			rep(ai, 2) rep(bi, 2) t[i].a[ai][bi] = 1 + P[a][ai].go(ai).dist(P[b][bi]);
			return ;
		}
		int m = (a + b) >> 1;
		build(i << 1, a, m);
		build(i << 1 | 1, m, b);
		t[i] = t[i << 1] * t[i << 1 | 1];
	}
	inline matrix query(int i, int a, int b, int l, int r) {
		if (l <= a && b <= r) return t[i];
		if (r <= a || b <= l) return matrix(0);
		int m = (a + b) >> 1;
		return query(i << 1, a, m, l, r) * query(i << 1 | 1, m, b, l, r);
	}
} seg;

i64 pref[mxn][2], suff[mxn][2];

int main() {
	#ifdef DEBUG
	freopen("in", "r", stdin);
	#endif
	scanf("%d", &n);
	rep(i, n - 1) rep(j, 2) scanf("%d %d", &P[i][j].x, &P[i][j].y);
	for (int i = 1; i < n; ++ i) rep(j, 2) {
		pref[i][j] = 2 + P[i - 1][j].dist(P[i - 1][j ^ 1]);
		if (i > 1) rep(nj, 2) pref[i][j] = std::min(pref[i][j],
			2 +
			P[i - 1][j].dist(P[i - 2][nj].go(nj)) +
			pref[i - 1][nj] +
			P[i - 1][j ^ 1].dist(P[i - 2][nj ^ 1].go(nj ^ 1))
		);
	}
	for (int i = n - 2; ~i; -- i) rep(j, 2) {
		suff[i][j] = 2 + P[i][j].go(j).dist(P[i][j ^ 1].go(j ^ 1));
		if (i + 2 < n) rep(nj, 2) suff[i][j] = std::min(suff[i][j],
			2 +
			P[i][j].go(j).dist(P[i + 1][nj]) +
			suff[i + 1][nj] +
			P[i][j ^ 1].go(j ^ 1).dist(P[i + 1][nj ^ 1])
		);
	}
	if (n > 2) seg.build(1, 0, n - 2);
	int m;
	scanf("%d", &m);
	while (m --) {
		point A, B;
		scanf("%d %d %d %d", &A.x, &A.y, &B.x, &B.y);
		int p = A.level(), q = B.level();
		if (p > q) std::swap(p, q), std::swap(A, B);
		i64 ans = linf;
		if (p == q) {
			ans = std::min(ans, A.dist(B));
			if (p) rep(pj, 2) {
				ans = std::min(ans, A.dist(P[p - 1][pj].go(pj)) + pref[p][pj] + P[p - 1][pj ^ 1].go(pj ^ 1).dist(B));
			}
			if (q + 1 < n) rep(qj, 2) {
				ans = std::min(ans, A.dist(P[q][qj]) + suff[q][qj] + P[q][qj ^ 1].dist(B));
			}
			if (p && q + 1 < n) rep(pj, 2) rep(qj, 2) {
				i64 lef = A.dist(P[p - 1][pj].go(pj)) + pref[p][pj];
				i64 rig = B.dist(P[q][qj]) + suff[q][qj];
				i64 med = P[p - 1][pj].go(pj).dist(P[q][qj]);
				ans = std::min(ans, lef + med + rig);
			}
		} else {
			matrix temp = p + 1 < q ? seg.query(1, 0, n - 2, p, q - 1) : matrix(0);
			rep(pj, 2) rep(qj, 2) {
				i64 lef = A.dist(P[p][pj]);
				if (p) rep(nj, 2) lef = std::min(lef,
					A.dist(P[p - 1][nj].go(nj)) +
					pref[p][nj] +
					P[p - 1][nj ^ 1].go(nj ^ 1).dist(P[p][pj])
				);
				i64 rig = B.dist(P[q - 1][qj].go(qj));
				if (q + 1 < n) rep(nj, 2) rig = std::min(rig,
					B.dist(P[q][nj]) +
					suff[q][nj] +
					P[q][nj ^ 1].dist(P[q - 1][qj].go(qj))
				);
				i64 med = temp.a[pj][qj] + 1;
				ans = std::min(ans, lef + med + rig);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}