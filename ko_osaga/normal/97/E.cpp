#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

vector<pi> lef;

vector<int> gph[100005];
int par[100005][17], dep[100005];
lint odd[100005], ps1[100005];

int n, m;

void dfs(int x, int p){
	for(int i=1; i<17; i++){
		par[x][i] = par[par[x][i-1]][i-1];
	}
	for(auto &i : gph[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		par[i][0] = x;
		dfs(i, x);
	}
}

int lca(int x, int y){
	if(dep[x] > dep[y]) swap(x, y);
	int dx = dep[y] - dep[x];
	for(int i=0; i<=16; i++){
		if((dx >> i) & 1) y = par[y][i];
	}
	for(int i=16; i>=0; i--){
		if(par[x][i] != par[y][i]){
			x = par[x][i];
			y = par[y][i];
		}
	}
	if(x != y) return par[x][0];
	return x;
}

struct disj{
	int pa[100005];
	void init(int n){
		for(int i=1; i<=n; i++){
			pa[i] = i;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p); q = find(q);
		if(p == q) return 0;
		if(dep[p] > dep[q]) swap(p, q);
		pa[q] = p; return 1;
	}
	bool same_set(int p, int q){
		return find(p) == find(q);
	}
}disj1, disj2, disj3;

void dfs2(int x, int p){
	ps1[x] += (disj3.find(x) != x && odd[disj3.find(x)]);
	for(auto &i : gph[x]){
		if(i == p) continue;
		ps1[i] += ps1[x];
		dfs2(i, x);
	}
}

int main(){
	scanf("%d %d",&n,&m);
	disj1.init(n);
	disj3.init(n);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		if(disj1.uni(s, e)){
			gph[s].push_back(e);
			gph[e].push_back(s);
		}
		else{
			lef.emplace_back(s, e);
		}
	}
	disj2 = disj1;
	for(int i=1; i<=n; i++){
		if(disj1.uni(1, i)){
			gph[1].push_back(i);
			gph[i].push_back(1);
		}
	}
	dfs(1, 0);
	for(auto &i : lef){
		int l = lca(i.first, i.second);
		for(int j=i.first; ; ){
			int u = disj3.find(j);
			if(dep[u] > dep[l]) disj3.uni(u, par[u][0]);
			else break;
			j = par[u][0];
		}
		for(int j=i.second; ; ){
			int u = disj3.find(j);
			if(dep[u] > dep[l]) disj3.uni(u, par[u][0]);
			else break;
			j = par[u][0];
		}
		if(dep[i.first] % 2 == dep[i.second] % 2){
			odd[l] = 1;
		}
	}
	for(int i=1; i<=n; i++){
		if(disj3.find(i) != i){
			odd[disj3.find(i)] |= odd[i];
			odd[i] = 0;
		}
	}
	dfs2(1, 0);
	int q;
	scanf("%d",&q);
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		if(!disj2.same_set(x, y)){
			puts("No");
		}
		else{
			int l = lca(x, y);
			int dist = dep[x] + dep[y] - dep[l] * 2;
			lint hodd = ps1[x] + ps1[y] - ps1[l] * 2ll;
			puts(dist % 2 == 0 && hodd == 0 ? "No" : "Yes");
		}
	}
}