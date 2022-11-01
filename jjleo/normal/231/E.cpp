#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

const int p = 1e9 + 7;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		y >>= 1;
	}
	return ans;
}

vector<int> v1[maxn], v2[maxn];
int fa[maxn], dep[maxn];
int col[maxn], cnt;

void dfs1(int i){
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(to == fa[i]) continue;
		if(!dep[to]){
			dep[to] = dep[i] + 1, fa[to] = i;
			dfs1(to);
		}else{
			if(dep[i] > dep[to]){
				col[i] = ++cnt;
				for(int j = i;j != to;j = fa[j]) col[fa[j]] = col[i];
			}
		}
	} 
	if(!col[i]) col[i] = ++cnt;
}

int siz[maxn], sum[maxn];
int f[maxn][25], lg[maxn];

void dfs2(int i){
	sum[i] = (siz[i] > 1) + sum[f[i][0]];//debug:  
	for(int j = 1;j <= lg[dep[i]];j++) f[i][j] = f[f[i][j - 1]][j - 1];
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j];
		if(!dep[to]){
			f[to][0] = i;
			dep[to] = dep[i] + 1;
			dfs2(to);
		}
	}
}

inline int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = f[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = lg[dep[x]];i >= 0;i--){
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}

int n, m, k, x, y, z;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 2;i <= n;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	while(m--){
		scanf("%d%d", &x, &y);
		v1[x].push_back(y), v1[y].push_back(x); 
	}
	dep[1] = 1, dfs1(1);
	for(int i = 1;i <= n;i++){
		siz[col[i]]++;
		for(int j = 0;j < v1[i].size();j++){
			if(col[i] ^ col[v1[i][j]]) v2[col[i]].push_back(col[v1[i][j]]);
		}
	}
	memset(dep, 0, sizeof(dep));
	dep[1] = 1, dfs2(1);
	scanf("%d", &k);
	while(k--){
		scanf("%d%d", &x, &y);
		x = col[x], y = col[y];
		z = lca(x, y);
		printf("%d\n", fpow(2, sum[x] + sum[y] - sum[z] - sum[f[z][0]]));
	}
}