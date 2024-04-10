#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 505;
struct Edge {
	short v, nxt; int w;
} e[N * 2];
short hd[N], sz[N], pos[N], w[N], n, m, ec;
short dl[N], dr[N], idx, dp[N][N][N], t[N][N];
int x, dis[N][N];
void clr() {
	fill(hd + 1, hd + n + 1, -1); ec = 0;
}
void add(short u, short v, int w) {
	e[ec] = (Edge) {v, hd[u], w}; hd[u] = ec ++;
}
void dfs0(int *d, int u, int fa = 0) {
	if(!fa) d[u] = 0;
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		Edge &p = e[i];
		if(p.v != fa) {
			d[p.v] = min(x + 1, d[u] + p.w);
			dfs0(d, p.v, u);
		}
	}
}
void dfs1(int u, int fa = 0) {
	dl[u] = ++ idx; pos[idx] = u;
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) dfs1(v, u);
	}
	dr[u] = idx;
}
void dfs(int u, int fa = 0) {
	for(int v = 1; v <= n; v ++) {
		if(dis[u][v] <= x && u != v) {
			dp[u][0][v] = 0;
		}
	}
	dp[u][1][u] = w[u] ^ 1; sz[u] = 1;
	for(short i = hd[u]; ~ i; i = e[i].nxt) {
		int v = e[i].v;
		if(v == fa) continue ;
		dfs(v, u);
		for(short s = min(sz[v] + sz[u], (int) m); s >= 0; s --)
			for(short a = 1; a <= n; a ++)
				t[s][a] = n + 1;
		for(short su = min(sz[u], m); su >= 0; su --) {
			for(short sv = min(sz[v], m); sv >= 0; sv --) {
				short mv = n + 1;
				for(int a = dl[v]; a <= dr[v]; a ++) mv = min(mv, dp[v][sv][pos[a]]);
				for(int a = 1; a <= n; a ++) {
					t[su + sv][a] = min((int) t[su + sv][a], dp[u][su][a] + dp[v][sv][a]);
					if(a < dl[v] || a > dr[v]) {
						t[su + sv][pos[a]] = min((int) t[su + sv][pos[a]], dp[u][su][pos[a]] + mv);
					}
				}
			}
		}
		sz[u] += sz[v];
		for(short s = min(sz[u], m); s >= 0; s --)
			for(short a = 1; a <= n; a ++)
				dp[u][s][a] = t[s][a];
	}
}
int main() {
	scanf("%hd%d", &n, &x); clr();
	for(int i = 1; i <= n; i ++) {
		scanf("%hd", w + i);
		m += w[i];
	}
	for(int u, v, w, i = 1; i < n; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	for(int i = 1; i <= n; i ++) dfs0(dis[i], i);
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= n; j ++)
			for(int k = 0; k <= n; k ++)
				dp[i][j][k] = n + 1;
	dfs1(1); dfs(1);
	short ans = n + 1;
	for(int i = 1; i <= n; i ++)
		ans = min(ans, dp[1][m][i]);
	printf("%hd\n", ans > n ? -1 : ans);
	return 0;
}