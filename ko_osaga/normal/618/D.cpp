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
typedef pair<int,int> pi;

vector<int> graph[200005];
int n, x, y, deg[200005];

bool vis[200005];

pi dfs(int pos){
    pi res(0,pos);
    vis[pos] = 1;
    for (int i=0; i<graph[pos].size(); i++) {
        if(vis[graph[pos][i]]) continue;
        pi x = dfs(graph[pos][i]);
        x.first += 1;
        res = max(res,x);
    }
    return res;
}

int diameter(){
	pi q = dfs(1);
    memset(vis,0,sizeof(vis));
    pi r = dfs(q.second);
    memset(vis,0,sizeof(vis));
    return r.first;
}

int dp[200005][2];

int dfs2(int x, int m, int p){
	if(~dp[x][m]) return dp[x][m];
	int ret = 0;
	vector<int> dx;
	int sum = 0;
	for(auto &i : graph[x]){
		if(i == p) continue;
		sum += dfs2(i, 0, x);
		dx.push_back(dfs2(i, 1, x) - dfs2(i, 0, x) + 1);
	}
	sort(dx.begin(), dx.end());
	reverse(dx.begin(), dx.end());
	if(m == 0){
		for(int j=0; j<2 && j<dx.size(); j++){
			sum += max(0, dx[j]);
		}
		return dp[x][m] = sum;
	}
	else{
		for(int j=0; j<1 && j<dx.size(); j++){
			sum += max(0, dx[j]);
		}
		return dp[x][m] = sum;
	}
}

int matching(){
	memset(dp, -1, sizeof(dp));
	return dfs2(1, 0, -1);
}

int main(){
	cin >> n >> x >> y;
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		graph[s].push_back(e);
		graph[e].push_back(s);
		deg[s]++, deg[e]++;
	}
	int s = 0;
	lint ret = 1e18;
	if(*max_element(deg+1, deg+n+1) == n-1){
		s = 1;
	}
	int e = matching();
	//printf("%d %d\n",s , e);
	for(int i=s; i<=e; i++){
		ret = min(ret, 1ll * i * x + 1ll * (n-1-i) * y);
	}
	cout << ret;
}