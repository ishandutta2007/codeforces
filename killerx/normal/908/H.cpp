#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef unsigned long long ull;

struct UF {
	int fa[55];

	UF() { rep(i, 55) fa[i] = i; }

	int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
};

int n;
char ch[55][55];
UF uf;
int siz[55];
bool adj[55][55];
ull dp[1 << 23];
ull dp0[1 << 23];

int solve(int n) {
	dp[0] = 1;
	for (int mask = 1; mask < (1 << n); ++ mask) {
		int x = __builtin_ctz(mask & -mask);
		int nmask = mask ^ 1 << x;
		dp[mask] = dp[nmask];
		for (int y = x + 1; y < n; ++ y) if (mask >> y & 1)
			if (adj[x][y]) dp[mask] = 0;
	}
	rep(i, n) rep(mask, 1 << n) if (!(mask >> i & 1))
		dp[mask | 1 << i] += dp[mask];
	rep(mask, 1 << n)
		dp0[mask] = 1;
	for (int c = 0; c <= n; ++ c) {
		ull ans = 0;
		rep(mask, 1 << n) {
			int c = n - __builtin_popcount(mask);
			ull cur = c & 1 ? -dp0[mask] : dp0[mask];
			ans += cur;
			dp0[mask] = dp0[mask] * dp[mask];
		}
		if (ans) return c;
	}
	return 0x3f3f3f3f;
}

int main() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%s", ch[i]);
		rep(j, n) if (ch[i][j] == 'A') {
			uf.fa[uf.find(i)] = uf.find(j);
		}
	}
	rep(i, n) {
		siz[uf.find(i)] ++;
	}
	std::vector <int> vec;
	rep(i, n) if (i == uf.find(i) && siz[i] > 1) vec.push_back(i);
	rep(i, n) {
		rep(j, n) if (ch[i][j] == 'X') {
			if (uf.find(i) == uf.find(j)) {
				printf("-1\n");
				return 0;
			}
			int ni = uf.find(i);
			if (siz[ni] == 1) continue;
			ni = lower_bound(vec.begin(), vec.end(), ni) - vec.begin();
			int nj = uf.find(j);
			if (siz[nj] == 1) continue;
			nj = lower_bound(vec.begin(), vec.end(), nj) - vec.begin();
			adj[ni][nj] = adj[nj][ni] = 1;
		}
	}
	int ans = n - 1 + solve(vec.size());
	printf("%d\n", ans);
	return 0;
}