#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3010;
struct qs { int k, id; } a[N];
int n, m, q, rt, ans[400010], st[N], top, tag[N], tx;
vector<int> G[N];
vector<qs> vec[N][N];
bool ins[N], vis[N];
void dfs(int u) {
	st[++ top] = u; ins[u] = vis[u] = 1; tag[u] = 0;
	for(int i = 0; i < (int) vec[rt][u].size(); i ++) {
		qs s = vec[rt][u][i];
		if(!tx && s.k <= top) {
			ans[s.id] = st[s.k];
		}																																																																																																																																																																																																																																																							
	}
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i];
		if(!vis[v]) {
			dfs(v);
		} else if(ins[v]) {
			tx ++; tag[v] --;
		}
	}
	tx += tag[u]; ins[u] = 0; top --;
}
int main() {
	//freopen("qwq.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	for(int u, v, i = 1; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}	
	for(int i = 1; i <= n; i ++) sort(G[i].begin(), G[i].end());
	for(int u, v, k, i = 1; i <= q; i ++) {
		scanf("%d%d%d", &u, &v, &k); ans[i] = -1;
		vec[u][v].push_back((qs) {k, i});
	}
	for(int i = 1; i <= n; i ++) {
		fill(vis + 1, vis + n + 1, 0);
		//fill(tag + 1, tag + n + 1, 0);
		tx = 0; rt = i; dfs(i);
	}
	for(int i = 1; i <= q; i ++)
		printf("%d\n", ans[i]);
	return 0;
}