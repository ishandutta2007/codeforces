#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, s, t, x[30005], y[30005], w[30005];
vector<int> edgs;

struct disj{
	int pa[1005];
	void init(int n){
		for(int i=1; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

struct edg{
	int s, e, x, idx;
}e[30005];

bool ok(int d){
	disj.init(n);
	for(int i=0; i<m; i++){
		if(i == d) continue;
		disj.uni(x[i], y[i]);
	}
	if(disj.uni(s, t)){
		return 0;
	}
	return 1;
}

vector<pi> gph[1005];
int par[10][1005], pae[1005], dep[1005];
int chk[1005];

int lca(int s, int e){
	if(dep[s] < dep[e]) swap(s, e);
	int dx = dep[s] - dep[e];
	for(int i=0; i<10; i++){
		if((dx >> i) & 1){
			s = par[i][s];
		}
	}
	for(int i=9; i>=0; i--){
		if(par[i][s] != par[i][e]){
			s = par[i][s];
			e = par[i][e];
		}
	}
	if(s != e) return par[0][s];
	return s;
}

void dfs(int x, int p){
	for(auto &i : gph[x]){
		if(i.first != p){
			par[0][i.first] = x;
			for(int j=1; j<10; j++){
				par[j][i.first] = par[j-1][par[j-1][i.first]];
			}
			dep[i.first] = dep[x] + 1;
			pae[i.first] = i.second;
			dfs(i.first, x);
		}
	}
}

void dfs3(int x, int p){
	for(auto &i : gph[x]){
		if(i.first != p){
			dfs3(i.first, x);
			chk[x] += chk[i.first];
		}
	}
}

int solve(int d){
	disj.init(n);
	vector<edg> tr;
	vector<pi> iy;
	for(int i=0; i<m; i++){
		if(e[i].idx == d) continue;
		if(disj.uni(e[i].s, e[i].e)){
			tr.push_back(e[i]);
		}
		else{
			iy.push_back({e[i].s, e[i].e});
		}
	}
	if(disj.find(s) != disj.find(t)){
		return -1;
	}
	for(int i=1; i<=n; i++) gph[i].clear();
	memset(chk, 0, sizeof(chk));
	memset(par, 0, sizeof(par));
	for(auto &i : tr){
		gph[i.s].push_back({i.e, i.idx});
		gph[i.e].push_back({i.s, i.idx});
	}
	dfs(s, -1);
	for(auto &i : iy){
		int l = lca(i.first, i.second);
		chk[i.first]++;
		chk[i.second]++;
		chk[l] -= 2;
	}
	dfs3(s, -1);
	lint ret = 1e18;
	int pos = -1;
	for(int i=t; i!=s; i=par[0][i]){
		if(!chk[i]){
			if(ret > w[pae[i]]){
				ret = w[pae[i]];
				pos = pae[i];
			}
		}
	}
	return pos;
}

vector<pi> just[1005];
bool vis[1005];
int pae2[1005], par2[1005];

void dfs2(int x){
	for(auto &i :just[x]){
		if(vis[i.first]) continue;
		else{
			vis[i.first] = 1;
			par2[i.first] = x;
			pae2[i.first] = i.second;
			dfs2(i.first);
		}
	}
}

int ori[30005];

int main(){
	cin >> n >> m >> s >> t;
	disj.init(n);
	int indx = 0;
	for(int i=0; i<m; i++){
		indx++;
		scanf("%d %d %d",&x[i], &y[i], &w[i]);
		if(x[i] == y[i]){
			i--;
			m--;
			continue;
		}
		ori[i] = indx;
		e[i] = {x[i], y[i], w[i], i};
		just[x[i]].push_back({y[i], i});
		just[y[i]].push_back({x[i], i});
		disj.uni(x[i], y[i]);
	}
	if(disj.uni(s, t)){
		puts("0\n0");
		return 0;
	}
	vis[s] = 1;
	dfs2(s);
	for(int i=t; i!=s; i=par2[i]){
		edgs.push_back(pae2[i]);
	}
	lint ret = 1e18;
	int p1 = -1, p2 = -1;
	for(int i=0; i<edgs.size(); i++){
		if(!ok(edgs[i])){
			if(ret > w[edgs[i]]){
				ret = w[edgs[i]];
				p1 = edgs[i];
				p2 = -1;
			}
		}
	}
	for(int i=0; i<edgs.size(); i++){
		int p = solve(edgs[i]);
		if(p != -1){
			if(ret > w[edgs[i]] + w[p]){
				ret = w[edgs[i]] + w[p];
				p1 = edgs[i];
				p2 = p;
			}
		}
	}
	if(p1 == -1){
		puts("-1");
		return 0;
	}
	printf("%lld\n", ret);
	if(p2 == -1){
		printf("1\n%d", ori[p1]);
	}
	else{
		printf("2\n%d %d", ori[p1], ori[p2]);
	}
}