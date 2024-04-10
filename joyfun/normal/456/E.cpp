#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 300005;
int n, m, q, parent[N], len[N], vis[N], Maxu, Maxl;
vector<int> g[N];

void dfs(int u, int h, int p) {
    vis[u] = 1;
    int flag = 1;
    for (int i = 0; i < g[u].size(); i++) {
	int v = g[u][i];
	if (v == p) continue;
	flag = 0;
	dfs(v, h + 1, u);
    }
    if (flag) {
	if (h > Maxl) {
	    Maxl = h;
	    Maxu = u; 
	}
    }
}

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
	parent[i] = i;
    int u, v;
    while (m--) {
	scanf("%d%d", &u, &v);
	int pu = find(u);
	int pv = find(v);
	parent[pu] = pv;
	g[u].push_back(v);
	g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
	if (vis[i]) continue;
	Maxl = -1;
	dfs(i, 0, 0);
	Maxl = -1;
	dfs(Maxu, 0, 0);
	len[find(i)] = Maxl;
    }
    int c, a, b;
    while (q--) {
	scanf("%d", &c);
	if (c == 1) {
	    scanf("%d", &a);
	    printf("%d\n", len[find(a)]);
	}
	else {
	    scanf("%d%d", &a, &b);
	    int pa = find(a);
	    int pb = find(b);
	    if (pa != pb) {
		parent[pa] = pb;
		len[pb] = max(len[pa], max(len[pb], (len[pb] + 1) / 2 + (len[pa] + 1) / 2 + 1));
	    }
	}
    }
    return 0;
}