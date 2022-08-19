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

const int MAXN = 205;
struct maxflow{
	struct edg{int pos, cap, rev;};
	vector<edg> graph[MAXN];

	int end;

	void init(int x){
		end = x;
		for(int i=0; i<MAXN; i++){
			graph[i].clear();
		}
	}
	 
	void add_edge(int s, int e, int x){
		graph[s].push_back({e, x, (int)graph[e].size()});
		graph[e].push_back({s, 0, (int)graph[s].size()-1});
	}
	 
	bool vis[MAXN];
	int pa[MAXN], pe[MAXN];
	 
	int dfs(int x){
		if(x == end) return 1;
		if(vis[x]) return 0;
		vis[x] = 1;
		for(int i=0; i<graph[x].size(); i++){
			edg e = graph[x][i];
			if(e.cap > 0 && dfs(e.pos)){
				pa[e.pos] = x;
				pe[e.pos] = i;
				return 1;
			}
		}
		return 0;
	}
	
	queue<int> q;
	int bfs(int x){
		q.push(x);
		vis[x] = 1;
		while(!q.empty()){
			x = q.front(); q.pop();
			for(int i=0; i<graph[x].size(); i++){
				edg e = graph[x][i];
				if(e.cap > 0 && !vis[e.pos]){
					vis[e.pos] = 1;
					pa[e.pos] = x;
					pe[e.pos] = i;
					q.push(e.pos);
				}
			}
		}
		return vis[end];
	}

	int match_dfs(){
		int ret = 0;
		while(dfs(0)){
			memset(vis,0,sizeof(vis));
			for(int pos = end; pos; pos = pa[pos]){
				int rev = graph[pa[pos]][pe[pos]].rev;
				graph[pa[pos]][pe[pos]].cap--;
				graph[pos][rev].cap++;
			}
			ret++;
		}
		memset(vis,0,sizeof(vis));
		return ret;
	}

	int match_bfs(){
		int ret = 0;
		while(bfs(0)){
			memset(vis,0,sizeof(vis));
			int minv = 1e9;
			for(int pos = end; pos; pos = pa[pos]){
				minv = min(minv, graph[pa[pos]][pe[pos]].cap);
			}
			for(int pos = end; pos; pos = pa[pos]){
				int rev = graph[pa[pos]][pe[pos]].rev;
				graph[pa[pos]][pe[pos]].cap -= minv;
				graph[pos][rev].cap += minv;
			}
			ret += minv;
		}
		memset(vis,0,sizeof(vis));
		return ret;
	}
}maxflow;

int n, a[205];
vector<int> gph[205];
vector<int> dfn;
bool vis[205];

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	dfn.push_back(x);
	for(auto &i : gph[x]){
		dfs(i);
	}
}

bool isprime(int x){
	for(int i=2; i*i<=x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}
int main(){
	cin >> n;
	maxflow.init(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] % 2 == 0) maxflow.add_edge(0, i, 2);
		else maxflow.add_edge(i, n+1, 2);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i] % 2 == 0 && a[j] % 2 == 1 && isprime(a[i] + a[j])){
				maxflow.add_edge(i, j, 1);
			}
		}
	}
	if(maxflow.match_bfs() != n){
		cout << "Impossible";
		return 0;
	}
	for(int i=1; i<=n; i++){
		for(auto &j : maxflow.graph[i]){
			if(a[i] % 2 == 0 && j.cap == 0 && j.pos != n+1 && j.pos != 0){
				gph[i].push_back(j.pos);
				gph[j.pos].push_back(i);
			}
		}
	}
	vector<vector<int>> ret;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfn.clear();
			dfs(i);
			ret.push_back(dfn);
		}
	}
	printf("%d\n",ret.size());
	for(auto &i : ret){
		printf("%d ",i.size());
		for(auto &j : i){
			printf("%d ",j);
		}
		puts("");
	}
}