#include <algorithm>
#include <cstdio>
using namespace std;

namespace net {
	
const int N = 1e3 + 10;
const int M = 5e5 + 10;
const int INF = 2e9 + 10;

struct Edge {
	int v, f, c, nxt;
} e[M]; 
int hd[N], p, n, s, t;
void clr() {
	fill(hd + 1, hd + n + 1, -1); p = 0;
}
void init(int n, int s, int t) {
	net :: n = n; net :: s = s; net :: t = t; clr(); 
}
void add(int u, int v, int c) {
	e[p] = (Edge) {v, 0, c, hd[u]}; hd[u] = p ++;
	e[p] = (Edge) {u, 0, 0, hd[v]}; hd[v] = p ++;
}
int d[N], cur[N];
bool bfs() {
	static int q[N];
	fill(d + 1, d + n + 1, -1); d[s] = 0;
	int l = 0, r = 0; q[r ++] = s;
	while(l < r) {
		int u = q[l ++];
		for(int i = hd[u]; ~ i; i = e[i].nxt) {
			if(-1 == d[e[i].v] && e[i].f < e[i].c) {
				d[e[i].v] = d[u] + 1; q[r ++] = e[i].v;
			}
		}
	}
	return ~ d[t];
}
int dfs(int u, int a) {
	if(u == t || a == 0) return a;
	int flow = 0;
	for(int &i = cur[u]; ~ i; i = e[i].nxt) {
		int v = e[i].v, f;
		if(d[v] == d[u] + 1 && (f = dfs(v, min(a, e[i].c - e[i].f))) > 0) {
			flow += f; e[i].f += f; e[i ^ 1].f -= f;
			if((a -= f) == 0) break ;
		}
	}
	return flow;
}
int dinic() {
	int flow = 0;
	while(bfs()) {
		copy(hd + 1, hd + n + 1, cur + 1);
		flow += dfs(s, INF);
	}
	return flow;
}

}

using net :: init;
using net :: add;
using net :: dinic;

const int N = 410;

int a[N], b[N], n, m, ans[N][N];

int main() {
	scanf("%d%d", &n, &m);
	init(2 * n + 2, 2 * n + 1, 2 * n + 2);
	int sum = 0, sum2 = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		add(net :: s, i, a[i]);
		sum += a[i];
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%d", b + i);
		sum2 += b[i];
		add(n + i, net :: t, b[i]);
	}
	for(int i = 1; i <= n; i ++) add(i, i + n, net :: INF);
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v + n, net :: INF);
		add(v, u + n, net :: INF);
	}
	if(sum == sum2 && dinic() == sum) {
		puts("YES");
		for(int i = 0; i < net :: p; i ++) {
			int u = net :: e[i ^ 1].v, v = net :: e[i].v;
			if(u >= 1 && u <= n && v > n && v <= 2 * n && net :: e[i].f > 0) {
				ans[u][v - n] += net :: e[i].f;
			}
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	} else puts("NO");
	return 0;
}