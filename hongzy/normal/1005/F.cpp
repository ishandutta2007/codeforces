#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 2e5 + 10;

int n, m, k, ans1, d[N];
vector< pair<int, int> > G[N];
vector<int> p[N];
vector<string> ans;
string now;

void bfs() {
	static bool vis[N];
	queue<int> q; q.push(1); vis[1] = 1;
	while(!q.empty()) {
		int u = q.front(), v; q.pop();
		for(int i = 0; i < G[u].size(); i ++) if(!vis[v = G[u][i].first]) {
			vis[v] = 1; d[v] = d[u] + 1; q.push(v);
		}
	}
	for(int i = 2; i <= n; i ++) for(int j = 0; j < G[i].size(); j ++)
		if(d[G[i][j].first] + 1 == d[i]) p[i].push_back(G[i][j].second);
}

void solve(int u) {
	if(ans.size() >= k) return ;
	if(u == n + 1) return (void) (ans.push_back(now));
	for(int i = 0; i < p[u].size(); i ++) {
		now[p[u][i]] = '1'; solve(u + 1); now[p[u][i]] = '0';
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, u, v; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(make_pair(v, i - 1));
		G[v].push_back(make_pair(u, i - 1));
	}
	bfs();
	for(int i = 0; i < m; i ++) now.push_back('0');
	solve(2);
	printf("%d\n", ans1 = min(k, (int) ans.size()));
	for(int i = 0; i < ans1; i ++)
		printf("%s\n", ans[i].c_str());
	return 0;
}