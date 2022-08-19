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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

lint dep[100005], dep2[100005];
int par[100005][17], dfn[100005], rev[100005], piv;

vector<pi> gph[100005];

void dfs(int x, int p){
	for(int i=1; i<17; i++){
		par[x][i] = par[par[x][i-1]][i-1];
	}
	dfn[x] = ++piv;
	rev[dfn[x]] = x;
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		dep[i.second] = dep[x] + 1;
		dep2[i.second] = dep2[x] + i.first;
		par[i.second][0] = x;
		dfs(i.second, x);
	}
}

lint dist(int s, int e){
	lint cr = dep2[s] + dep2[e];
	if(dep[s] < dep[e]){
		swap(s, e);
	}
	int dx = dep[s] - dep[e];
	for(int i=0; i<17; i++){
		if((dx >> i) & 1) s = par[s][i];
	}
	for(int i=16; i>=0; i--){
		if(par[s][i] != par[e][i]){
			s = par[s][i];
			e = par[e][i];
		}
	}
	if(s != e) s = par[s][0];
	cr -= dep2[s] * 2;
	return cr;
}

set<int> s;
lint cur;

void add(int x){
	if(s.empty()){
		s.insert(x);
		return;
	}
	auto nxt = s.lower_bound(x);
	auto bef = s.lower_bound(x);
	if(nxt == s.begin()){
		bef = --s.end();
	}
	else{
		bef--;
		if(nxt == s.end()) nxt = s.begin();
	}
	cur += dist(rev[*bef], rev[x]) + dist(rev[x], rev[*nxt]) - dist(rev[*bef], rev[*nxt]);
	s.insert(x);
}

void del(int x){
	s.erase(x);
	if(s.empty()) return;
	auto nxt = s.upper_bound(x);
	auto bef = s.lower_bound(x);
	if(nxt == s.begin()){
		bef = --s.end();
	}
	else{
		bef--;
		if(nxt == s.end()) nxt = s.begin();
	}
	cur -= dist(rev[*bef], rev[x]) + dist(rev[x], rev[*nxt]) - dist(rev[*bef], rev[*nxt]);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		gph[s].emplace_back(x, e);
		gph[e].emplace_back(x, s);
	}
	dfs(1, 0);
	int q;
	scanf("%d",&q);
	while(q--){
		string s;
		cin >> s;
		if(s[0] == '?') printf("%lld\n",cur/2);
		if(s[0] == '+'){
			int x;
			scanf("%d",&x);
			add(dfn[x]);
		}
		if(s[0] == '-'){
			int x;
			scanf("%d",&x);
			del(dfn[x]);
		}
	}
}