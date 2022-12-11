#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
 
int q, n, ans, d[N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
	int maxv = (int) G[u].size() - 1;
	for(int v : G[u]) if(v != fa) {
		dfs(v, u);
		ans = max(ans, maxv + d[v]);
		maxv = max(maxv, (int) G[u].size() - 1 + d[v]);
	}
	d[u] = maxv;
}
int main() {
	scanf("%d", &q);
	for(int t = 0; t < q; t ++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) G[i].clear();
		for(int i = 1, u, v; i < n; i ++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans = 0; dfs(1); printf("%d\n", ans + 2);		
	}
	return 0;
}