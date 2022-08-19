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

int n;
vector<int> graph[500005];

int dfn[500005], size[500005], par[500005], piv;

void dfs(int x, int p){
	dfn[x] = ++piv;
	par[x] = p;
	size[x] = 1;
	for(auto &i : graph[x]){
		if(i == p) continue;
		dfs(i, x);
		size[x] += size[i];
	}
}

set<int> st;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	dfs(1, 0);
	for(int i=1; i<=n; i++){
		st.insert(i);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int t, x;
		scanf("%d %d",&t,&x);
		if(t == 1){
			auto t = st.lower_bound(dfn[x]);
			bool hdel = 0;
			while(t != st.end() && *t <= dfn[x] + size[x] - 1){
				auto u = t;
				u++;
				hdel = 1;
				st.erase(t);
				t = u;
			}
			if(hdel && x != 1) st.insert(dfn[par[x]]);
		}
		if(t == 2){
			st.insert(dfn[x]);
		}
		if(t == 3){
			auto t = st.lower_bound(dfn[x]);
			if(t != st.end() && *t <= dfn[x] + size[x] - 1) puts("0");
			else puts("1");
		}
	}
}