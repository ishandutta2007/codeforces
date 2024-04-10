#include <bits/stdc++.h>
using namespace std;
vector<int> g[100001];
char ans[100001];
int s[100001],siz;
void solve(int x, int p, char c);
void gs(int x, int p) {
	s[x] = 1;
	for (int y : g[x])if (y != p&&ans[y]==0)gs(y, x), s[x] += s[y];
}
void dfs(int x ,int p, char c) {
	for (int y : g[x]) {
		if (y == p||ans[y]!=0)continue;
		if (s[y] > siz / 2) {
			dfs(y, x, c); return;
		}
	}
	ans[x] = c;
	for (int y : g[x])if(ans[y]==0)solve(y, x, c + 1);
}
void solve(int x,int p, char c) {
	gs(x, p);
	siz = s[x];
	dfs(x, p, c);
}
int main() {
	int n,a,b,i;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), g[a].push_back(b), g[b].push_back(a);
	solve(1,0, 'A');
	for (i = 1; i <= n; i++)printf("%c ", ans[i]);
	getchar(); getchar();
}