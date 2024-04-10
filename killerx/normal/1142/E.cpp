#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

// #define RANDOM

const int mxn = 1e5 + 5;

int n, m;
std::vector <int> adj[mxn], radj[mxn];
int cc[mxn], c;
int indeg[mxn];
std::vector <int> vscc[mxn];
int ptr[mxn];
int que[mxn * 2], ql, qr;

void add_edge(int u, int v) {
	// eprintf("edge %d %d\n", u + 1, v + 1);
	adj[u].push_back(v);
	radj[v].push_back(u);
}

namespace SCC {
bool vis[mxn];
std::vector <int> vec;

void dfs(int u) {
	vis[u] = 1;
	for (int v : adj[u]) if (!vis[v]) dfs(v);
	vec.push_back(u);
}

void rdfs(int u) {
	cc[u] = c;
	for (int v : radj[u]) if (!~cc[v]) rdfs(v);
}

void solve() {
	rep(i, n) if (!vis[i]) dfs(i);
	std::reverse(vec.begin(), vec.end());
	rep(i, n) cc[i] = -1;
	for (int u : vec) if (!~cc[u]) rdfs(u), ++ c;
	rep(u, n) for (int v : adj[u]) if (cc[u] != cc[v]) ++ indeg[cc[v]];
}
}

#ifdef RANDOM
std::mt19937 RNG((unsigned long long) new char);
inline int rng(int l, int r) { return std::uniform_int_distribution <int> (l, r)(RNG); }

int CNT = 0;
bool hav[305][305];
std::vector <int> gadj[305];

inline void init() {
	n = rng(1, 100);
	std::vector <int> qwq;
	rep(i, n) rep(j, i) qwq.push_back(i * n + j);
	rep(i, qwq.size()) std::swap(qwq[i], qwq[rng(0, i)]);
	m = rng(0, n);
	rep(i, qwq.size()) {
		int u = qwq[i] / n, v = qwq[i] % n;
		if (rng(0, 1)) std::swap(u, v);
		if (i < m) add_edge(u, v);
		else hav[u][v] = 1, gadj[u].push_back(v);
	}
	eprintf("%d %d %d\n", n, m, (int) qwq.size());
}

inline bool query(int u, int v) {
	++ CNT;
	return hav[u][v];
}

bool vis[2][305];

void dfs(int u, bool vis[], std::vector <int> adj[]) {
	vis[u] = 1;
	for (int v : adj[u]) if (!vis[v]) dfs(v, vis, adj);
}

inline void answer(int x) {
	dfs(x, vis[0], gadj);
	dfs(x, vis[1], adj);
	rep(i, n) if (!vis[0][i] && !vis[1][i]) {
		eprintf("wrong answer.\n"); return ;
	}
	eprintf("accepted.\n");
	eprintf("CNT = %d\n", CNT);
	exit(0);
}
#else
inline void init() {
	scanf("%d %d", &n, &m);
	rep(i, m) {
		int u, v; scanf("%d %d", &u, &v); -- u, -- v;
		add_edge(u, v);
	}
}

inline bool query(int u, int v) {
	printf("? %d %d\n", u + 1, v + 1);
	fflush(stdout);
	int ans; scanf("%d", &ans);
	return ans;
}

inline void answer(int x) {
	printf("! %d\n", x + 1);
	fflush(stdout);
	exit(0);
}
#endif

int main() {
	init();
	SCC::solve();
	// rep(i, n) eprintf("%d ", cc[i]); eprintf("\n");
	rep(i, n) vscc[cc[i]].push_back(i);
	rep(i, c) if (indeg[i] == 0) que[qr ++] = i;
	while (qr - ql > 1) {
		int u = que[ql ++], v = que[ql ++];
		u = vscc[u][ptr[u]], v = vscc[v][ptr[v]];
		if (!query(u, v)) std::swap(u, v);
		// u -> v
		que[qr ++] = cc[u];
		++ ptr[cc[v]];
		if (ptr[cc[v]] == vscc[cc[v]].size()) {
			for (int x : vscc[cc[v]]) for (int y : adj[x]) if (cc[x] != cc[y]) {
				if (-- indeg[cc[y]] == 0) que[qr ++] = cc[y];
			}
		}
		else que[qr ++] = cc[v];
	}
	answer(vscc[que[ql]][ptr[que[ql]]]);
	return 0;
}