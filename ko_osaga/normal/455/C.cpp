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
typedef pair<lint, lint> pi;

struct disj{
	int pa[300005], s[300005];
	void init(int n){
		for(int i=1; i<=n; i++){
			pa[i] = i;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		int sz = (s[p] + 1) / 2 + (s[q] + 1) / 2 + 1;
		sz = max(sz, max(s[p], s[q]));
		pa[q] = p, s[p] = sz;
		return 1;
	}
	int getdiam(int x){
		return s[find(x)];
	}
}disj;

int n, m, q;
vector<int> gph[300005];
bool vis[300005];

pi dfs(int x, int p){
	vis[x] = 1;
	pi ret(0, x);
	for(auto &i : gph[x]){
		if(i == p) continue;
		pi t = dfs(i, x);
		t.first++;
		ret = max(ret, t);
	}
	return ret;
}

int main(){
	cin >> n >> m >> q;
	disj.init(n);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
		disj.uni(s, e);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i] && gph[i].size()){
			int diam = dfs(dfs(i, -1).second, -1).first;
			int u = disj.find(i);
			disj.s[u] = diam;
		}
	}
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 2){
			int s, e;
			scanf("%d %d",&s,&e);
			disj.uni(s, e);
		}
		else{
			int x;
			scanf("%d",&x);
			printf("%d\n", disj.getdiam(x));
		}
	}
}