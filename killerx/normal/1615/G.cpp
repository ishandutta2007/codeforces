#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct Blossom {
	static const int mxn = 605 * 2;

	int n, tot;
	bool adj[mxn][mxn];
	int from[mxn][mxn];

	void init(int _n) {
		n = _n;
		memset(adj, 0, sizeof(adj));
	}

	inline void add_edge(int u, int v) {
		adj[u][v] = adj[v][u] = true;
	}

	int match[mxn];

	inline void M(int u, int v) {
		match[u] = v;
		match[v] = u;
	}

	int fid[mxn];
	std::vector <int> cyc[mxn];

	int find(int x, int v) {
		rep(i, cyc[x].size()) if (cyc[x][i] == v) return i;
		return -1;
	}

	void lift(int x) {
		if (~match[x]) {
			int s = from[x][match[x]];
			int p = find(x, s);
			if (~match[s]) {
				int q = find(x, match[s]);
				match[s] = -1;
				int d = (q + cyc[x].size() - p) % cyc[x].size();
				for (int i = p; ~match[cyc[x][(i + d) % cyc[x].size()]]; ) {
					int j = (i + d) % cyc[x].size();
					int k = (j + d) % cyc[x].size();
					M(cyc[x][j], cyc[x][k]);
					i = k;
				}
			}
			M(s, match[x]);
			match[x] = -1;
		}
		fid[x] = -2;
		for (int z : cyc[x]) fid[z] = -1;
		rep(u, tot) if (adj[x][u]) adj[x][u] = adj[u][x] = false, from[x][u] = from[u][x] = -1;
	}

	bool argument() {
		static bool vis[mxn], col[mxn];
		static int rt[mxn], dep[mxn];
		rep(i, tot) if (!~fid[i]) vis[i] = false, col[i] = 0, rt[i] = -1, dep[i] = -1;
		static int que[mxn];
		int ql = 0, qr = 0;
		rep(i, tot) if (!~fid[i] && !~match[i]) {
			que[qr ++] = i, vis[i] = true, col[i] = 0, rt[i] = i, dep[i] = 0;
		}
		static int pr[mxn];
		while (ql < qr) {
			int u = que[ql ++];
			rep(v, tot) if (!~fid[v] && adj[u][v]) {
				if (!vis[v]) {
					int w = match[v];
					que[qr ++] = w;
					vis[v] = vis[w] = true;
					col[v] = col[u] ^ 1;
					col[w] = col[v] ^ 1;
					pr[v] = u; dep[v] = dep[u] + 1;
					pr[w] = v; dep[w] = dep[v] + 1;
					rt[v] = rt[w] = rt[u];
				} else if (!col[v]) {
					if (rt[u] != rt[v]) {
						M(u, v);
						for (int x = u; x != rt[x]; x = pr[pr[x]]) M(pr[x], pr[pr[x]]);
						for (int x = v; x != rt[x]; x = pr[pr[x]]) M(pr[x], pr[pr[x]]);
						return true;
					} else {
						// rep(i, tot) eprintf("%d ", match[i] + 1);
						// eprintf("\n");
						int x = tot ++;
						{
							std::vector <int> vl, vr;
							int a, b;
							for (a = u, b = v; a != b; ) {
								if (dep[a] > dep[b]) vl.push_back(a), a = pr[a];
								else vr.push_back(b), b = pr[b];
							}
							cyc[x].insert(cyc[x].end(), vl.begin(), vl.end());
							cyc[x].push_back(a);
							cyc[x].insert(cyc[x].end(), vr.rbegin(), vr.rend());
							// eprintf("\t");
							// for (int z : cyc[x]) eprintf("%d ", z + 1);
							// eprintf("\n");
							if (~match[a] && !~fid[match[a]]) {
								M(match[a], x);
								match[a] = -1;
							}
						}
						for (int a : cyc[x]) fid[a] = x;
						for (int a : cyc[x]) rep(b, tot) if (!~fid[b] && adj[a][b])
							adj[x][b] = adj[b][x] = 1, from[x][b] = from[b][x] = a;
						bool res = argument();
						lift(x);
						return res;
					}
				}
			}
		}
		return false;
	}

	void find_matching() {
		memset(from, -1, sizeof(from));
		memset(match, -1, sizeof(match));
		memset(fid, -1, sizeof(fid));
		tot = n;
		while (argument()) {
			while (tot > n) {
				-- tot;
				cyc[tot].clear();
				match[tot] = -1;
				fid[tot] = -1;
			}
		}
	}
} solver;

const int mxn = 3e5 + 5, mxa = 605;

int n;
int a[mxn];

bool adj[mxa][mxa];
std::vector <std::pair <int, int> > G[mxa];

inline void add_edge(int u, int v, int i) {
	adj[u][v] = adj[v][u] = true;
	G[u].push_back({v, i});
	G[v].push_back({u, i});
}

bool vis[mxa];
bool istree[mxa];
int c[mxa], cc;

inline void dfs0(int u, int pi = -1) {
	c[u] = cc;
	vis[u] = true;
	rep(i, G[u].size()) {
		int v = G[u][i].first;
		if (!vis[v]) dfs0(v, G[u][i].second);
		else if (G[u][i].second != pi) istree[cc] = false;
	}
}

int ovo[mxa];
bool done[mxa];

std::pair <int, int> dir[mxn];

void dfs_tree(int u) {
	done[u] = true;
	rep(i, G[u].size()) {
		int v = G[u][i].first;
		int _ = G[u][i].second;
		if (!done[v]) {
			dir[_] = {u, v};
			dfs_tree(v);
		}
	}
}

void dfs_ntree(int u, int p = -1, bool found = false) {
	static int fa[mxn], fai[mxn];
	fa[u] = p;
	done[u] = true;
	rep(i, G[u].size()) {
		int v = G[u][i].first;
		int _ = G[u][i].second;
		if (!done[v]) {
			fai[v] = i;
			dfs_ntree(v, u, found);
			dir[_] = {u, v};
		} else {
			if (!found) {
				found = true;
				dir[_] = {v, u};
				for (int x = u; ~x; x = fa[x]) {
					if (~fa[x]) dir[fai[x]] = {x, fa[x]};
				}
			}
		}
	}
}

bool ok[mxa];

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	std::vector <std::pair <int, int> > gg;
	rep(i, n) if (a[i] == 0) {
		int j;
		for (j = i; a[j] == 0 && j < n; ++ j);
		if (i == 0) { if ((j - i) % 2 == 1) a[j - 1] = j < n ? a[j] : 1; }
		else if (j == n) { if ((j - i) % 2 == 1) a[i] = i ? a[i - 1] : 1; }
		else gg.push_back({i, j});
		i = j;
	}
	rep(i, n - 1) if (a[i] && a[i] == a[i + 1]) add_edge(a[i], a[i + 1], n), ok[a[i]] = true;
	for (auto [l, r] : gg) if ((r - l) % 2 == 1) add_edge(a[l - 1], a[r], l);
	rep(i, mxa) if (!vis[i]) {
		istree[cc] = true;
		dfs0(i);
		++ cc;
	}
	solver.init(cc);
	for (auto [l, r] : gg) if ((r - l) % 2 == 0) {
		if (c[a[l - 1]] == c[a[r]]) continue;
		if (istree[c[a[l - 1]]] && istree[c[a[r]]])
			solver.add_edge(c[a[l - 1]], c[a[r]]);
	}
	solver.find_matching();
	rep(i, mxa) ovo[i] = -1;
	for (auto [l, r] : gg) if ((r - l) % 2 == 0 && solver.match[c[a[l - 1]]] == c[a[r]]) {
		if (!ok[a[l - 1]] && !ok[a[r]]) {
			ovo[c[a[l - 1]]] = a[l - 1];
			ovo[c[a[r]]] = a[r];
			a[l] = a[l - 1], a[r - 1] = a[r];
			ok[a[l]] = ok[a[r]] = true;
		}
	}
	rep(u, mxa) if (!done[u]) {
		if (~ovo[c[u]]) {
			dfs_tree(ovo[c[u]]);
		} else {
			if (istree[c[u]]) dfs_tree(u);
			else dfs_ntree(u);
		}
	}
	for (auto [l, r] : gg) if ((r - l) % 2 == 1) {
		if (dir[l] == std::make_pair(a[l - 1], a[r])) {
			a[r - 1] = a[r];
		} else {
			a[l] = a[l - 1];
		}
	}
	std::set <int> st;
	for (int i = 1; i <= n; ++ i) st.insert(i);
	rep(i, n - 1) if (a[i] && a[i] == a[i + 1]) {
		st.erase(a[i]);
	}
	rep(i, n) if (!a[i]) {
		assert(i < n - 1 && !a[i + 1]);
		a[i] = a[i + 1] = *st.begin();
		st.erase(st.begin());
	}
	rep(i, n) printf("%d ", a[i]);
	printf("\n");
	return 0;
}