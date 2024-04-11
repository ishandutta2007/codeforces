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
int n, m, x;
const int MAXN = 55;
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
			if(ret >= x) break;
		}
		memset(vis,0,sizeof(vis));
		return ret;
	}
}maxflow;
int s[505], e[505], c[505];

int trial(double t){
	maxflow.init(n-1);
	for(int i=0; i<m; i++){
		maxflow.add_edge(s[i], e[i], min((long long)(c[i] / t), 1ll * x));
	}
	return maxflow.match_bfs();
}

int main(){
	scanf("%d %d %d",&n,&m,&x);
	for(int i=0; i<m; i++){
		cin >> s[i] >> e[i] >> c[i];
		s[i]--, e[i]--;
	}
	double s = 0, e = 1e6;
	for(int i=0; i<100; i++){
		double m = (s+e)/2;
		if(trial(m) >= x) s = m;
		else e = m;
	}
	printf("%.10f", s * x);
}