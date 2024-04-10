#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[5001];
int r[5001],s;
bool vis[5001];
void dfs(int x) {
	vis[x] = 1;
	for (int y : g[x]) {
		if (y == s )continue;
		if (vis[y])continue;
		r[y] = r[x];
		dfs(y);
	}
}
int main() {
	int n,m,i,a,b;
	scanf("%d%d%d", &n, &m,&s);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
	}
	for (i = 1; i <= n; i++) {
		if (r[i] != 0)continue;
		r[i] = i;
		memset(vis, 0, sizeof(vis));
		dfs(i);
	}
	set<int> s;
	for (i = 1; i <= n; i++) {
		s.insert(r[i]);
	}
	printf("%d", s.size() - 1);
	getchar(); getchar();
}