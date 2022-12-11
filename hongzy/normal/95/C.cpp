#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18;
const int N = 1010;
struct Graph {

struct Edge { int v; ll w; };
vector<Edge> G[N];
struct Node {
	int u; ll d;
	bool operator < (const Node &b) const { return d > b.d; }
};
int n;
void link(int u, int v, ll w) {
	G[u].push_back((Edge) {v, w});
}
void Dijkstra(int s, ll *d) {
	fill(d + 1, d + n + 1, INF);
	priority_queue<Node> pq; pq.push((Node) {s, d[s] = 0});
	while(pq.size()) {
		int u = pq.top().u; ll du = pq.top().d; pq.pop();
		if(d[u] < du) continue ;
		for(int i = 0; i < (int) G[u].size(); i ++) {
			Edge &e = G[u][i];
			if(d[e.v] > d[u] + e.w) {
				d[e.v] = d[u] + e.w; pq.push((Node) {e.v, d[e.v]});
			}
		}
	}
}

} G1, G2;
int n, m, s, t;
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t); G1.n = G2.n = n;
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G1.link(u, v, w); G1.link(v, u, w);
	}
	static ll d[N];
	for(int i = 1; i <= n; i ++) {
		int l, c; scanf("%d%d", &l, &c);
		G1.Dijkstra(i, d);
		for(int j = 1; j <= n; j ++) if(i != j && d[j] <= l) {
			G2.link(i, j, c);
		}
	}
	G2.Dijkstra(s, d);
	printf("%lld\n", d[t] == INF ? -1 : d[t]);
	return 0;
}