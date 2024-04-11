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

struct t1{
	int pos, type, time;
};

int n, m;
vector<int> gph[100005];
vector<pi> qry[100005];

int ret[100005], dep[100005], size[100005], msize[100005];
bool vis[100005];

vector<int> dfn;

void dfs(int x, int p){
	size[x] = 1;
	msize[x] = 0;
	dfn.push_back(x);
	for(auto &i : gph[x]){
		if(i == p) continue;
		if(vis[i]) continue;
		dep[i] = dep[x] + 1;
		dfs(i, x);
		size[x] += size[i];
		msize[x] = max(msize[x], size[i]);
	}
}

int get_center(int x){
	dfn.clear();
	dfs(x, -1);
	int csize = 1e9, cpos = -1;
	for(auto &i : dfn){
		int t1 = max(size[x] - size[i], msize[i]);
		if(t1 < csize){
			csize = t1;
			cpos = i;
		}
	}
	return cpos;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	memset(ret, 0x3f, sizeof(ret));
	qry[1].emplace_back(1, 0);
	for(int i=1; i<=m; i++){
		int t, x;
		scanf("%d %d",&t, &x);
		if(t == 1) ret[i] = -1;
		qry[x].emplace_back(t, i);
	}
	queue<int> que;
	que.push(1);
	while(!que.empty()){
		int x = que.front();
		que.pop();
		x = get_center(x);
		vector<t1> query;
		for(auto &i : dfn){
			for(auto &j : qry[i]){
				query.push_back({i, j.first, j.second});
			}
		}
		sort(query.begin(), query.end(), [&](const t1 &a, const t1 &b){
			return a.time < b.time;
		});
		dep[x] = 0;
		dfs(x, -1);
		vis[x] = 1;
		int mindep = 1e9;
		for(auto &i : query){
			if(i.type == 1){
				mindep = min(mindep, dep[i.pos]);
			}
			else{
				ret[i.time] = min(ret[i.time], dep[i.pos] + mindep);
			}
		}
		for(auto &i : gph[x]){
			if(!vis[i]) que.push(i);
		}
	}
	for(int i=1; i<=m; i++){
		if(ret[i] != -1) printf("%d\n",ret[i]);
	}
}