#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
	int v, w, nxt;
} e[N * 2];
int n, m, ec, hd[N];
void clr() {
	fill(hd + 1, hd + n + 1, -1); ec = 0;
}
void add(int u, int v, int w) {
	e[ec] = (Edge) {v, w, hd[u]}; hd[u] = ec ++;
}
namespace Lbase {

const int L = 27;
int r[L + 5];
void insert(int x) {
	for(int i = L; i >= 0; i --) {
		if(x & (1 << i)) {
			if(r[i])	x ^= r[i];
			else {
				r[i] = x;
				break ;
			}
		}
	}
}
int query(int x) {
	for(int i = L; i >= 0; i --) {
		if(x & (1 << i)) {
			if(r[i]) x ^= r[i];
		}
	}
	return x;
}

}
int dfn[N], idx, d[N]; 
void dfs(int u, int fa = 0) {
	dfn[u] = ++ idx;
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		Edge &p = e[i];
		if(p.v == fa) continue ;
		if(dfn[p.v] && dfn[p.v] <= dfn[u]) {
			Lbase :: insert(d[u] ^ d[p.v] ^ p.w);
		} else if(!dfn[p.v]) {
			d[p.v] = d[u] ^ p.w;
			dfs(p.v, u);
		}
	}
}
bool vis[N];
void dfs2(int u) {
	vis[u] = 1;
	if(u == n) return ;
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		Edge &p = e[i];
		if(vis[p.v]) continue ;
		d[p.v] = d[u] ^ p.w;
		dfs2(p.v);
		if(vis[n]) return ;
	}
}
int main() {
	scanf("%d%d", &n, &m); clr();
	for(int u, v, w, i = 0; i < m; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	dfs(1); dfs2(1);
	printf("%d\n", Lbase :: query(d[n]));
	return 0;
}