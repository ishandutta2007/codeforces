#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const int mxn = 2e5 + 5;
int n;
int L[mxn], R[mxn];

int c_lef[mxn], c_rig[mxn], c_cov[mxn], c_icov[mxn], deg[mxn];

struct fenwick_tree {
	i64 s[mxn];

	inline void clear() { memset(s, 0, sizeof(s)); }
	inline void update(int x, i64 v) { for (++ x; x < mxn; x += x & -x) s[x] += v; }
	inline i64 query(int x) { i64 ans = 0; for (++ x; x; x -= x & -x) ans += s[x]; return ans; }
	inline i64 query(int l, int r) { return query(r - 1) - query(l - 1); }
} bit;

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &L[i], &R[i]), -- L[i], -- R[i];
	rep(i, n) if (L[i] > R[i]) std::swap(L[i], R[i]);
	std::vector <int> id(n);
	std::iota(id.begin(), id.end(), 0);
	i64 cyc = 1LL * n * (n - 1) * (n - 2) / 6;
	i64 par = 0;
	bit.clear();
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return L[i] < L[j]; });
	for (int i : id) {
		c_lef[i] = bit.query(0, L[i]);
		bit.update(R[i], 1);
	}
	bit.clear();
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return R[i] > R[j]; });
	for (int i : id) {
		c_rig[i] = bit.query(R[i] + 1, 2 * n);
		bit.update(L[i], 1);
	}
	bit.clear();
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return L[i] > L[j]; });
	for (int i : id) {
		c_cov[i] = bit.query(0, R[i]);
		bit.update(R[i], 1);
	}
	bit.clear();
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return L[i] < L[j]; });
	for (int i : id) {
		c_icov[i] = bit.query(R[i], 2 * n);
		bit.update(R[i], 1);
	}
	bit.clear();
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return L[i] > L[j]; });
	for (int i : id) {
		par += bit.query(0, R[i]);
		bit.update(R[i], c_cov[i]);
	}
	bit.clear();
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return L[i] < L[j]; });
	for (int i : id) {
		par += bit.query(0, L[i]);
		bit.update(R[i], c_cov[i]);
	}
	bit.clear();
	std::sort(id.begin(), id.end(), [&] (int i, int j) { return R[i] > R[j]; });
	for (int i : id) {
		par += bit.query(R[i] + 1, 2 * n);
		bit.update(L[i], c_cov[i]);
	}
	rep(i, n) deg[i] = n - 1 - c_lef[i] - c_rig[i] - c_cov[i] - c_icov[i];
	// rep(i, n) eprintf("%d %d %d %d %d\n", c_lef[i], c_rig[i], c_cov[i], c_icov[i], deg[i]);
	i64 temp = 0;
	rep(i, n) temp += 1LL * deg[i] * (n - 1 - deg[i]);
	temp /= 2;
	cyc -= temp;
	// eprintf("%lld\n", cyc);
	printf("%lld\n", cyc - par);
	return 0;
}

/*
3-cycle - 3-parallel

3-cycle = comb(n, 3) - \sum_i deg_i (n - 1 - deg_i)

3-parallel = [[[]]] + [[]][] + [][[]]
*/