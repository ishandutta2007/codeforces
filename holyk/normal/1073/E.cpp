#include <bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)


typedef long long ll;
#define int ll
const int P(998244353);
inline void inc(int &x, int y) { if ((x += y) >= P) x -= P; }

int k, a[22], pw10[22];
int f[22][1033][2][2], g[22][1033][2][2];
int dfs(int p, int s, bool lim, bool lead) {
	int &ans = g[p][s][lim][lead];
	if (~ans) return ans;
	if (__builtin_popcount(s) > k) 
		return f[p][s][lim][lead] = ans = 0;
	if (!p) return f[p][s][lim][lead] = 1, ans = 0;
	f[p][s][lim][lead] = ans = 0;
	int up = lim ? a[p] : 9;
	REP(i, 0, up) {
		int to = (s >> i & 1 ^ 1) && (i || !lead) ? s | 1 << i : s;
		int v = dfs(p - 1, to, lim && i == up, lead && i == 0);
		ans = (ans + v + 1ll * i * pw10[p - 1] % P * f[p - 1][to][lim && i == up][lead && i == 0]) % P;
		inc(f[p][s][lim][lead], f[p - 1][to][lim && i == up][lead && i == 0]);
	}
	return ans;
}
int solve(ll x) {
	if (!x) return 0;
	for (a[0] = 0; x; x /= 10) a[++a[0]] = x % 10;
	memset(g, -1, sizeof g);
	return dfs(a[0], 0, 1, 1);
}
signed main() {
	pw10[0] = 1;
	REP(i, 1, 19) pw10[i] = 10ll * pw10[i - 1] % P;
	ll l, r;
	std::cin >> l >> r >> k;
	std::cout << (solve(r) - solve(l - 1) + P) % P;
	return 0;
}