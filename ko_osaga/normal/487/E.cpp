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

vector<int> graph[100005];
int low[100005], dfn[100005], piv;

vector<int> bcc[100005];
int cutp[100005], col, cutf[200005];

void dfs(int x, int p){
	dfn[x] = low[x] = ++piv;
	for(auto &i : graph[x]){
		if(i == p) continue;
		if(dfn[i]){
			low[x] = min(low[x], dfn[i]);
		}
		else{
			dfs(i, x);
			low[x] = min(low[x], low[i]);
		}
	}
}

void color(int x, int c){
	if(c > 0) bcc[x].push_back(c);
	for(auto &i : graph[x]){
		if(bcc[i].size()) continue;
		if(low[i] >= dfn[x]){
			col++;
			bcc[x].push_back(col);
			cutf[col] = x;
			color(i, col);
		}
		else{
			color(i, c);
		}
	}
}

int a[100005];
int n, m, q;

vector<int> tree[200005];
multiset<int> ms[200005];
int dep[200005], par[18][200005];
int tpiv, tdfn[200005], size[200005];

int comp[200005], chead[200005], cnum;

void tdfs(int x, int p){
	par[0][x] = p;
	for(int i=1; i<=17; i++){
		par[i][x] = par[i-1][par[i-1][x]];
	}
	size[x] = 1;
	for(auto &i : tree[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		tdfs(i, x);
		size[x] += size[i];
	}
}

void hld(int x, int p){
	tdfn[x] = ++tpiv;
	int cmax = -1, son = -1;
	for(auto &i : tree[x]){
		if(i == p) continue;
		if(size[i] > cmax){
			cmax = size[i];
			son = i;
		}
	}
	comp[x] = cnum;
	if(son != -1) hld(son, x);
	for(auto &i : tree[x]){
		if(i != son && i != p){
			cnum++;
			chead[cnum] = i;
			hld(i, x);
		}
	}
}

struct rmq{
	int tree[530000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree + 2 * lim, 1e9);
	}
	void upd(int x, int v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		int ret = 1e9;
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}rmq;

int lca(int s, int e){
	if(dep[s] < dep[e]) swap(s, e);
	int dx = dep[s] - dep[e];
	for(int i=0; i<=17; i++){
		if((dx >> i) & 1) s = par[i][s];
	}
	for(int i=17; i>=0; i--){
		if(par[i][s] != par[i][e]){
			s = par[i][s];
			e = par[i][e];
		}
	}
	if(s != e) return par[0][s];
	return s;
}

int query(int s, int e){
	int ret = 1e9;
	while(comp[s] != comp[e]){
		ret = min(ret, rmq.query(tdfn[chead[comp[s]]], tdfn[s]));
		s = par[0][chead[comp[s]]];
	}
	ret = min(ret, rmq.query(tdfn[e], tdfn[s]));
	return ret;
}

void update(int x){
	rmq.upd(tdfn[x], *ms[x].begin());
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	dfs(1, 0);
	color(1, 0);
	for(int i=1; i<=n; i++){
		if(bcc[i].size() > 1){
			cutp[i] = ++col;
			for(auto &j : bcc[i]){
				tree[j].push_back(col);
				tree[col].push_back(j);
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(!cutp[i]){
			ms[bcc[i][0]].insert(a[i]);
		}
		else{
			ms[bcc[i][0]].insert(a[i]);
			ms[cutp[i]].insert(a[i]);
		}
	}
	tdfs(1, 0);
	chead[1] = 1;
	cnum = 1;
	hld(1, 0);
	rmq.init(col);
	for(int i=1; i<=col; i++){
		update(i);
	}
	while(q--){
		char buf[5];
		int s, e;
		scanf("%s %d %d",buf,&s,&e);
		if(*buf == 'A'){
			if(s == e){
				printf("%d\n",a[s]);
				continue;
			}
			if(cutp[s]) s = cutp[s];
			else s = bcc[s][0];
			if(cutp[e]) e = cutp[e];
			else e = bcc[e][0];
			int ret = 1e9, l = lca(s, e);
			if(cutf[l]) ret = a[cutf[l]];
			ret = min(ret, query(s, l));
			ret = min(ret, query(e, l));
			printf("%d\n",ret);
		}
		else{
			if(!cutp[s]){
				ms[bcc[s][0]].erase(ms[bcc[s][0]].find(a[s])); 
				ms[bcc[s][0]].insert(e);
				update(bcc[s][0]);
			}
			else{
				ms[bcc[s][0]].erase(ms[bcc[s][0]].find(a[s])); 
				ms[bcc[s][0]].insert(e);
				ms[cutp[s]].erase(ms[cutp[s]].find(a[s])); 
				ms[cutp[s]].insert(e);
				update(bcc[s][0]);
				update(cutp[s]);
			}
			a[s] = e;
		}
	}
}