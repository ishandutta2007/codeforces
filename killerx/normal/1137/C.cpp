#include <bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long
#define pii pair <int, int>
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define PI acos(-1)
#define MOD 1000000007
#define MUL 19260817
#define EPS 1e-10
#define INF 1e9
#define LINF 1e18

template <typename T> inline void chkmin(T &x, T y) {if (y < x) x = y;}
template <typename T> inline void chkmax(T &x, T y) {if (y > x) x = y;}
template <typename T> inline T add(T x, T y) {return (x + y) % MOD;}
template <typename T> inline T mul(T x, T y) {return 1LL * x * y % MOD;}
template <typename T> inline T qp(T x, T n) {
	T ans = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

#ifndef DEBUG
const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)
#endif

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 1e5 + 1;
const int NN = N * 50;

struct Graph {
	int tot, head[NN], nxt[NN], to[NN];
	Graph() {tot = 0; memset(head, ~0, sizeof head);}
	void Add(int u, int v) {
		nxt[tot] = head[u];
		head[u] = tot;
		to[tot] = v;
		tot ++;
	}
};

int n, m, d;
//vector <int> g[NN], rg[NN], gg[NN];
Graph g, rg, gg;
bool use[NN];
int V[NN], Sz;
int vis[NN];
int scc[NN], cc;
int cnt[NN], lst[NN];
int dp[NN];
int stk[NN + NN];
int tp;
//int ql, qr;
//int que[NN];
//int deg[NN];
int ee[NN][2];
int id[NN], mm;

void dfs(int s) {
//	vis[u] = 1;
//	for (int e = g.head[u]; ~e; e = g.nxt[e]) {
//		int v = g.to[e];
//		if (!vis[v]) dfs(v);
//	}
//	V[-- Sz] = u;
	tp = 0;
	stk[tp ++] = s;
	while (tp) {
		int u = stk[-- tp];
		if (vis[u] == 2) continue;
		if (vis[u] == 1) {vis[u] = 2; V[-- Sz] = u; continue;}
		vis[u] = 1;
		stk[tp ++] = u;
		for (int e = g.head[u]; ~e; e = g.nxt[e]) {
			int v = g.to[e];
			if (!vis[v]) stk[tp ++] = v;
		}
	}
}

void rdfs(int s) {
//	scc[u] = cc;
//	rep(i, rg[u].size()) {
//		int v = rg[u][i];
//		if (!scc[v]) rdfs(v);
//	}
	tp = 0;
	stk[tp ++] = s;
	while (tp) {
		int u = stk[-- tp];
		scc[u] = cc;
		for (int e = rg.head[u]; ~e; e = rg.nxt[e]) {
			int v = rg.to[e];
			if (!scc[v]) stk[tp ++] = v;
		}
	}
}

//void Dfs(int s) {
//	tp = 0;
//	stk[tp ++] = s;
//	while (tp) {
//		int u = stk[-- tp];
//		vis[u] = 1;
//		for (int e = gg.head[u]; ~e; e = gg.nxt[e]) {
//			int v = gg.to[e];
//			deg[v] ++;
//			if (!vis[v]) stk[tp ++] = v;
//		}
//	}
//}

int DP(int s) {
//	if (~dp[u]) return dp[u];
//	dp[u] = 0;
//	for (int e = gg.head[u]; ~e; e = gg.nxt[e]) {
//		int v = gg.to[e];
//		chkmax(dp[u], DP(v));
//	}
//	dp[u] += cnt[u];
//	return dp[u];

//	que[qr ++] = s;
//	while (ql < qr) {
//		int u = que[ql ++];
//		for (int e = gg.head[u]; ~e; e = gg.nxt[e]){
//			int v = gg.to[e];
//			if (-- deg[v] == 0) que[qr ++] = v;
//		}
//	}
//	rep(i, qr) printf("%d ", que[i]); puts("");
//	for (int i = qr - 1; ~i; -- i) {
//		int u = que[i];
//		dp[u] = 0;
//		for (int e = gg.head[u]; ~e; e = gg.nxt[e]) chkmax(dp[u], dp[gg.to[e]]);
//		dp[u] += cnt[u];
//	}

	tp = 0;
	stk[tp ++] = s;
	while (tp) {
		int u = stk[-- tp];
		if (vis[u] == 1) {
			dp[u] = 0;
			for (int e = gg.head[u]; ~e; e = gg.nxt[e]) {
				int v = gg.to[e];
				chkmax(dp[u], dp[v]);
			}
			dp[u] += cnt[u];
			continue;
		}
		vis[u] = 1;
		stk[tp ++] = u;
		for (int e = gg.head[u]; ~e; e = gg.nxt[e]) {
			int v = gg.to[e];
			if (!vis[v]) stk[tp ++] = v;
		}
	}
	return dp[s];
}

int main() {
	n = read(), m = read(), d = read();
//	n = 1e5, m = 1e5 - 1, d = 50;
	rep(i, m) {
		int u = read() - 1, v = read() - 1;
//		int u = i, v = (i + 1) % n;
		rep(j, d) {
			g.Add(u * d + j, v * d + (j + 1) % d);
			rg.Add(v * d + (j + 1) % d, u * d + j);
		}
	}
	rep(i, n) {
		rep(j, d) {
			int c = getchar();
			while (isspace(c)) c = getchar();
//			int c = rand() % 2 + '0';
			c -= '0';
			use[i * d + j] = c;
		}
	}
	Sz = n * d;
	rep(i, n * d) if (!vis[i]) dfs(i);
	assert(!Sz);
	rep(i, n * d) if (!scc[V[i]]) cc ++, rdfs(V[i]);
	memset(lst, -1, sizeof lst);
	rep(i, n * d) if (use[i]) {
		if (lst[scc[i]] == i / d) continue;
		lst[scc[i]] = i / d;
		++ cnt[scc[i]];
	}
	rep(i, n * d) {
		for (int e = g.head[i]; ~e; e = g.nxt[e]) {
			int v = g.to[e];
			if (scc[i] != scc[v]) {
				ee[mm][0] = scc[i];
				ee[mm][1] = scc[v];
				id[mm] = mm;
				++ mm;
			}
//			if (scc[i] != scc[v]) {
//				assert(scc[i] < scc[v]);
//				gg.Add(scc[i], scc[v]);
//			}
		}
	}
	sort(id, id + mm, [&](int a, int b) {
		if (ee[a][0] != ee[b][0]) return ee[a][0] < ee[b][0];
		return ee[a][1] < ee[b][1];
	});
	rep(ii, mm) {
		int i = id[ii];
		if (!ii || (ee[i][0] != ee[id[ii - 1]][0] || ee[i][1] != ee[id[ii - 1]][1])) {
			gg.Add(ee[i][0], ee[i][1]);
		}
	}
	memset(dp, ~0, sizeof dp);
	memset(vis, 0, sizeof vis);
//	Dfs(scc[0]);
	printf("%d\n", DP(scc[0]));
	return 0;
}