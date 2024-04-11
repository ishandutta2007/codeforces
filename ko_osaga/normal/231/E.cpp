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
const int mod = 1e9 + 7;

struct disj{
	int pa[100005];
	void init(int n){
		for(int i=1; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p); q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
	bool con(int p, int q){
		return find(p) == find(q);
	}
}disj;

int n, m;
vector<int> gph[100005], tree[100005];
vector<int> dfn;

int par[100005], chk[100005];
int comp[100005], csz[100005];
bool vis[100005], stk[100005];

void dfs1(int x, int p){
	par[x] = p;
	vis[x] = 1;
	stk[x] = 1;
	dfn.push_back(x);
	for(auto &i : gph[x]){
		if(i == p) continue;
		else if(stk[i]){
			for(int j=x; j!=i; j=par[j]){
				chk[j] = 1;
			}
		}
		else if(!vis[i]){
			dfs1(i, x);
		}
	}
	stk[x] = 0;
}

int spt[100005][17], dep1[100005], dep2[100005];

void dfs2(int x, int p){
	for(int i=1; i<17; i++){
		spt[x][i] = spt[spt[x][i-1]][i-1];
	}
	dep2[x] = dep2[p] + (csz[x] > 1);
	for(auto &i : tree[x]){
		spt[i][0] = x;
		dep1[i] = dep1[x] + 1;
		dfs2(i, x);
	}
}

int ipow[100005];

int query(int x, int y){
	int ret = dep2[x] + dep2[y];
	if(dep1[x] < dep1[y]) swap(x, y);
	int dx = dep1[x] - dep1[y];
	for(int i=0; i<17; i++){
		if((dx >> i) & 1) x = spt[x][i];
	}
	for(int i=16; i>=0; i--){
		if(spt[x][i] != spt[y][i]){
			x = spt[x][i];
			y = spt[y][i];
		}
	}
	if(x != y) x = spt[x][0];
	ret -= dep2[x] + dep2[spt[x][0]];
	return ret;
}

int main(){
	ipow[0] = 1;
	for(int i=1; i<=100000; i++){
		ipow[i] = (ipow[i-1] << 1) % mod;
	}
	scanf("%d %d",&n,&m);
	disj.init(n);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
		disj.uni(s, e);
	}
	dfs1(1, 0);
	int p = 0;
	for(auto &i : dfn){
		if(chk[i]) comp[i] = comp[par[i]];
		else comp[i] = ++p;
		csz[comp[i]]++;
	}
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(comp[i] < comp[j]){
				tree[comp[i]].push_back(comp[j]);
			}
		}
	}
	dfs2(1, 0);
	int q;
	scanf("%d",&q);
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		if(!disj.con(x, y)) puts("0");
		else printf("%d\n",ipow[query(comp[x], comp[y])]);
	}
}