#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node { int v, p, a; };
int num[501],s,cnt,flow;
vector<int>  g[5001];
vector<node> sp[501];
int c[2001][2001],at[2001],l[2001];
bool bfs() {
	memset(l, -1, sizeof(l));
	l[0] = 0;
	queue<int> q;
	q.push(0);
	int x;
	while (!q.empty()) {
		x = q.front(), q.pop();
		for (int y : g[x])if (c[x][y] && l[y] == -1)l[y] = l[x] + 1, q.push(y);
	}
	return l[s] + 1;
}
int dfs(int x, int ch) {
	if (x == s) return ch;
	for (; at[x] < g[x].size();at[x]++) {
		int y = g[x][at[x]];
		if (l[y] != l[x] + 1||c[x][y]==0)continue;
		int f = dfs(y, min(ch, c[x][y]));
		if (f) {
			c[x][y] -= f, c[y][x] += f;
			if (x == 0)flow += f;
			return f;
		}
	}
	return 0;
}
int main() {
	int n,i,j,a,b,m,aa,bb;
	scanf("%d%d", &n,&m);
	for (i = 0; i < n; i++)scanf("%d", num + i + 1);
	cnt = 1;
	for (i = 1; i <= n; i++) {
		for (j = 2; j*j <= num[i]; j++) {
			int idk = 0;
			while (num[i] % j == 0)idk++, num[i] /= j;
			if(idk)sp[i].push_back({ cnt++,j,idk });
		}
		if (num[i] != 1)sp[i].push_back({ cnt++,num[i],1 });
	}
	s = cnt;
	for (i = 1; i <= n; i += 2)for (auto th : sp[i])g[th.v].push_back(0), g[0].push_back(th.v), c[0][th.v] = th.a;
	for (i = 2; i <= n; i += 2)for (auto th : sp[i])g[th.v].push_back(s), g[s].push_back(th.v), c[th.v][s] = th.a;
	while (m--) {
		scanf("%d%d", &a, &b);
		if (!(a & 1))a ^= b ^= a ^= b;
		aa = 0, bb = 0;
		
		while (aa < sp[a].size() && bb < sp[b].size()) {
			auto aaa = sp[a][aa], bbb = sp[b][bb];
			if (aaa.p == bbb.p)g[aaa.v].push_back(bbb.v), g[bbb.v].push_back(aaa.v),c[aaa.v][bbb.v]=0x3f3f3f3f;
			if (aaa.p < bbb.p)aa++;
			else bb++;
		}
	}
	while (bfs()) {
		memset(at, 0, sizeof(at));
		while (dfs(0,0x3f3f3f3f));
	}
	printf("%d", flow);
	getchar(); getchar();
}