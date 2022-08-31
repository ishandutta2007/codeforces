#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
const int mod = 998244353;
const int MAXN = 200005;

struct path{
	int cost, s, e;
};

int n, m;
vector<int> graph[MAXN];
vector<path> paths[MAXN];
int par[MAXN][18], dep[MAXN];

int dfn[MAXN], sz[MAXN], p0, tra[MAXN];
int comp[MAXN], cnum[MAXN], chead[MAXN], csize[MAXN], piv;
int son[MAXN];

int lca(int x, int y){
	if(dep[x] > dep[y]) swap(x,y);
	int diff = dep[y] - dep[x];
	for (int i=0; i<18; i++) {
		if((diff >> i) & 1) y = par[y][i];
	}
	for (int i=17; i>=0; i--) {
		if(par[x][i] != par[y][i]){
			x = par[x][i];
			y = par[y][i];
		}
	}
	if(x == y) return x;
	return par[x][0];
}

void dfs(int pos, int pa){
	dfn[pos] = ++p0;
	tra[dfn[pos]] = pos;
	par[pos][0] = pa;
	for (int i=1; i<18; i++) {
		par[pos][i] = par[par[pos][i-1]][i-1];
	}
	for (auto &x : graph[pos]){
		if(x == pa) continue;
		dep[x] = dep[pos] + 1;
		dfs(x,pos);
		sz[pos] += sz[x];
	}
	sz[pos]++;
}

void hld(int pos){
	comp[pos] = piv;
	cnum[pos] = ++csize[piv];
	int pmax = -1, vmax = -1;
	for (int i=0; i<graph[pos].size(); i++) {
		if(graph[pos][i] == par[pos][0]) continue;
		if(vmax < sz[graph[pos][i]]){
			vmax = sz[graph[pos][i]];
			pmax = i;
		}
	}
	if(pmax == -1) return;
	son[pos] = graph[pos][pmax];
	hld(graph[pos][pmax]);
	for (int i=0; i<graph[pos].size(); i++) {
		if(graph[pos][i] == par[pos][0] || i == pmax) continue;
		piv++;
		chead[piv] = graph[pos][i];
		hld(graph[pos][i]);
	}
}

int dp[MAXN], sum[MAXN];
int mark[MAXN];
vector<int> psum[MAXN];

int getsum(int num, int s, int e){
	if(s > e) return 0;
	return psum[num][s] - psum[num][e+1];
}

int f(int x, int y, int l){
	int ret = 0;
	while (comp[x] != comp[l]) {
		ret += getsum(comp[x],1,cnum[x]);
		x = par[chead[comp[x]]][0];
	}
	ret += getsum(comp[l],cnum[l]+1,cnum[x]);
	while (comp[y] != comp[l]) {
		ret += getsum(comp[y],1,cnum[y]);
		y = par[chead[comp[y]]][0];
	}
	ret += getsum(comp[l],cnum[l]+1,cnum[y]);
	ret += sum[l];
	return ret;
}

void solve(){
	for (int i=n; i; i--) {
		int pos = tra[i];
		for (auto &j : graph[pos]){
			if(j == par[pos][0]) continue;
			sum[pos] += dp[j];
		}
		int ret = sum[pos];
		for (auto &j : paths[pos]){
			ret = max(ret,f(j.s,j.e,pos) + j.cost);
		}
		dp[pos] = ret;
		ret = sum[pos] - dp[pos];
		psum[comp[pos]][cnum[pos]] = psum[comp[pos]][cnum[pos]+1] + ret;
	}
}

int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=2; i<=n; i++){
		int p;
		scanf("%d",&p);
		graph[p].push_back(i);
		graph[i].push_back(p);
	}
	dfs(1,0);
	for (int i=0; i<m; i++) {
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		int l = lca(x,y);
		paths[l].push_back({c,x,y});
	}
	piv = 1;
	hld(1);
	for (int i=1; i<=piv; i++) {
		psum[i].resize(csize[i] + 2);
	}
	solve();
	printf("%d",dp[1]);
}