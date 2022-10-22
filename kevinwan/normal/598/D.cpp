#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m, k;
int lab = 1;
int use[1000][1000];
bool vis[1000][1000];
bool val[1000][1000];
int ans[1000001];
string g[1000];
void dfs(int x, int y) {
	if (vis[x][y])return;
	if (!val[x][y]) {
		ans[lab]++;
		use[x][y] = lab;
		return;
	}
	vis[x][y] = 1;
	use[x][y] = lab;
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x - 1, y);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int i,j,a,b;
	for (i = 0; i < n; i++)cin >> g[i];
	for (i = 0; i < n; i++)for (j = 0; j < m; j++)val[i][j] = (g[i][j]=='.');
	for (i = 0; i < n; i++)for(j=0;j<m;j++) {
		if(!vis[i][j])dfs(i, j);
		lab++;
	}
	for (i = 0; i < k; i++)scanf("%d%d", &a, &b), printf("%d\n", ans[use[a-1][b-1]]);
}