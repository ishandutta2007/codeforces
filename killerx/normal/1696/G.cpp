#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using db = double;
const db inf = 1e18;

const int B = 3;
const int mxn = 1 << 18;

int n, q, x, y;
int a[mxn];

struct matrix {
	db va[B][B];
	matrix(db z = -inf) {
		rep(i, B) rep(j, B) va[i][j] = i == j ? z : -inf;
	}
	inline matrix operator * (const matrix &o) const {
		matrix res;
		rep(i, B) rep(j, B) rep(k, B)
			res.va[i][k] = std::max(res.va[i][k], va[i][j] + o.va[j][k]);
		return res;
	}
};

inline matrix E(int v) {
	const long long V[] = {0, y, x + y};
	const long long VV = 1LL * (x + y) * y;
	matrix tr;
	rep(i, B) rep(j, B) {
		if (1LL * V[i] * x + 1LL * V[j] * y <= VV &&
			1LL * V[j] * x + 1LL * V[i] * y <= VV) {
			tr.va[i][j] = (db)(V[j]) / VV * v;
		}
	}
	return tr;
}

struct segment_tree {
	matrix t[mxn << 1];
	inline void init() {
		rep(i, n) t[i + mxn] = E(a[i]);
		for (int i = mxn - 1; i; -- i) t[i] = t[i << 1] * t[i << 1 | 1];
	}
	inline void update(int i, int v) {
		for (t[i += mxn] = E(v); i >>= 1; t[i] = t[i << 1] * t[i << 1 | 1]);
	}
	inline matrix query(int l, int r) {
		matrix L(0), R(0);
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) L = L * t[l ++];
			if (r & 1) R = t[-- r] * R;
		}
		return L * R;
	}
} seg;

int main() {
	scanf("%d %d", &n, &q);
	scanf("%d %d", &x, &y);
	if (x > y) std::swap(x, y);
	const long long V[] = {0, y, x + y};
	const long long VV = 1LL * (x + y) * y;
	rep(i, n) scanf("%d", &a[i]);
	seg.init();
	while (q --) {
		int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		if (op == 1) {
			-- l;
			seg.update(l, a[l] = r);
		} else {
			-- l;
			matrix tr;
			rep(i, B) tr.va[0][i] = (db)(V[i]) / VV * a[l];
			tr = tr * seg.query(l + 1, r);
			db ans = -inf;
			rep(i, B) ans = std::max(ans, tr.va[0][i]);
			printf("%.30lf\n", ans);
		}
	}
	return 0;
}