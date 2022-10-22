#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, m, K;
bool adj[15][15];

std::set <std::vector <int> > ans;

int p2[15][2];
int col[15];

void dfs1(int id, int max) {
	if (id == n / 2) {
		static int last[15];
		rep(i, n) last[i] = -1;
		int cnt = 0;
		rep(i, n) if (last[col[i]] == -1) last[col[i]] = cnt ++;
		std::vector <int> ovo(n);
		rep(i, n) ovo[i] = last[col[i]];
		ans.insert(ovo);
		return ;
	}
	rep(c, max + 1) {
		col[p2[id][0]] = col[p2[id][1]] = c;
		dfs1(id + 1, std::max(c + 1, max));
	}
}

bool check() {
	static bool dp[1 << 6][10];
	memset(dp, 0, sizeof(dp));
	rep(i, n / 2) if (adj[p2[i][0]][p2[i][1]]) dp[1 << i][i] = true;
	rep(mask, 1 << (n / 2)) rep(cur, n / 2) if (mask >> cur & 1) {
		int nmask = mask ^ 1 << cur;
		if (nmask) {
			rep(last, n / 2) if (nmask >> last & 1) {
				if ((adj[p2[cur][0]][p2[last][0]] && adj[p2[last][1]][p2[cur][1]]) ||
					(adj[p2[cur][0]][p2[last][1]] && adj[p2[last][0]][p2[cur][1]])) {
					dp[mask][cur] |= dp[nmask][last];
				}
			}
		}
	}
	rep(i, n / 2) if (dp[(1 << (n / 2)) - 1][i]) return true;
	return false;
}

void dfs0(int mask, int id) {
	if (!mask) {
		rep(i, n / 2) col[p2[i][0]] = col[p2[i][1]] = i;
		if (check()) dfs1(0, 0);
		return ;
	}
	int u = __builtin_ctz(mask);
	int nmask = mask ^ 1 << u;
	rep(v, n) if (nmask >> v & 1) {
		p2[id][0] = u, p2[id][1] = v;
		dfs0(nmask ^ 1 << v, id + 1);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &K);
	rep(i, m) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[u][v] = adj[v][u] = true;
	}
	dfs0((1 << n) - 1, 0);
	static int f[15];
	rep(i, n + 1) f[i] = 0;
	for (auto s : ans) {
		int mx = 0;
		rep(i, s.size()) mx = std::max(mx, s[i] + 1);
		++ f[mx];
	}
	long long ans = 0;
	rep(i, n + 1) if (f[i]) {
		long long cur = 1;
		for (int x = K; x > K - i; -- x) cur = 1LL * cur * x;
		ans += cur * f[i];
	}
	printf("%lld\n", ans);
	return 0;
}