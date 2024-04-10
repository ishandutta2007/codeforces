#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const int mxn = 2e5 + 5, mxlg = 18, mxq = 1e6 + 5;

struct fenwick {
	i64 s[mxn];
	fenwick() { memset(s, 0, sizeof(s)); }
	inline void update(int x, i64 v) { for (++ x; x < mxn; x += x & -x) s[x] += v; }
	inline i64 query(int x) { i64 ans = 0; for (++ x; x; x &= x - 1) ans += s[x]; return ans; }
} b0, b1, b2, b3;

int n, q, a[mxn], ia[mxn];
int ql[mxq << 2], qr[mxq << 2];
int id[mxq << 2];
i64 ans[mxq];
std::vector <int> factor[mxn];
int mx[mxlg][mxn], __lg[mxn];

inline int qry(int l, int r) {
	int k = __lg[r - l + 1];
	return a[mx[k][l]] > a[mx[k][r - (1 << k) + 1]] ? mx[k][l] : mx[k][r - (1 << k) + 1];
}

std::vector <std::pair <std::pair <int, int>, int> > vpnt;

inline void add(int x, int y, int v) {
	// eprintf("+ (%d, %d) %d\n", x, y, v);
	vpnt.push_back({{x, y}, v});
}

inline void prep(int l, int r) {
	if (l > r) return ;
	int p = qry(l, r);
	// eprintf("[%d, %d] %d\n", l, r, p);
	std::vector <std::pair <int, int> > rs;
	for (int s : factor[a[p]]) {
		int x = ia[s], y = ia[a[p] / s];
		if (x > y) std::swap(x, y);
		if (x < l || y > r) continue;
		if (y <= p) rs.push_back({x, p});
		else if (x >= p) rs.push_back({p, y});
		else rs.push_back({x, y});
	}
	std::sort(rs.begin(), rs.end(), [&] (std::pair <int, int> i, std::pair <int, int> j) {
		return i.first != j.first ? i.first < j.first : i.second > j.second;
	});
	std::vector <std::pair <int, int> > stk;
	for (auto pr : rs) {
		while (!stk.empty() && pr.second <= stk.back().second) stk.pop_back();
		stk.push_back(pr);
	}
	stk.swap(rs);
	int last = l;
	for (auto pr : rs) {
		// [last, pr.first], [pr.second, r]
		// eprintf("[%d, %d] - [%d, %d]\n", last, pr.first, pr.second, r);
		add(last, pr.second, +1);
		add(last, r + 1, -1);
		add(pr.first + 1, pr.second, -1);
		add(pr.first + 1, r + 1, +1);
		last = pr.first + 1;
	}
	prep(l, p - 1);
	prep(p + 1, r);
}

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &a[i]), ia[a[i]] = i;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n / i; ++ j)
			if (i != j) factor[i * j].push_back(i);
	rep(i, n) mx[0][i] = i;
	rep(j, mxlg - 1) rep(i, n - (1 << (j + 1)) + 1)
		mx[j + 1][i] = a[mx[j][i]] > a[mx[j][i + (1 << j)]] ? mx[j][i] : mx[j][i + (1 << j)];
	rep(i, n + 1) __lg[i] = i > 1 ? __lg[i >> 1] + 1 : 0;
	prep(0, n - 1);
	std::sort(vpnt.begin(), vpnt.end());
	rep(i, q) scanf("%d %d", &ql[i], &qr[i]), -- ql[i], -- qr[i];
	static int rl[mxq], rr[mxq];
	rep(i, q) rl[i] = ql[i], rr[i] = qr[i];
	rep(i, q) {
		ql[i << 2 | 0] = rr[i], qr[i << 2 | 0] = rr[i];
		ql[i << 2 | 1] = rl[i] - 1, qr[i << 2 | 1] = rr[i];
		ql[i << 2 | 2] = rr[i], qr[i << 2 | 2] = rl[i] - 1;
		ql[i << 2 | 3] = rl[i] - 1, qr[i << 2 | 3] = rl[i] - 1;
	}
	std::iota(id, id + (q << 2), 0);
	std::sort(id, id + (q << 2), [&] (int i, int j) {
		return ql[i] != ql[j] ? ql[i] < ql[j] : qr[i] < qr[j];
	});
	int ptr = 0;
	rep(_, q << 2) {
		int i = id[_];
		while (ptr < (int) vpnt.size() && vpnt[ptr].first.first <= ql[i]) {
			int x = vpnt[ptr].first.first;
			int y = vpnt[ptr].first.second;
			int v = vpnt[ptr].second;
			b0.update(y, v);
			b1.update(y, -1LL * y * v);
			b2.update(y, -1LL * x * v);
			b3.update(y, 1LL * x * y * v);
			++ ptr;
		}
		auto calc = [&] (int X, int Y) {
			i64 S = 0;
			S += 1LL * (X + 1) * (Y + 1) * b0.query(Y);
			S += 1LL * (X + 1) * b1.query(Y);
			S += 1LL * (Y + 1) * b2.query(Y);
			S += b3.query(Y);
			return S;
		};
		int X = ql[i], Y = qr[i];
		ans[i >> 2] += std::vector <int> ({1, -1, -1, 1})[i & 3] * calc(X, Y);
	}
	rep(i, q) printf("%lld\n", ans[i]);
	return 0;
}