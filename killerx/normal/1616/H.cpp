#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 150000 + 100, mxlg = 30, mod = 998244353;

int n, x;
int a[mxn];
int tot;
int go[mxn * mxlg][2];
int sz[mxn * mxlg];
int pw[mxn];

inline int solve(int u0, int u1, int b = mxlg - 1) {
	if (!u0 || !u1) return 0;
	if (b < 0) {
		if (u0 == u1) return (pw[sz[u0]] + mod - 1) % mod;
		else {
			int v0 = (pw[sz[u0]] + mod - 1) % mod;
			int v1 = (pw[sz[u1]] + mod - 1) % mod;
			return 1LL * v0 * v1 % mod;
		}
	}
	if (u0 == u1) {
		if (x >> b & 1) {
			int v0 = solve(go[u0][0], go[u0][1], b - 1);
			int v1 = (pw[sz[go[u0][0]]] + mod - 1) % mod;
			int v2 = (pw[sz[go[u0][1]]] + mod - 1) % mod;
			return (0LL + v0 + v1 + v2) % mod;
		} else {
			int v0 = solve(go[u0][0], go[u0][0], b - 1);
			int v1 = solve(go[u0][1], go[u0][1], b - 1);
			return (0LL + v0 + v1) % mod;
		}
	} else {
		if (x >> b & 1) {
			int v0 = solve(go[u0][0], go[u1][1], b - 1);
			int v1 = solve(go[u0][1], go[u1][0], b - 1);
			int v00 = (pw[sz[go[u0][0]]] + mod - 1) % mod;
			int v01 = (pw[sz[go[u0][1]]] + mod - 1) % mod;
			int v10 = (pw[sz[go[u1][0]]] + mod - 1) % mod;
			int v11 = (pw[sz[go[u1][1]]] + mod - 1) % mod;
			long long ans = 0;
			ans += 1LL * v01 * v11;
			ans += v1;
			ans += 1LL * v1 * v11;
			ans += v0;
			ans += 1LL * v00 * v10;
			ans += 1LL * v0 * v10;
			ans += 1LL * v0 * v01;
			ans += 1LL * v1 * v00;
			ans += 1LL * v0 * v1;
			return ans % mod;
		} else {
			int v0 = solve(go[u0][0], go[u1][0], b - 1);
			int v1 = solve(go[u0][1], go[u1][1], b - 1);
			return (0LL + v0 + v1) % mod;
		}
	}
}

int main() {
	rep(i, mxn) pw[i] = i ? 2LL * pw[i - 1] % mod : 1;
	scanf("%d %d", &n, &x);
	rep(i, n) scanf("%d", &a[i]);
	tot = 1;
	rep(i, n) {
		int u = 1;
		++ sz[u];
		for (int b = mxlg - 1; ~b; -- b) {
			int &v = go[u][a[i] >> b & 1];
			if (!v) v = ++ tot;
			u = v;
			++ sz[u];
		}
	}
	printf("%d\n", solve(1, 1));
	return 0;
}