#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;

const int N = 1e3 + 10;
const int M = 2e4 + 10;
const ll INF = 1e16;

struct Edge {
	int v, nxt; ll w;
} e[M];
int hd[N], p, n, m, L, s, t, pre[N];
bool use[M], mark[M];
vector<int> mdf, mmdf;
void clr() { fill(hd, hd + n, -1); p = 0; }
void add(int u, int v, ll w) {
	e[p] = (Edge) {v, hd[u], w}; hd[u] = p ++;
}
struct node {
	int u; ll d;
	bool operator < (const node &b) const { return d > b.d; }
};
ll d[N];
ll dijkstra() {
	fill(d, d + n, INF * 10ll);
	priority_queue<node> pq; pq.push((node) {s, d[s] = 0});
	while(pq.size()) {
		node k = pq.top(); pq.pop();
		int u = k.u; ll du = k.d;
		if(d[u] < du) continue ;
		for(int i = hd[u]; ~ i; i = e[i].nxt) {
			Edge &g = e[i];
			if(d[g.v] > d[u] + g.w) {
				pre[g.v] = i;
				pq.push((node) {g.v, d[g.v] = d[u] + g.w});
			}
		}
	}
	return d[t];
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &L, &s, &t); clr();
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(w == 0) mdf.push_back(p), use[p] = 1;
		add(u, v, w); add(v, u, w);
	}
	for(int i = 0; i < mdf.size(); i ++) {
		int j = mdf[i]; e[j].w = e[j ^ 1].w = INF;
	}
	if(dijkstra() < L) return puts("NO"), 0;
	for(int i = 0; i < mdf.size(); i ++) {
		int j = mdf[i]; e[j].w = e[j ^ 1].w = 1;
	}
	if(dijkstra() > L) return puts("NO"), 0;
	puts("YES");
	for(int u = t; u != s; u = e[pre[u] ^ 1].v) {
		int j = pre[u], v = e[j ^ 1].v; j >>= 1; j <<= 1;
		if(use[j] && d[u] == d[v] + e[j].w || d[v] == d[u] + e[j].w) {
			mark[j] = 1; mmdf.push_back(j);
		}
	}
	for(int i = 0; i < mdf.size(); i ++) {
		int j = mdf[i];
		if(!mark[j]) e[j].w = e[j ^ 1].w = INF;
	}
	while(1) {
		ll di = dijkstra();
		if(di == L) break ;
		for(int i = 0; i < mmdf.size(); i ++) {
			int j = mmdf[i];
			if(mark[j]) {
				mark[j] = 0; e[j].w += L - di; e[j ^ 1].w += L - di; break ;
			}
		}
	}
	for(int i = 0; i < p; i += 2)
		printf("%d %d %I64d\n", e[i ^ 1].v, e[i].v, e[i].w);
	return 0;
}