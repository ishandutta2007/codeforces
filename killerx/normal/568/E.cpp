#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, a[mxn], b[mxn];
std::multiset <int> ib;
int L[mxn], R[mxn];
int S[mxn];
int dp[mxn], pr[mxn];

struct BIT {
	int vis[mxn << 1], tim;
	std::pair <int, int> ovo[mxn << 1];

	inline void init() { ++ tim; }

	inline void update(int x, std::pair <int, int> v) {
		for (; x < mxn << 1; x += x & -x) {
			if (vis[x] != tim) vis[x] = tim, ovo[x] = std::make_pair(-inf, -1);
			ovo[x] = std::max(ovo[x], v);
		}
	}

	inline std::pair <int, int> query(int x) {
		std::pair <int, int> ans = std::make_pair(-inf, -1);
		for (; x; x -= x & -x) {
			if (vis[x] != tim) continue;
			ans = std::max(ans, ovo[x]);
		}
		return ans;
	}
} s1, s2;

void conq(int l, int r) {
	if (l + 1 == r) return ;
	int m = (l + r) >> 1;
	conq(l, m);
	/*
	for (int i = m; i < r; ++ i) if (a[i] != -1) {
		for (int j = l; j < m; ++ j) if (a[j] != -1) {
			if (a[j] < a[i]) {
				int c1 = R[i] - L[j];
				int c2 = S[i] - S[j];
				if (dp[i] < dp[j] + 1 + std::min(c1, c2)) {
					dp[i] = dp[j] + 1 + std::min(c1, c2);
					pr[i] = j;
				}
			}
		}
	}
	*/
	s1.init(); s2.init();
	std::vector <std::pair <int, int> > vec;
	for (int i = l; i < r; ++ i) if (a[i] != -1) vec.push_back(std::make_pair(a[i], i));
	std::sort(vec.begin(), vec.end());
	// eprintf("[%d, %d)\n", l, r);
	rep(xx, vec.size()) {
		int i = vec[xx].second;
		// eprintf("%d\n", i);
		if (i < m) {
			s1.update(mxn - (L[i] - S[i]), std::make_pair(dp[i] + 1 - L[i], i));
			s2.update(mxn + (L[i] - S[i]), std::make_pair(dp[i] + 1 - S[i], i));
		} else {
			std::pair <int, int> p;
			p = s1.query(mxn - (R[i] - S[i]));
			if (R[i] + p.first > dp[i]) dp[i] = R[i] + p.first, pr[i] = p.second, assert(R[i] - L[pr[i]] <= S[i] - S[pr[i]]);
			p = s2.query(mxn + (R[i] - S[i]));
			if (S[i] + p.first > dp[i]) dp[i] = S[i] + p.first, pr[i] = p.second;
		}
	}
	conq(m, r);
}

void doit(int l, int r) {
	int las = a[l];
	for (int i = l + 1; i < r; ++ i) if (a[i] == -1) {
		std::multiset <int>::iterator it = ib.upper_bound(las);
		if (it == ib.end() || *it >= a[r]) break;
		a[i] = *it;
		ib.erase(it);
		las = a[i];
	}
}

int main() {
	scanf("%d", &n);
	a[0] = 0;
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	a[n + 1] = inf;
	n += 2;
	scanf("%d", &m);
	rep(i, m) scanf("%d", &b[i]), ib.insert(b[i]);
	std::sort(b, b + m);
	m = std::unique(b, b + m) - b;
	rep(i, n) {
		S[i + 1] = S[i] + (a[i] == -1);
		L[i] = std::upper_bound(b, b + m, a[i]) - b;
		R[i] = std::lower_bound(b, b + m, a[i]) - b;
	}
	dp[0] = 1;
	conq(0, n);
	// eprintf("%d\n", dp[n - 1] - 2);
	int u = n - 1;
	while (u) {
		doit(pr[u], u);
		u = pr[u];
	}
	rep(i, n) if (a[i] == -1) {
		a[i] = *ib.begin();
		ib.erase(ib.begin());
	}
	for (int i = 1; i <= n - 2; ++ i) printf("%d ", a[i]); printf("\n");
	return 0;
}