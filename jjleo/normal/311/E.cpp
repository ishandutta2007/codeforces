#include <bits/stdc++.h>
#define maxn 300086 
using namespace std;

const int inf = 0x3f3f3f3f;

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
	cnt++;
	edge[cnt].to = v;
	edge[cnt].val = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
	cnt++;
	edge[cnt].to = u;
	edge[cnt].val = 0;
	edge[cnt].next = head[v];
	head[v] = cnt;
}

bool bfs(){
	memset(d, -1, sizeof(d));
	//for(int i = 1;i <= n;i++) cur[i] = head[i];// 
	d[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];i != -1;i = edge[i].next){
			int v = edge[i].to;
			cur[v] = head[v];// 
			if(d[v] == -1 && edge[i].val > 0){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return d[t] != -1;
}

int dfs(int u, int flow){
	int nowflow = 0;// 
	if(u == t) return flow;
	for(int i = cur[u];i != -1;i = edge[i].next){
		cur[u] = i;//0    
		int v = edge[i].to;
		int w = edge[i].val;
		if(d[v] == d[u] + 1 && w > 0){
			int k = dfs(v, min(flow-nowflow, w));
			if(k > 0){// 
				edge[i].val -= k;
				edge[i^1].val += k;
				nowflow += k;
				if(nowflow == flow) break;//   
			}
		}
	}
	if(!nowflow) d[u] = -1;//
	return nowflow; 
}

int dinic(){
	int ans = 0;
	while(bfs()){
		ans += dfs(s, inf);
	}
	return ans;
}

int n, m, g;
bool a[maxn];
int w, x, y, z, sum;

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &g);
	s = 0, t = n + m + 1;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[i] ? addEdge(i, t, x) : addEdge(s, i, x);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &x, &w, &y), sum += w;
		while(y--){
			scanf("%d", &z);
			x ? addEdge(z, i + n, inf) : addEdge(i + n, z, inf);
		}
		scanf("%d", &y), w += y * g;
		x ? addEdge(i + n, t, w) : addEdge(s, i + n, w);
	}
	printf("%d", sum - dinic());
}