#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5;
int n, a[mxn];
long long ans = 0;

struct Map {
	static const int shift = mxn << 1;
	int a[shift << 1], vis[shift << 1], tim;

	inline void clear() { ++ tim; }
	inline void visit(int x) { if (vis[x] < tim) vis[x] = tim, a[x] = 0; }

	inline int &operator [] (int x) { x += shift; visit(x); return a[x]; }
} mp;

int mn[mxn], mx[mxn];
std::vector <std::pair <int, int> > qry[mxn];

void conq(int l, int r) {
	if (l + 1 == r) { ++ ans; return ; }
	int mid = (l + r) >> 1;
	conq(l, mid); conq(mid, r);
	for (int i = mid - 1; i >= l; -- i) {
		mn[i] = std::min(i + 1 < mid ? mn[i + 1] : n, a[i]);
		mx[i] = std::max(i + 1 < mid ? mx[i + 1] : 0, a[i]);
	}
	for (int i = mid; i < r; ++ i) {
		mn[i] = std::min(i - 1 >= mid ? mn[i - 1] : n, a[i]);
		mx[i] = std::max(i - 1 >= mid ? mx[i - 1] : 0, a[i]);
	}
	// LL
	for (int i = mid; i < r; ++ i) qry[i].clear();
	for (int i = mid - 1, j0 = mid, j1 = mid; i >= l; -- i) {
		while (j0 < r && mx[j0] < mx[i]) ++ j0;
		while (j1 < r && mn[j1] > mn[i]) ++ j1;
		if (std::min(j0, j1) - 1 >= mid)
			qry[std::min(j0, j1) - 1].emplace_back(mx[i] - mn[i] - (mid - i), 1);
	}
	mp.clear();
	for (int i = mid; i < r; ++ i) {
		++ mp[i - mid];
		for (auto pr : qry[i]) ans += pr.second * mp[pr.first];
	}
	// RR
	for (int i = l; i < mid; ++ i) qry[i].clear();
	for (int i = mid, j0 = mid - 1, j1 = mid - 1; i < r; ++ i) {
		while (j0 >= l && mx[j0] < mx[i]) -- j0;
		while (j1 >= l && mn[j1] > mn[i]) -- j1;
		if (std::max(j0, j1) + 1 < mid)
			qry[std::max(j0, j1) + 1].emplace_back(mx[i] - mn[i] - (i - mid), 1);
	}
	mp.clear();
	for (int i = mid - 1; i >= l; -- i) {
		++ mp[mid - i];
		for (auto pr : qry[i]) ans += pr.second * mp[pr.first];
	}
	// LR
	for (int i = mid; i < r; ++ i) qry[i].clear();
	for (int i = mid - 1, j0 = mid, j1 = mid; i >= l; -- i) {
		while (j0 < r && mx[j0] < mx[i]) ++ j0;
		while (j1 < r && mn[j1] > mn[i]) ++ j1;
		if (j0 < j1) {
			if (j0 - 1 >= mid) qry[j0 - 1].emplace_back(mn[i] - i, -1);
			qry[j1 - 1].emplace_back(mn[i] - i, +1);
		}
	}
	mp.clear();
	for (int i = mid; i < r; ++ i) {
		++ mp[mx[i] - i];
		for (auto pr : qry[i]) ans += pr.second * mp[pr.first];
	}
	// RL
	for (int i = l; i < mid; ++ i) qry[i].clear();
	for (int i = mid, j0 = mid - 1, j1 = mid - 1; i < r; ++ i) {
		while (j0 >= l && mx[j0] < mx[i]) -- j0;
		while (j1 >= l && mn[j1] > mn[i]) -- j1;
		if (j0 > j1) {
			if (j0 + 1 < mid) qry[j0 + 1].emplace_back(i + mn[i], -1);
			qry[j1 + 1].emplace_back(i + mn[i], +1);
		}
	}
	mp.clear();
	for (int i = mid - 1; i >= l; -- i) {
		++ mp[i + mx[i]];
		for (auto pr : qry[i]) ans += pr.second * mp[pr.first];
	}
}

long long solve() {
	ans = 0;
	conq(0, n);
	return ans;
}

long long brute() {
	int ans = 0;
	for (int i = 0; i < n; ++ i) {
		int mn = n, mx = 0;
		for (int j = i; j < n; ++ j) {
			mn = std::min(mn, a[j]);
			mx = std::max(mx, a[j]);
			ans += mx - mn == j - i;
		}
	}
	return ans;
}

std::random_device rd;
std::mt19937 rng(rd());

int rand(int l, int r) { return std::uniform_int_distribution <int> (l, r)(rng); }

int main() {
	scanf("%d", &n);
	rep(i, n) {
		int r, c;
		scanf("%d %d", &r, &c);
		-- r, -- c;
		a[r] = c;
	}
	printf("%lld\n", solve());
	return 0;
	/*
	n = 6;
	a[0] = 1; a[1] = 4; a[2] = 0; a[3] = 3; a[4] = 2; a[5] = 5;
	eprintf("%lld\n", solve());
	eprintf("%lld\n", brute());
	return 0;
	while (true) {
		n = rand(1, 100);
		rep(i, n) a[i] = i;
		rep(i, n) std::swap(a[i], a[rand(0, i)]);
		rep(i, n) printf("%d ", a[i]);
		printf("\n");
		assert(solve() == brute());
	}
	*/
	return 0;
}