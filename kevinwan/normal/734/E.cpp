#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool col[200001],vis[200001];
vector<int> gg[200001];
set<int> g[200001];
int cnt = 1,num[200001],dep[200001],evil=0,val;
void bfs(int x) {
	queue<int> q;
	q.push(x);
	while (q.size()) {
		int y = q.front();
		vis[y] = 1;
		num[y] = cnt;
		q.pop();
		for (int z : gg[y])if (!vis[z]&&col[z]==col[y])q.push(z);
	}
}
void dfs(int x, int p) {
	if (dep[x] > evil)val = x,evil=dep[x];
	for (int y : g[x]) {
		if (y == p)continue;
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
}
int main() {
	scanf("%d", &n);
	int i,a,b;
	for (i = 1; i <= n; i++)scanf("%d", col + i);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), gg[a].push_back(b), gg[b].push_back(a);
	a = b = 0;
	for (i = 1; i <= n; i++) {
		if (vis[i])continue;
		bfs(i);
		cnt++;
	}
	for (i = 1; i <= n; i++) {
		for (int j : gg[i]) {
			if (num[i] != num[j])g[num[i]].insert(num[j]),g[num[j]].insert(num[i]);
		}
	}
	dfs(1, 0);
	dep[val] = 0, evil = 0;
	dfs(val, 0);
	printf("%d", (evil+1)/2);
}