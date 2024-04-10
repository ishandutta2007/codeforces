#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
 
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)
 
template <int mxn, int mxm> struct MF {
	int hd[mxn], nex[mxm << 1], to[mxm << 1], lim[mxm << 1], tot;
	int dis[mxn], que[mxn], ql, qr, temp[mxn];
	MF() { memset(hd, -1, sizeof(hd)); }
	void __add_edge(int u, int v, int w) {
		to[tot] = v;
		lim[tot] = w;
		nex[tot] = hd[u];
		hd[u] = tot ++;
	}
	void add_edge(int u, int v, int w) {
		__add_edge(u, v, w);
		__add_edge(v, u, 0);
	}
	bool bfs(int S, int T) {
		memset(dis, -1, sizeof(dis)); dis[S] = 0;
		ql = qr = 0; que[qr ++] = S;
		while (ql < qr) {
			int u = que[ql ++];
			for (int e = hd[u]; ~e; e = nex[e]) {
				int v = to[e], w = lim[e];
				if (w && dis[v] == -1) {
					dis[v] = dis[u] + 1;
					que[qr ++] = v;
				}
			}
		}
		return dis[T] != -1;
	}
	int dfs(int u, int T, int f) {
		if (u == T) return f;
		int flow = 0;
		for (int &e = temp[u]; ~e; e = nex[e]) {
			int v = to[e], w = lim[e];
			if (w && dis[v] == dis[u] + 1) {
				int d = dfs(v, T, min(f, w));
				if (d == 0) continue;
				lim[e] -= d; lim[e ^ 1] += d;
				f -= d; flow += d;
			}
		}
		return flow;
	}
	int solve(int S, int T) {
		int ans = 0;
		while (bfs(S, T)) {
			memcpy(temp, hd, sizeof(hd));
			ans += dfs(S, T, 0x3f3f3f3f);
		}
		return ans;
	}
};
 
const int mxn = 205, mxnd = mxn * mxn * 8;
int n, m;
char s[mxn][mxn];
int id[mxn][mxn][2];
int cnt;
MF <mxnd, mxnd> mf;
 
int main() {
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%s", s[i]);
	int S = cnt ++, T = cnt ++;
	rep(i, n) rep(j, m) {
		if (s[i][j] == '#' && s[i][j + 1] == '#') id[i][j][0] = cnt ++, mf.add_edge(S, id[i][j][0], 1); else id[i][j][0] = -1;
		if (s[i][j] == '#' && s[i + 1][j] == '#') id[i][j][1] = cnt ++, mf.add_edge(id[i][j][1], T, 1); else id[i][j][1] = -1;
	}
	rep(i, n - 1) rep(j, m - 1) {
		if (id[i][j][0] != -1 && id[i][j][1] != -1) mf.add_edge(id[i][j][0], id[i][j][1], 1);
		if (id[i][j][0] != -1 && id[i][j + 1][1] != -1) mf.add_edge(id[i][j][0], id[i][j + 1][1], 1);
		if (id[i][j][1] != -1 && id[i + 1][j][0] != -1) mf.add_edge(id[i + 1][j][0], id[i][j][1], 1);
		if (id[i][j + 1][1] != -1 && id[i + 1][j][0] != -1) mf.add_edge(id[i + 1][j][0], id[i][j + 1][1], 1);
	}
	int blk = 0;
	rep(i, n) rep(j, m) if (s[i][j] == '#') ++ blk;
	printf("%d\n", blk - (cnt - 2 - mf.solve(S, T)));
	return 0;
}