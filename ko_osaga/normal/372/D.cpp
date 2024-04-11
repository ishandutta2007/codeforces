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

int n, k;
int par[100005][17], dep[100005], dfn[100005];
int rev[100005], piv;

vector<int> graph[100005];

void dfs(int x, int p){
	dfn[x] = ++piv;
	rev[piv] = x;
	par[x][0] = p;
	for(int i=1; i<17; i++){
		par[x][i] = par[par[x][i-1]][i-1];
	}
	for(auto &i : graph[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		dfs(i, x);
	}
}

int lca(int s, int e){
	if(dep[s] < dep[e]) swap(s, e);
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
	if(s == e) return s;
	return par[s][0];
}

int dist(int s, int e){
	return dep[e] + dep[s] - 2 * dep[lca(s, e)];
}

set<int> st;

int getright(int x){
	auto u = st.lower_bound(dfn[x]);
	if(u == st.end()) return rev[*st.begin()];
	else return rev[*u];
}

int getleft(int x){
	auto u = st.lower_bound(dfn[x]);
	if(u != st.begin()) return rev[*(--u)];
	return rev[*--st.end()];
}

bool trial(int x){
	if(x == 1) return 1;
	st.clear();
	st.insert(dfn[1]);
	lint cost = 0;
	for(int i=2; i<=x; i++){
		int t = getleft(i);
		int u = getright(i);
		cost += dist(t, i) + dist(i, u) - dist(t, u);
		st.insert(dfn[i]);
	}
	for(int i=x; i<=n; i++){
		if(cost <= 2 * k - 2) return 1;
		if(i == n) break;
		int t = getleft(i+1);
		int u = getright(i+1);
		cost += dist(t, i+1) + dist(i+1, u) - dist(t, u);
		st.insert(dfn[i+1]);
		st.erase(dfn[i-x+1]);
		t = getleft(i-x+1);
		u = getright(i-x+1);
		cost -= dist(t, i-x+1) + dist(i-x+1, u) - dist(t, u);
	}
	return 0;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	dfs(1, 0);
	int s = 0, e = n;
	while(s != e){
		int m = (s+e+1)/2;
		if(trial(m)) s = m;
		else e = m-1;
	}
	cout << s;
}