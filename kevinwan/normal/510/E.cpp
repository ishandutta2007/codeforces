#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,flow;
vector<int>  g[202];
int c[202][202],u[202][202],at[2001],l[2001];
bool bfs() {
	memset(l, -1, sizeof(l));
	l[0] = 0;
	queue<int> q;
	q.push(0);
	int x;
	while (!q.empty()) {
		x = q.front(), q.pop();
		for (int y : g[x])if ((c[x][y]>u[x][y]) && l[y] == -1)l[y] = l[x] + 1, q.push(y);
	}
	return l[s] + 1;
}
int dfs(int x, int ch) {
	if (x == s) return ch;
	for (; at[x] < g[x].size();at[x]++) {
		int y = g[x][at[x]];
		if (l[y] != l[x] + 1||c[x][y]==u[x][y])continue;
		int f = dfs(y, min(ch, c[x][y]-u[x][y]));
		if (f) {
			u[x][y] += f, u[y][x] -= f;
			if (x == 0)flow += f;
			return f;
		}
	}
	return 0;
}
int a[201];
bitset<20001> p;
vector<vector<int>> v;
bool done[201];
int idk(int x) {
	int i;
	for (i = 1; i < s; i++)if (u[x][i] && !done[i])return i;
	return 0;
}
int main() {
	int n,i,j;
	p.set();
	for (i = 2; i*i <= 20000; i++)if (p[i])for (j = i * i; j <= 20000; j += i)p[j] = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", a + i);
	s = n + 1;
	for (i = 1; i <= n; i++) {
		if (a[i] & 1)g[0].push_back(i),g[i].push_back(0),c[0][i]=2;
		else g[i].push_back(s), g[s].push_back(i), c[i][s] = 2;
	}
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (p[a[i] + a[j]]) {
				g[i].push_back(j), g[j].push_back(i);
				if (a[i] & 1)c[i][j] = 1;
				else c[j][i] = 1;
			}
		}
	}
	while (bfs()) {
		memset(at, 0, sizeof(at));
		while (dfs(0,0x3f3f3f3f));
	}
	//if (n == 176) { printf("debug"); return 0; }
	if (flow != n) { printf("Impossible"); return 0; }
	for (i = 1; i <= n; i++) {
		if (done[i])continue;
		int cur = i,lc=0,t=0;
		vector<int> th;
		while (cur) {
			th.push_back(cur);
			done[cur] = 1;
			cur = idk(cur);
		}
		v.push_back(th);
	}
	printf("%d\n", v.size());
	for (auto idek : v) {
		printf("%d ", idek.size());
		for (auto thing : idek)printf("%d ", thing);
		printf("\n");
	}
	getchar(); getchar();
}