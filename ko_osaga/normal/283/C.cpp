#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
const int mod = 1e9 + 7;

int n, q, t;
int a[305];
int nxt[305], deg[305], vis[305];

vector<int> v;

void dfs(int x){
	if(x == 0) return;
	v.push_back(x);
	dfs(nxt[x]);
}

int get(int x){
	if(x == 0) return 0;
	return a[x] + get(nxt[x]);
}

int dp[100005];

int solve(vector<int> &v){
	if(t < 0) return 0;
	dp[0] = 1;
	for(auto &i : v){
		for(int j=i; j<=t; j++){
			dp[j] += dp[j-i];
			dp[j] %= mod;
		}
	}
	return dp[t];
}

bool chk(){
	int indeg[305] = {};
	queue<int> que;
	for(int i=1; i<=n; i++){
		if(nxt[i]) indeg[nxt[i]]++;
	}
	for(int i=1; i<=n; i++){
		if(indeg[i] == 0){
			que.push(i);
		}
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		if(nxt[x]){
			indeg[nxt[x]]--;
			if(indeg[nxt[x]] == 0){
				que.push(nxt[x]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(indeg[i]) return 1;
	}
	return 0;
}

int main(){
	cin >> n >> q >> t;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=0; i<q; i++){
		int s, e;
		cin >> s >> e;
		nxt[e] = s;
		vis[s] = vis[e] = 1;
		deg[s]++;
	}
	if(chk()){
		cout << 0;
		return 0;
	}
	for(int i=1; i<=n; i++){
		if(nxt[i] && !deg[i]){
			dfs(i);
		}
	}
	vector<int> knap_cand;
	for(int i=1; i<=n; i++){
		if(!vis[i]) knap_cand.push_back(a[i]);
		else{
			t -= get(i) - a[i];
			if(t < 0){
				cout << 0;
				return 0;
			}
			knap_cand.push_back(get(i));
		}
	}
	cout << solve(knap_cand);
}