#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const ll inf = 1LL << 60;

int n, m;
int a[10], b[10], c[10][10];
ll dp[10][10][5][15625];

inline int encode(int x[]) {
	int ans = 0;
	rep(i, m) (ans *= (b[i] + 1)) += x[i];
	return ans;
}

ll DP(int u, int v, int ulft, int x[]) {
	if (v == m) return ulft == 0 ? DP(u + 1, 0, a[u + 1], x) : inf;
	if (u == n) return 0;
	int S = encode(x);
	ll &ans = dp[u][v][ulft][S];
	if (ans != -1) return ans;
	ans = DP(u, v + 1, ulft, x);
	for (int use = 0; use <= x[v] && use <= ulft; ++ use) {
		x[v] -= use;
		ans = std::min(ans, DP(u, v + 1, ulft - use, x) + c[u][v]);
		x[v] += use;
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, m) scanf("%d", &b[i]);
	rep(i, n) rep(j, m) scanf("%d", &c[i][j]);
	int sa = 0, sb = 0;
	rep(i, n) sa += a[i];
	rep(i, m) sb += b[i];
	if (sa > sb) {
		printf("%d\n", -1);
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	int nb[10];
	rep(i, m) nb[i] = b[i];
	printf("%lld\n", DP(0, 0, a[0], nb));
	return 0;
}