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

vector<int> graph[100005];

int n, k;
bool vis[100005];

int size[100005], msize[100005];
vector<int> dfn;

int dfs(int x, int p){
	size[x] = 1;
	msize[x] = 1;
	dfn.push_back(x);
	for(int i=0; i<graph[x].size(); i++){
		int pos = graph[x][i];
		if(pos == p) continue;
		if(vis[pos]) continue;
		int t = dfs(pos, x);
		size[x] += t;
		msize[x] = max(msize[x], t);
	}
	return size[x];
}

int get_center(int x){
	dfn.clear();
	dfs(x, 0);
	int retp = 1e9, retv = -1;
	for(int i=0; i<dfn.size(); i++){
		int p = max(msize[dfn[i]], (int)dfn.size() - size[dfn[i]]);
		if(retp > p){
			retp = p;
			retv = dfn[i];
		}
	}
	return retv;
}

char ret[100005];

int main(){
	cin >> n;
	for(int i=0; i<n-1; i++){
		int s, e, x;
		scanf("%d %d",&s,&e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	queue<int> q, l;
	q.push(1);
	l.push(1);
	while(!q.empty()){
		int x = q.front();
		int cl = l.front();
		q.pop(), l.pop();
		x = get_center(x);
		vis[x] = 1;
		ret[x] = cl + 'A' - 1;
		for(int i=0; i<graph[x].size(); i++){
			if(!vis[graph[x][i]]){
				q.push(graph[x][i]);
				l.push(cl + 1);
			}
		}
	}
	for(int i=1; i<=n; i++){
		printf("%c ",ret[i]);
	}
}