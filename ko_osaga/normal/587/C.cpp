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

vector<int> graph[100005];
vector<int> ppl[100005];

int n, m, q;
int pa[100005][17];
int dep[100005];
vector<int> minv[100005][17];

vector<int> merge(vector<int> &r1, vector<int> &r2){
	vector<int> r3(11, 1e9);
	for(int i=0; i<=10; i++){
		for(int j=0; j<=i; j++){
			r3[i] = min(r3[i], max(r1[j], r2[i-j]));
		}
	}
	return r3;
}

void dfs(int x, int p){
	pa[x][0] = p;
	for(int i=1; i<=16; i++){
		pa[x][i] = pa[pa[x][i-1]][i-1];
	}
	minv[x][0].resize(11, 0);
	for(int i=1; i<=10; i++){
		if(i <= ppl[x].size()) minv[x][0][i] = ppl[x][i-1];
		else minv[x][0][i] = 1e9;
	}
	for(int i=1; i<17; i++){
		minv[x][i] = merge(minv[x][i-1], minv[pa[x][i-1]][i-1]);
	}
	for(auto &i : graph[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		dfs(i, x);
	}
}

int lca(int x, int y){
	if(dep[x] > dep[y]) swap(x,y);
	int dx = dep[y] - dep[x];
	for(int i=0; i<17; i++){
		if((dx >> i) & 1) y = pa[y][i];
	}
	for(int i=16; i>=0; i--){
		if(pa[x][i] != pa[y][i]){
			x = pa[x][i];
			y = pa[y][i];
		}
	}
	if(x != y) return pa[x][0];
	return x;
}

vector<int> solve_rootway(int s, int h){
	vector<int> ret(11, 1e9);
	ret[0] = 0;
	for(int i=0; i<=16; i++){
		if((h >> i) & 1){
			vector<int> tmp = merge(ret, minv[s][i]);
			ret = tmp;
			s = pa[s][i];
		}
	}
	return ret;
}

vector<int> solve(int s, int e, int l, int p){
	vector<int> r1 = solve_rootway(s, dep[s] - dep[l]);
	vector<int> r2 = solve_rootway(e, dep[e] - dep[l] + 1);
	return merge(r1, r2);
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for(int i=0; i<=16; i++){
		minv[0][i].resize(11, 1e9);
		minv[0][i][0] = 0;
	}
	for(int i=1; i<=m; i++){
		int x;
		scanf("%d",&x);
		ppl[x].push_back(i);
	}
	dfs(1, 0);
	for(int i=0; i<q; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		int l = lca(s, e);
		vector<int> v = solve(s, e, l, i);
		vector<int> tt;
		for(int i=1; i<=x; i++){
			if(v[i] < 1e8) tt.push_back(v[i]);
		}
		printf("%d ",tt.size());
		for(auto &i : tt) printf("%d ",i);
		puts("");
	}
}