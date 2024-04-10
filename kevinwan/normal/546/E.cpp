
 #include <bits/stdc++.h>
using namespace std;
vector<int> g[250];
int c[250][250],u[250][250],l[250],st[250];
int n,m,t,flow;
int dfs(int x,int ch=0x3f3f3f3f) {
	if (x == t)return ch;
	for (; st[x] < g[x].size();st[x]++) {
		int y = g[x][st[x]];
		if (u[x][y]>=c[x][y])continue;
		if (l[y] != l[x] + 1)continue;
		int f=dfs(y,min(ch,c[x][y]-u[x][y]));
		if (f > 0) {
			u[x][y] += f;
			u[y][x] -= f;
			if (x == 0)flow += f;
			return f;
		}
	}
	return 0;
}
bool bfs() {
	memset(l, -1, sizeof(l));
	l[0] = 0;
	queue<int> q;
	q.push(0);
	int x;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int y : g[x])if (l[y] == -1&&u[x][y]<c[x][y])l[y] = l[x] + 1, q.push(y);
	}
	return l[t] != -1;
}
int main() {
	int i,j,a,b,aa=0,bb=0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)g[0].push_back(i),g[i].push_back(0), g[i].push_back(n + i),g[n+i].push_back(i),c[i][n+i]=0x3f3f3f3f, g[n + i].push_back(2 * n + 1),g[2*n+1].push_back(n+i);
	for (i = 1; i <= n; i++)scanf("%d", &c[0][i]),aa+=c[0][i];
	for (i = 1; i <= n; i++)scanf("%d", &c[n+i][2*n+1]),bb+=c[n+i][2*n+1];
	if (aa != bb) { printf("NO"); getchar(); getchar(); return 0; }
	for (i = 0; i < m; i++)scanf("%d%d", &a, &b), g[a].push_back(n + b),g[n+b].push_back(a),g[n+a].push_back(b), g[b].push_back(n + a),c[a][n+b]=0x3f3f3f3f,c[b][n+a]=0x3f3f3f3f;
	int f = 0,ff;
	t = 2 * n + 1;
	while (bfs()) {
		memset(st, 0, sizeof(st));
		while (dfs(0));
	}
	if (flow == aa) {
		printf("YES\n");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				printf("%d ", u[i][n + j]);
			}
			printf("\n");
		}
	}
	else printf("NO");
	getchar(); getchar();
}