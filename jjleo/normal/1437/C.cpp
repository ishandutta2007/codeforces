#include <bits/stdc++.h>
#define maxn 300086
using namespace std;

const int inf = 0x3f3f3f3f;

struct Edge{
	int to, val, next, cost;
}edge[maxn];

int s, t;
int cnt = -1;

int head[maxn];
queue<int> q;
int d[maxn];
int cur[maxn];
int inq[maxn]; 
int vis[maxn];

int costsum;

void addEdge(int u, int v, int w, int f){
	edge[++cnt] = (Edge){v, w, head[u], f}, head[u] = cnt;
	edge[++cnt] = (Edge){u, 0, head[v], -f}, head[v] = cnt;
}

bool bfs(){
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[s] = 0;
	q.push(s);
	inq[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = head[u];i != -1;i = edge[i].next){
			int v = edge[i].to;
			cur[v] = head[v];
			int f = edge[i].cost;
			if(d[v] > d[u] + f && edge[i].val > 0){
				d[v] = d[u] + f;
				if(!inq[v]){
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return d[t] != inf;
}

int dfs(int u, int flow){
	vis[u] = 1;
	int nowflow = 0;
	if(u == t) return flow;
	for(int i = cur[u];i != -1;i = edge[i].next){
		cur[u] = i;
		int v = edge[i].to;
		int w = edge[i].val;
		int f = edge[i].cost;
		if(d[v] == d[u] + f && w > 0 && !vis[v]){
			int k = dfs(v, min(flow - nowflow, w));
			if(k > 0){
				edge[i].val -= k;
				edge[i ^ 1].val += k;
				nowflow += k;
				costsum += f * k;
				if(nowflow == flow) break; 
			}
		}
	}
	vis[u] = 0;
	if(!nowflow) d[u] = inf;
	return nowflow; 
}

int dinic(){
	int ans = 0;
	while(bfs()){
		ans += dfs(s, inf);
	}
	return ans;
}

int T; 
int n, x;

int main(){
	scanf("%d", &T);
	while(T--){
		memset(head, -1, sizeof(head)), cnt = -1;
		scanf("%d", &n);
		s = n * 3 + 1, t = s + 1, costsum = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			for(int j = 1;j <= n * 2;j++) addEdge(i, j + n, 1, abs(x - j));
			addEdge(s, i, 1, 0), addEdge(2 * i - 1 + n, t, 1, 0), addEdge(2 * i + n, t, 1, 0);
		}
		dinic();
		printf("%d\n", costsum);
	}
}