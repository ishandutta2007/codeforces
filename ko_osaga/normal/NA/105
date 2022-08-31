#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
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
const int MAXN = 1000005;
 
struct strongly_connected{
    vector<int> gph[MAXN];
    vector<int> rev[MAXN];
    int comp[MAXN], p;
    bool vis[MAXN];
    vector<int> dfn;
    void add_edge(int s, int e){
    	gph[s].push_back(e);
    	rev[e].push_back(s);
	}
	void dfs(int x){
		if(vis[x]) return;
		vis[x] = 1;
		for(auto &i : gph[x]) dfs(i);
		dfn.push_back(x);
	}
	void rdfs(int x, int p){
		if(comp[x]) return;
		comp[x] = p;
		for(auto &i : rev[x]) rdfs(i, p);
	}
	void get_scc(int n){
		for(int i=0; i<n; i++){
			if(!vis[i]) dfs(i);
		}
		reverse(dfn.begin(), dfn.end());
		for(auto &i : dfn){
			if(!comp[i]) rdfs(i, ++p);
		}
	}
}scc;

int n, k, par[MAXN], anc[MAXN], dp[MAXN];
vector<int> gph[MAXN], dag[MAXN];
vector<int> stk;

void dfs(int x){
	stk.push_back(x);
	anc[x] = (stk.size() >= k + 1 ? stk[stk.size() - k - 1] : 1);
	for(auto &i : gph[x]) dfs(i);
	stk.pop_back();
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=2; i<=n; i++){
		scanf("%d",&par[i]);
		gph[par[i]].push_back(i);
	}
	dfs(1);
	for(int i=2; i<=n; i++){
		scc.add_edge(par[i], i);
		if(gph[i].size() == 0){
			scc.add_edge(i, anc[i]);
		}
	}
	scc.get_scc(n + 1);
	int m = scc.p;
	for(int i=1; i<=n; i++){
		if(gph[i].size() == 0) dp[scc.comp[i]]++;
		for(auto &j : scc.gph[i]){
			int l = scc.comp[i];
			int r = scc.comp[j];
			if(l != r){
				dag[l].push_back(r);
			}
		}
	}
	for(int i=m; i; i--){
		int cnt = dp[i];
		dp[i] = 0;
		for(auto &j : dag[i]) dp[i] = max(dp[i], dp[j]);
		dp[i] += cnt;
	}
	cout << *max_element(dp, dp + m + 1) << endl;
}