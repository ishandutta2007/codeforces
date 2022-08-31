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

int n, k, crit;
vector<int> dfn;
vector<int> gph[200005];
int par[200005], s1[200005], s2[200005];
int a[200005];

void dfs(int x, int p){
	par[x] = p;
	s1[x] = (a[x] >= crit);
	s2[x] = 1;
	dfn.push_back(x);
	for(auto &i : gph[x]){
		if(i == p) continue;
		dfs(i, x);
		s1[x] += s1[i];
		s2[x] += s2[i];
	}
}

int dp[200005], mdp[200005];
int pdp[200005], pmdp[200005];
multiset<int> st[200005];

int trial(int x){
	crit = x;
	dfn.clear();
	dfs(1, 0);
	memset(dp, 0, sizeof(dp));
	memset(mdp, 0, sizeof(mdp));
	memset(pdp, 0, sizeof(pdp));
	memset(pmdp, 0, sizeof(pmdp));
	for(int i=1; i<=n; i++) st[i].clear();
	for(int i=dfn.size()-1; i>=0; i--){
		int p = dfn[i];
		if(a[p] < crit) continue;
		dp[p] = 1;
		mdp[p] = 0;
		for(auto &j : gph[p]){
			if(j == par[p]) continue;
			if(s1[j] == s2[j]){
				dp[p] += s2[j];
			}
			else{
				st[p].insert(dp[j]);
				mdp[p] = max(mdp[p], dp[j]);
			}
		}
		dp[p] += mdp[p];
	}
	int ret = 0;
	if(a[1] >= crit) ret = dp[1];
	for(int i=1; i<dfn.size(); i++){
		int p = dfn[i];
		if(a[par[p]] < crit) continue;
		pdp[p] = 1;
		pmdp[p] = 0;
		if(par[par[p]]){
			if(s1[1] - s1[par[p]] == s2[1] - s2[par[p]]){
				pdp[p] += pdp[par[p]];
			}
			else{
				pmdp[p] = max(pmdp[p], pdp[par[p]]);
			}
		}
		if(s1[p] == s2[p]){
			pdp[p] += dp[par[p]] - 1 - mdp[par[p]] - s2[p];
			pmdp[p] = max(pmdp[p], mdp[par[p]]);
		}
		else{
			pdp[p] += dp[par[p]] - 1 - mdp[par[p]];
			if(*--st[par[p]].end() == dp[p]){
				auto u = --st[par[p]].end();
				if(u != st[par[p]].begin()){
					u--;
					pmdp[p] = max(pmdp[p], *u);
				}
			}
			else{
				pmdp[p] = max(pmdp[p], *--st[par[p]].end());
			}
		}/*
		for(auto &j : gph[par[p]]){
			if(j == p || j == par[par[p]]) continue;
			else{
				if(s1[j] == s2[j]){
					pdp[p] += s2[j];
				}
				else{
					pmdp[p] = max(pmdp[p], dp[j]);
				}
			}
		}*/
		pdp[p] += pmdp[p];
	}
	for(int i=2; i<=n; i++){
		if(a[i] < crit) continue;
		int p = i;
		int t1 = dp[p] - mdp[p];
		int t2 = mdp[p];
		if(s1[1] - s1[i] == s2[1] - s2[i]){
			t1 += pdp[p];
		}
		else{
			t2 = max(t2, pdp[p]);
		}
		ret = max(ret, t1 + t2);
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	int s = 0, e = 1e6;
	while(s != e){
		int m = (s+e+1)/2;
		if(trial(m) >= k) s = m;
		else e = m-1;
	}
	cout << s;
}