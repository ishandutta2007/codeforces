#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 3010; 

struct Edge {
	int v, nxt;
} e[N << 1];
int n, m, hd[N], p, s1, t1, l1, s2, t2, l2, dis[N][N];
void clr() {
	fill(hd + 1, hd + n + 1, -1); p = 0;
}
void add(int u, int v) {
	e[p] = (Edge) {v, hd[u]}; hd[u] = p ++;
}
void bfs(int s) {
	queue<int> q; q.push(s); dis[s][s] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = hd[u]; ~ i; i = e[i].nxt) {
			int v = e[i].v;
			if(dis[s][v] == -1) {
				dis[s][v] = dis[s][u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m); clr();
	for(int i = 1; i <= n; i ++) {
		fill(dis[i] + 1, dis[i] + n + 1, -1);
	}
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	for(int i = 1; i <= n; i ++) bfs(i);
	scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
	if(dis[s1][t1] > l1 || dis[s2][t2] > l2) {
		puts("-1"); return 0;
	}
	int ma = dis[s1][t1] + dis[s2][t2];
	for(int u = 1; u <= n; u ++) {
		for(int v = 1; v <= n; v ++) {
			if(dis[s1][u] + dis[u][v] + dis[v][t1] <= l1 && dis[s2][u] + dis[u][v] + dis[v][t2] <= l2) {
				ma = min(ma, dis[s1][u] + dis[s2][u] + dis[u][v] + dis[v][t1] + dis[v][t2]);
			}
			if(dis[s1][u] + dis[u][v] + dis[v][t1] <= l1 && dis[t2][u] + dis[u][v] + dis[v][s2] <= l2) {
				ma = min(ma, dis[s1][u] + dis[t2][u] + dis[u][v] + dis[v][t1] + dis[v][s2]);
			}
		}
	}
	printf("%d\n", m - ma);
	return 0;
}