#include <bits/stdc++.h>
#define maxn 250086

using namespace std;

int n;
vector<int> v[maxn];
int f[maxn][25], lg[maxn], dep[maxn], x, y;

void dfs(int i){
	for(int j = 1;j <= 20;j++) f[i][j] = f[f[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == f[i][0]) continue;
		f[to][0] = i, dep[to] = dep[i] + 1, dfs(to);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = f[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int fa[maxn];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve(int x, int y){
	int X = x, Y = y;
	int z = lca(x, y);
	if(find(x) ^ find(z)){
		x = find(x);
		printf("%d %d %d %d\n", x, f[x][0], X, Y);
		fa[x] = find(f[x][0]);
	}else{
		x = y;
		for(int i = 20;~i;i--) if(dep[f[x][i]] > dep[z] && find(f[x][i]) != find(z)) x = f[x][i];
		printf("%d %d %d %d\n", x, f[x][0], X, Y);
		fa[x] = find(f[x][0]);
	}
}

void dfs(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
	}
	if(fa) solve(i, fa);
}

int main(){
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d", &n);
	for(int i = 1;i < n;i++) scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	dfs(1);
	for(int i = 1;i <= n;i++) v[i].clear();
	for(int i = 1;i < n;i++) scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	for(int i = 1;i <= n;i++) fa[i] = i;
	printf("%d\n", n - 1);
	dfs(1, 0);
}