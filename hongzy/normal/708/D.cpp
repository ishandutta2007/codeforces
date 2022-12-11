#include <algorithm>
#include <cstdio>
#include <queue>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

const int N = 210;
const int M = 1e5 + 10;
const int INF = 2e9 + 10;

struct network {
	struct Edge {
		int v, c, f, w, nxt;
	} e[M];
	int n, hd[N], ec;
	void init() {
		fill(hd + 1, hd + n + 1, -1); ec = 0;
	}
	void add(int u, int v, int c, int w) {
		e[ec] = (Edge) {v, c, 0, w, hd[u]}; hd[u] = ec ++;
		e[ec] = (Edge) {u, 0, 0, -w, hd[v]}; hd[v] = ec ++;
	}
	int d[N], a[N], p[N];
	bool inq[N]; 
	int mcmf(int s, int t) {
		int cost = 0;
		while(1) { 
			fill(d + 1, d + n + 1, INF);
			fill(inq + 1, inq + n + 1, 0);
			queue<int> q; q.push(s); d[s] = 0; inq[s] = 1; a[s] = INF;
			while(q.size()) {
				int u = q.front(); q.pop(); inq[u] = 0;
				for(int i = hd[u]; ~ i; i = e[i].nxt) {
					int v = e[i].v;
					if(d[v] > d[u] + e[i].w && e[i].c > e[i].f) {
						d[v] = d[u] + e[i].w; a[v] = min(a[u], e[i].c - e[i].f); p[v] = i;
						if(!inq[v]) {
							inq[v] = 1; q.push(v);
						}
					}
				}
			}
			if(d[t] == INF) break ;
			cost += a[t] * d[t];
			for(int v = t; v != s; v = e[p[v] ^ 1].v) {
				e[p[v]].f += a[t]; e[p[v] ^ 1].f -= a[t];
			}
		}
		return cost;
	}
} net;
int n, m, flow[N];
int main() {
	scanf("%d%d", &n, &m);
	net.n = n + 2; net.init();
	int u, v, c, f, ans = 0;
	rep(i, 1, m) {
		scanf("%d%d%d%d", &u, &v, &c, &f);
		flow[u] -= f; flow[v] += f;
		if(f <= c) {
			net.add(v, u, f, 1);
			net.add(u, v, c - f, 1);
			net.add(u, v, INF, 2);
		} else {
			ans += f - c;
			net.add(v, u, f - c, 0);
			net.add(v, u, c, 1);
			net.add(u, v, INF, 2);
		}
	}
	net.add(n, 1, INF, 0);
	rep(i, 1, n) {
		if(flow[i] > 0) net.add(n + 1, i, flow[i], 0);
		if(flow[i] < 0) net.add(i, n + 2, -flow[i], 0);
	}
	ans += net.mcmf(n + 1, n + 2);
	printf("%d\n", ans);
	return 0;
}