#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 10;
int n, m, k, deg[N], vis[N];
vector<int> G[N];
void solve() {
	scanf("%d%d%d", &n, &m, &k);
	fill(vis + 1, vis + n + 1, 0);
	for(int i = 1; i <= n; i ++) G[i].clear();
	int u, v;
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
	}
	if(k * (k - 1ll) > 2 * m) {
		puts("-1"); return ;
	}
	for(int i = 1; i <= n; i ++) {
		sort(G[i].begin(), G[i].end());
		deg[i] = G[i].size();
	}
	queue<int> q;
	for(int i = 1; i <= n; i ++) if(deg[i] < k) q.push(i), vis[i] = 1;
	vector<int> clique;
	while(q.size()) {
		int u = q.front(); q.pop(); vis[u] = 2;
		if(deg[u] == k - 1 && !clique.size()) {
			vector<int> cur = {u};
			for(int v : G[u]) if(2 ^ vis[v]) cur.pb(v);
			bool mark = 1;
			for(int u : cur) for(int v : cur) if(u < v) {
				if(!binary_search(G[u].begin(), G[u].end(), v)){
					mark = 0; break ;
				}
			}
			if(mark) clique = cur;
		}
		for(int v : G[u]) {
			if(-- deg[v] < k && !vis[v]) {
				vis[v] = 1; q.push(v);
			}
		}
	}
	if(count(vis + 1, vis + n + 1, 0)) {
		vector<int> ans;
		for(int i = 1; i <= n; i ++) if(!vis[i]) ans.pb(i);
		printf("1 %d\n", (int)ans.size());
		for(int v : ans) printf("%d ", v);
		putchar('\n');
	} else if(clique.size()) {
		printf("2\n");
		for(int v : clique) printf("%d ", v);
		putchar('\n');
	} else puts("-1");
}
int main() {
	int test; scanf("%d", &test);
	while(test --) {
		solve();
	}
	return 0;
}