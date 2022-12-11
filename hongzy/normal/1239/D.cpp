#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e6 + 10;
int n, m, dfn[N], low[N], sz[N], bel[N], d[N], scc;
int st[N], top;
bool ins[N];
struct Edge {
	int u, v, nxt;
} e[N];
int hd[N], ec;
void clr() { fill(hd + 1, hd + n + 1, -1); ec = 0; }
void add(int u, int v) {
	e[ec] = (Edge) {u, v, hd[u]}; hd[u] = ec ++;
}
void tarjan(int u) {
	low[u] = dfn[u] = ++ dfn[0]; st[++ top] = u; ins[u] = 1;
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		int v = e[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		scc ++;
		while(1) {
			int v = st[top --];
			ins[v] = 0; bel[v] = scc; sz[scc] ++;
			if(u == v) break ;
		}
	}
}
 
int main() {
	int T; scanf("%d", &T);
	while(T --) {
		scanf("%d%d", &n, &m); clr();
		for(int i = 1; i <= m; i ++) {
			int u, v; scanf("%d%d", &u, &v);
			if(u != v) add(u, v);
		}
		for(int i = 1; i <= n; i ++)
			if(!dfn[i]) tarjan(i);
		for(int i = 0; i < ec; i ++) {
			int uu = bel[e[i].u], vv = bel[e[i].v];
			if(uu != vv) {
				d[vv] ++;
			}
		}
		if(scc == 1) puts("No");
		else {
			puts("Yes");
			int x = 0, y = 0, z = 0;
			for(int i = 1; i <= scc; i ++) if(d[i]) x += sz[i];
			for(int i = 1; i <= scc; i ++) if(!d[i]) y += sz[i], z = i;
			if(!x) {
				y -= sz[z]; x += sz[z];
			} else z = -1;
			printf("%d %d\n", x, y);
			for(int i = 1; i <= n; i ++) if(d[bel[i]] || bel[i] == z) printf("%d ", i);
			puts("");
			for(int i = 1; i <= n; i ++) if(!d[bel[i]] && bel[i] != z) printf("%d ", i);
			puts("");
		}
		for(int i = 1; i <= n; i ++) {
			ins[i] = bel[i] = dfn[i] = low[i] = 0;
		}
		for(int i = 1; i <= scc; i ++) {
			sz[i] = d[i] = 0;
		}
		scc = dfn[0] = top = 0;
	} 
	return 0;
}