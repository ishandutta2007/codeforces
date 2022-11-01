#include <bits/stdc++.h>
#define maxn 300086 
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f3f3f3f3f;

struct Edge{
	int to, val, next;
}edge[maxn];

int s, t;
int cnt = -1;

int head[maxn];
queue<int> q;
int d[maxn];
int cur[maxn];

void addEdge(int u, int v, int w){
	edge[++cnt] = (Edge){v, w, head[u]}, head[u] = cnt;
	edge[++cnt] = (Edge){u, 0, head[v]}, head[v] = cnt;
}

bool bfs(){
	memset(d, -1, sizeof(d));
	d[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];i != -1;i = edge[i].next){
			int v = edge[i].to;
			cur[v] = head[v];
			if(d[v] == -1 && edge[i].val){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return d[t] != -1;
}

int dfs(int u, int flow){
	int nowflow = 0;
	if(u == t) return flow;
	for(int i = cur[u];~i;i = edge[i].next){
		cur[u] = i;
		int v = edge[i].to;
		int w = edge[i].val;
		if(d[v] == d[u] + 1 && w > 0){
			int k = dfs(v, min(flow - nowflow, w));
			if(k){
				edge[i].val -= k;
				edge[i ^ 1].val += k;
				nowflow += k;
				if(nowflow == flow) break;
			}
		}
	}
	if(!nowflow) d[u] = -1;
	return nowflow; 
}

int dinic(){
	int ans = 0;
	while(bfs()){
		ans += dfs(s, inf);
	}
	return ans;
}

int n;
int x[maxn], y[maxn], w[maxn];

signed main(){
	memset(head, -1, sizeof(head));
	scanf("%lld", &n);
	s = n * 2 + 1, t = s + 1;
	int ans = 0;
	for(int i = 1;i <= n;i++) scanf("%lld%lld%lld", &x[i], &y[i], &w[i]), ans += w[i];
	for(int i = 1;i <= n;i++){
		addEdge(i, i + n, w[i]);
		if((x[i] & 1) && !(y[i] & 1)) addEdge(s, i, inf);
		else if((x[i] & 1) && (y[i] & 1)) addEdge(i + n, t, inf);
		for(int j = 1;j <= n;j++){
			if(abs(x[i] - x[j]) + abs(y[i] - y[j]) != 1) continue;
			if((x[i] & 1) && !(y[i] & 1) && !(x[j] & 1) && !(y[j] & 1)) addEdge(i + n, j, inf);
			else if(!(x[i] & 1) && !(y[i] & 1) && !(x[j] & 1) && (y[j] & 1)) addEdge(i + n, j, inf);
			else if(!(x[i] & 1) && (y[i] & 1) && (x[j] & 1) && (y[j] & 1)) addEdge(i + n, j, inf);
		}
	}
	printf("%lld", ans - dinic());
}