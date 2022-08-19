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

int n, k, piv;
vector<int> gph[200005];

int dfn[200005], dep[200005];
int par[18][200005];

void dfs(int x, int p){
	dfn[x] = ++piv;
	par[0][x] = p;
	for(auto &i : gph[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		dfs(i, x);
	}
}

int lca(int s, int e){
	if(dep[s] > dep[e]) swap(s, e);
	int dx = dep[e] - dep[s];
	for(int i=0; i<18; i++){
		if((dx >> i) & 1){
			e = par[i][e];
		}
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
int a[200005];

int main(){
	cin >> n >> k;
	for(int i=0; i<2*k; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	sort(a, a+2*k, [&](const int &a, const int &b){
		return dfn[a] < dfn[b];
	});
	for(int i=1; i<18; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
	lint ret = 0;
	for(int i=0; i<k; i++){
		ret += dep[a[i]] + dep[a[i+k]] - dep[lca(a[i], a[i+k])] * 2;
	}
	cout << ret;
}