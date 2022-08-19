#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
using lint = long long;
const int MAXN = 200005;
const int mod = 1e9 + 7;

vector<int> gph[MAXN];
vector<int> bcc[MAXN], cmp[MAXN];
int n, c, m, q;
int dfn[MAXN], low[MAXN], piv;
int par[18][MAXN], dep[MAXN];

int lca(int x, int y){
	if(dep[x] > dep[y]) swap(x, y);
	int dx = dep[y] - dep[x];
	for(int i=0; i<18; i++){
		if((dx >> i) & 1) y = par[i][y];
	}
	for(int i=17; i>=0; i--){
		if(par[i][x] != par[i][y]){
			x = par[i][x];
			y = par[i][y];
		}
	}
	if(x != y) return par[0][x];
	return x;
}

void dfs2(int x, int p){
	for(auto &i : gph[x]){
		if(i != p){
			dep[i] = dep[x] + 1;
			par[0][i] = x;
			dfs2(i, x);
		}
	}
}

void dfs(int x, int p){
	dfn[x] = low[x] = ++piv;
	for(auto &i : gph[x]){
		if(i == p) continue;
		if(!dfn[i]){
			dfs(i, x);
			low[x] = min(low[x], low[i]);
		}
		else low[x] = min(low[x], dfn[i]);
	}
}

void color(int x, int p){
	if(p){
		bcc[p].push_back(x);
		cmp[x].push_back(p);
	}
	for(auto &i : gph[x]){
		if(cmp[i].size()) continue;
		if(low[i] >= dfn[x]){
			bcc[++c].push_back(x);
			cmp[x].push_back(c);
			color(i, c);
		}
		else color(i, p);
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0; i<m; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	color(1, 0);
	for(int i=1; i<=n; i++) gph[i].clear();
	for(int i=1; i<=c; i++){
		for(int j=0; j<bcc[i].size(); j++){
			gph[i + n].push_back(bcc[i][j]);
			gph[bcc[i][j]].push_back(i + n);
		}
	}
	n += c;
	dfs2(1, 0);
	for(int i=1; i<18; i++){
		for(int j=1; j<=n; j++) par[i][j] = par[i-1][par[i-1][j]];
	}
	while(q--){
		int s, e; scanf("%d %d",&s,&e);
		int d = dep[s] + dep[e] - 2 * dep[lca(s, e)];
		assert(d % 2 == 0);
		printf("%d\n", d / 2);
	}
}