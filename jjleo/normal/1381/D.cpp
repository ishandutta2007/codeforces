#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;

int n, a, b, l;
int x, y;
vector<int> v[maxn];

int f[maxn], id[maxn], g[maxn], h[maxn];

void dfs1(int i, int fa, int dep){
	if(i == b) l = dep;
	f[i] = g[i] = h[i] = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i, dep + 1);
		if(f[to] + 1 >= f[i]) h[i] = g[i], g[i] = f[i], f[i] = f[to] + 1, id[i] = to;
		else if(f[to] + 1 >= g[i]) h[i] = g[i], g[i] = f[to] + 1;
		else h[i] = max(h[i], f[to] + 1);
	}
}

void dfs2(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		int x = (to == id[i] ? g[i] : f[i]) + 1;
		if(x >= f[to]) h[to] = g[to], g[to] = f[to], f[to] = x, id[to] = i;
		else if(x >= g[to]) h[to] = g[to], g[to] = x;
		else h[to] = max(h[to], x);
		dfs2(to, i);
	}
}

int fa[maxn][25], dep[maxn], dis[maxn], leaf[maxn];

void dfs3(int i){
	dep[i] = dep[fa[i][0]] + 1, dis[i] = 0, leaf[i] = i;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i][0]) continue;
		fa[to][0] = i;
		dfs3(to);
		if(dis[to] + 1 > dis[i]){
			dis[i] = dis[to] + 1;
			leaf[i] = leaf[to];
		}
	}
}

int lg[maxn];

inline int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--){
		if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

//bool tag[maxn];

int main(){
	for(int i = 2;i < maxn;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs1(a, 0, 0);
		dfs2(a, 0);
		int rt = 0;
		for(int i = 1;i <= n;i++){
			if(h[i] >= l){
				rt = i;
				break;
			}
		}
		if(!rt){
			puts("NO");
			continue;
		}
		for(int i = 1;i <= n;i++) memset(fa[i], 0, sizeof(fa[i]));
		dfs3(rt);
		bool suc = false;
		for(int i = 1;i <= n;i++){
			int c = lca(a, b);
			if(dep[b] - dep[c] <= dis[a]){
				suc = true;
				break;
			}
			for(int i = 20;~i;i--) if(dis[a] & (1 << i)) b = fa[b][i];
			a = leaf[a];
			swap(a, b);
		}
		/*for(int i = 1;i <= n;i++) memset(fa[i], 0, sizeof(fa[i])), tag[i] = false;
		dfs3(rt);
		bool suc = false;
		while(1){
			if(!dis[a]) swap(a, b);
			int k = dis[a];
			for(int i = 20;~i;i--) if(k & (1 << i)) b = fa[b][i];
			if(dep[a] < dep[b]) swap(a, b);
			if(tag[b]) break;
			tag[b] = true;
			a = leaf[a];
			int x = a;
			k = dep[a] - dep[b];
			for(int i = 20;~i;i--) if(k & (1 << i)) a = fa[a][i];
			if(a == b){
				suc = true;
				break;
			}
		}*/
		puts(suc ? "YES" : "NO");
	}
}