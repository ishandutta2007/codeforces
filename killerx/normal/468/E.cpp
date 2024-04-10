#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5, mxm = 55;
const int mod = 1e9 + 7;

inline void uadd(int &x, int y) {
	x += y - mod;
	x += x >> 31 & mod;
}

int m;
int id[mxn * 2];
std::vector <int> L, R;
std::vector <std::pair <std::pair <int, int>, int> > E;

namespace sub1 {
;

int dp[1 << 18 | 5];
inline void solve(int f[]) {
	static std::vector <std::pair <int, int> > adj[mxm];
	rep(i, L.size()) adj[i].clear();
	rep(i, E.size()) adj[id[E[i].first.first]].push_back({id[E[i].first.second], E[i].second});
	rep(S, 1 << (int) R.size()) dp[S] = 0;
	dp[0] = 1;
	rep(i, L.size()) {
		static int ndp[1 << 18 | 5];
		rep(S, 1 << (int) R.size()) ndp[S] = 0;
		rep(S, 1 << (int) R.size()) if (dp[S]) {
			uadd(ndp[S], dp[S]);
			rep(_, adj[i].size()) {
				int j = adj[i][_].first, w = adj[i][_].second;
				if (!(S >> j & 1)) uadd(ndp[S | 1 << j], 1LL * dp[S] * w % mod);
			}
		}
		rep(S, 1 << (int) R.size()) dp[S] = ndp[S];
	}
	rep(S, 1 << (int) R.size()) uadd(f[__builtin_popcount(S)], dp[S]);
}

} // sub1

namespace sub2 {
;

bool vis[mxm * 2];
std::vector <std::pair <int, int> > adj[mxm * 2];
std::vector <std::pair <std::pair <int, int>, int> > ntE;
bool can[mxm * 2];
int dp[mxm * 2][2][mxm];
inline void dfs(int u, int p) {
	vis[u] = 1;
	rep(i, adj[u].size()) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (v == p) continue;
		if (vis[v]) {
			if (u < v) ntE.push_back({{u, v}, w});
			continue;
		}
		dfs(v, u);
	}
}
inline void dfs_dp(int u) {
	vis[u] = 1;
	memset(dp[u], 0, sizeof(dp[u]));
	dp[u][0][0] = 1;
	rep(i, adj[u].size()) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (vis[v]) continue;
		dfs_dp(v);
		int nf[2][mxm];
		memset(nf, 0, sizeof(nf));
		rep(fu, 2) rep(eu, m + 1) rep(fv, 2) rep(ev, m + 1) {
			if (dp[u][fu][eu] && dp[v][fv][ev]) {
				uadd(nf[fu][eu + ev], 1LL * dp[u][fu][eu] * dp[v][fv][ev] % mod);
				if (can[u] && can[v] && !fu && !fv)
					uadd(nf[1][eu + ev + 1], 1LL * dp[u][fu][eu] * dp[v][fv][ev] % mod * w % mod);
			}
		}
		memcpy(dp[u], nf, sizeof(nf));
	}
}
inline void solve(int f[]) {
	rep(i, L.size() + R.size()) adj[i].clear();
	rep(i, E.size()) {
		adj[id[E[i].first.first]].push_back({id[E[i].first.second] + L.size(), E[i].second});
		adj[id[E[i].first.second] + L.size()].push_back({id[E[i].first.first], E[i].second});
	}
	rep(i, L.size() + R.size()) vis[i] = 0;
	ntE.clear();
	dfs(0, -1);
	rep(mask, 1 << (int) ntE.size()) {
		int z = 1;
		rep(i, L.size() + R.size()) can[i] = 1;
		bool ok = 1;
		rep(i, ntE.size()) if (mask >> i & 1) {
			z = 1LL * z * ntE[i].second % mod;
			if (!can[ntE[i].first.first]) ok = 0;
			if (!can[ntE[i].first.second]) ok = 0;
			can[ntE[i].first.first] = can[ntE[i].first.second] = 0;
		}
		if (!ok) continue;
		rep(i, L.size() + R.size()) vis[i] = 0;
		dfs_dp(0);
		int bE = int(__builtin_popcount(mask));
		rep(i, m + 1) {
			if (dp[0][0][i]) uadd(f[i + bE], 1LL * z * dp[0][0][i] % mod);
			if (dp[0][1][i]) uadd(f[i + bE], 1LL * z * dp[0][1][i] % mod);
		}
	}
}

} // sub2

inline void solve(int f[]) {
	rep(i, mxm) f[i] = 0;
	if ((int) L.size() < (int) R.size()) {
		std::swap(L, R);
		rep(i, E.size()) std::swap(E[i].first.first, E[i].first.second);
	}
	rep(i, L.size()) id[L[i]] = i;
	rep(i, R.size()) id[R[i]] = i;
	int lsz = (int) L.size(), rsz = (int) R.size(), esz = (int) E.size();
	if (rsz <= 18)
		sub1::solve(f);
	else
		sub2::solve(f);
	/*
	eprintf("L: "); rep(i, L.size()) eprintf("%d ", L[i] + 1); eprintf("\n");
	eprintf("R: "); rep(i, R.size()) eprintf("%d ", R[i] + 1); eprintf("\n");
	rep(i, E.size()) eprintf("%d %d %d\n", E[i].first.first + 1, E[i].first.second + 1, E[i].second);
	rep(i, m + 1) eprintf("%d ", f[i]); eprintf("\n");
	eprintf("\n");
	*/
}

int n;
std::vector <std::pair <int, int> > adj[mxn * 2];
bool vis[mxn * 2];

inline void dfs(int u) {
	vis[u] = 1;
	if (u < n) L.push_back(u);
	else R.push_back(u);
	rep(i, adj[u].size()) {
		int v = adj[u][i].first;
		int w = adj[u][i].second;
		if (u < v) E.push_back({{u, v}, w});
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	static int fac[mxn];
	rep(i, mxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
	scanf("%d %d", &n, &m);
	rep(i, m) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v, w = (w + mod - 1) % mod;
		adj[u].push_back({v + n, w});
		adj[v + n].push_back({u, w});
	}
	static int f[mxm];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	rep(i, n * 2) if (!vis[i]) {
		L.clear(), R.clear(), E.clear(), dfs(i);
		static int g[mxm];
		solve(g);
		static int nf[mxm];
		memset(nf, 0, sizeof(nf));
		rep(a, m + 1) rep(b, m + 1) if (f[a] && g[b])
			nf[a + b] = (nf[a + b] + 1LL * f[a] * g[b]) % mod;
		memcpy(f, nf, sizeof(nf));
	}
	int ans = 0;
	rep(i, m + 1) if (f[i]) ans = (ans + 1LL * fac[n - i] * f[i]) % mod;
	printf("%d\n", ans);
	return 0;
}