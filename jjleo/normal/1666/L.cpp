#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m, s;
vector<int> v[maxn];
bool vis[maxn];
int fa[maxn][25], lg[maxn], dep[maxn];

void dfs(int i){
	vis[i] = true;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]) continue;
		fa[to][0] = i, dep[to] = dep[i] + 1;
		dfs(to);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0]; 
}

int main(){
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d%d%d", &n, &m, &s);
	while(m--){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	dfs(s);
	for(int i = 1;i <= n;i++){
		if(!vis[i]) continue;
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j];
			if(!vis[to]) continue;
			if(fa[to][0] == i) continue;
			if(lca(i, to) != s) continue;
			if(to == s) continue;
			puts("Possible");
			vector<int> v;
			int x = i;
			v.push_back(to);
			while(x) v.push_back(x), x = fa[x][0];
			printf("%d\n", v.size());
			for(int k = v.size() - 1;~k;k--) printf("%d ", v[k]);
			puts("");
			v.clear();
			x = to;
			while(x) v.push_back(x), x = fa[x][0];
			printf("%d\n", v.size());
			for(int k = v.size() - 1;~k;k--) printf("%d ", v[k]);
			return 0;
		}
	}
	printf("Impossible");
}