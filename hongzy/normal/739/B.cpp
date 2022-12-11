#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
struct Edge {
	int v, w;
};
int n, a[N], f[N][19], ans[N];
vector<Edge> G[N];
ll d[N];
void dfs(int u, int fa = 0) {
	f[u][0] = fa;
	for(int i = 1; i < 19; i ++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	int v = u;
	for(int i = 18; ~ i; i --) {
		if(f[v][i] && d[u] - d[f[v][i]] <= a[u]) {
			v = f[v][i];
		}
	}
	ans[f[u][0]] ++; ans[f[v][0]] --;
	for(Edge &e : G[u]) {
		d[e.v] = d[u] + e.w;
		dfs(e.v, u); ans[u] += ans[e.v];
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 2; i <= n; i ++) {
		int u, w;
		scanf("%d%d", &u, &w);
		G[u].push_back({i, w});
	}
	dfs(1);
	for(int i = 1; i <= n; i ++) {
		printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}