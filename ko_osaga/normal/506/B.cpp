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

vector<int> gph[100005], rev[100005];
bool ok[100005];

int n, m;
vector<int> dfn;
int vis[100005], comp[100005], csz[100005], piv;

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	for(auto &i : gph[x]){
		dfs(i);
	}
	dfn.push_back(x);
}

void rdfs(int x, int p){
	if(comp[x]) return;
	comp[x] = p;
	csz[p]++;
	for(auto &i : rev[x]){
		rdfs(i, p);
	}
}

bool vis2[100005];

bool find_cyc(int x){
	if(vis2[x]) return 0;
	vis2[x] = 1;
	bool ret = 0;
	if(csz[comp[x]] > 1) ret = 1;
	for(auto &i : gph[x]){
		if(find_cyc(i)) ret = 1;
	}
	for(auto &i : rev[x]){
		if(find_cyc(i)) ret = 1;
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		rev[e].push_back(s);
		ok[s] = ok[e] = 1;
	}
	for(int i=1; i<=n; i++){
		if(ok[i] && !vis[i]){
			dfs(i);
		}
	}
	reverse(dfn.begin(), dfn.end());
	for(auto &i : dfn){
		if(!comp[i]) rdfs(i, ++piv);
	}
	int ret = n;
	for(int i=1; i<=n; i++){
		if(!vis2[i] && !find_cyc(i)) ret--;
	}
	cout << ret;
}