#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
struct Edge {
	int u, v, w;
	bool operator < (const Edge &e) const {
		return w > e.w;	
	}
} e[N];
int n, m, f[N];
bool cir[N];
int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) f[i] = i;
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	sort(e + 1, e + m + 1);
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		int u = find(e[i].u), v = find(e[i].v);
		if(u != v && cir[v] + cir[u] < 2) { cir[v] |= cir[u]; f[u] = v; ans += e[i].w; }
		else if(u == v && !cir[u]) { cir[u] = 1; ans += e[i].w; }
	}
	printf("%d\n", ans);
	return 0;
}