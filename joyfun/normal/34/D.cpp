#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;

int n, r1, r2, sb;

vector<int> g[N];
int du[N], i;
int vis[N];
int ans[N];

void dfs(int now) {
	vis[now] = 1;
	for (int i = 0; i < g[now].size(); i++) {
		int v = g[now][i];
		if (vis[v]) continue;
		ans[v] = now;
		dfs(v);
	}
}

int main() {
	memset(vis, 0, sizeof(vis));
	memset(du, 0, sizeof(du));
	memset(g, 0, sizeof(g));
	scanf("%d%d%d", &n, &r1, &r2);
	for (i = 1; i <= n; i++) {
		if (i == r1) continue;
		scanf("%d", &sb);
		g[i].push_back(sb);
		g[sb].push_back(i);
		du[i]++; du[sb]++;
	}
	dfs(r2);
	int bo = 0;
	for (i = 1; i <= n; i++) {
		if (i == r2) continue;
		if (bo++) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}