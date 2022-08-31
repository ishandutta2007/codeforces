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
vector<int> gph[100005];
int par[100005][17], dep[100005], dfn[100005], size[100005], piv;

void dfs(int x, int p){
	dfn[x] = ++piv;
	par[x][0] = p;
	size[x] = 1;
	for(int i=1; i<17; i++){
		par[x][i] = par[par[x][i-1]][i-1];
	}
	for(auto &i : gph[x]){
		if(i == p) continue;
		dep[i] = dep[x] + 1;
		dfs(i, x);
		size[x] += size[i];
	}
}

int parent(int x, int y){
	return dfn[x] <= dfn[y] && dfn[x] + size[x] - 1 >= dfn[y] + size[y] - 1;
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	int dx = dep[x] - dep[y];
	for(int i=0; i<17; i++){
		if((dx >> i) & 1) x = par[x][i];
	}
	for(int i=16; i>=0; i--){
		if(par[x][i] != par[y][i]){
			x = par[x][i];
			y = par[y][i];
		}
	}
	if(x != y) return par[x][0];
	return x;
}

bool mk[100005];
vector<int> cgph[100005];
int dp[100005][2];

int f(int x, int p){ // p == 0 -> . p == 1 ->  .
	if(~dp[x][p]) return dp[x][p];
	int ret = 0;
	if(mk[x]){
		if(p == 1) return 1e6;
		for(auto &i : cgph[x]){
			if(mk[i] == 1) ret += min(f(i, 0), f(i, 1)) + 1;
			else ret += f(i, 1);
		}
		return dp[x][p] = ret;
	}
	else{
		if(p == 1){
			for(auto &i : cgph[x]){
				ret += min(f(i, 0), f(i, 1));
			}
			int ret2 = 0;
			for(auto &i : cgph[x]){
				ret2 += f(i, 1);
			}
			ret = min(ret + 1, ret2);
		}
		else{
			for(auto &i : cgph[x]){
				ret += min(f(i, 0), f(i, 1));
			}
			int ret2 = 0, devi = 0;
			for(auto &i : cgph[x]){
				ret2 += f(i, 1);
				devi = min(devi, f(i, 0) - f(i, 1));
			}
			ret = min(ret + 1, ret2 + devi);
		}
		return dp[x][p] = ret;
	}
}

int solve(vector<int> &v){
	int sz = v.size();
	for(auto &i : v){
		mk[i] = 1;
	}
	for(int i=0; i<sz-1; i++){
		v.push_back(lca(v[i], v[i+1]));
	}
	sort(v.begin(), v.end(), [&](const int &a, const int &b){
		return dfn[a] < dfn[b];
	});
	v.resize(unique(v.begin(), v.end()) - v.begin());
	stack<int> stk;
	stk.push(v[0]);
	int cnt = 0;
	for(int i=1; i<v.size(); i++){
		while(!parent(stk.top(), v[i])){
			stk.pop();
		}
		cgph[stk.top()].push_back(v[i]);
		if(mk[stk.top()] && mk[v[i]] && par[v[i]][0] == stk.top()){
			for(auto &i : v){
				mk[i] = 0;
				cgph[i].clear();
			}
			return -1;
		}
		stk.push(v[i]);
	}
	for(auto &i : v){
		dp[i][0] = dp[i][1] = -1;
	}
	int ret = min(f(v[0], 0), f(v[0], 1));
	for(auto &i : v){
		mk[i] = 0;
		cgph[i].clear();
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	int q;
	scanf("%d",&q);
	while(q--){
		int sz;
		scanf("%d",&sz);
		vector<int> ls(sz);
		for(int i=0; i<sz; i++){
			scanf("%d",&ls[i]);
		}
		sort(ls.begin(), ls.end(), [&](const int &a, const int &b){
			return dfn[a] < dfn[b];
		});
		printf("%d\n",solve(ls));
	}
}