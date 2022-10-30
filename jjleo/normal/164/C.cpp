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

int costsum;// 

void addEdge(int u, int v, int w, int f){
	cnt++;
	edge[cnt].to = v;
	edge[cnt].val = w;
	edge[cnt].next = head[u];
	edge[cnt].cost = f;
	head[u] = cnt;
	
	cnt++;
	edge[cnt].to = u;
	edge[cnt].val = 0;
	edge[cnt].next = head[v];
	edge[cnt].cost = -f;
	head[v] = cnt;
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
			cur[v] = head[v];// 
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
	int nowflow = 0;// 
	if(u == t) return flow;
	for(int i = cur[u];i != -1;i = edge[i].next){
		cur[u] = i;//0    
		int v = edge[i].to;
		int w = edge[i].val;
		int f = edge[i].cost;
		if(d[v] == d[u] + f && w > 0 && !vis[v]){
			int k = dfs(v, min(flow-nowflow, w));
			if(k > 0){// 
				edge[i].val -= k;
				edge[i^1].val += k;
				nowflow += k;
				costsum += f * k;
				if(nowflow == flow) break;//   
			}
		}
	}
	vis[u] = 0;
	if(!nowflow) d[u] = inf;//
	return nowflow; 
}

int dinic(){
	int ans = 0;
	while(bfs()){
		ans += dfs(s, inf);
	}
	return ans;
}

int n, k;

struct Node{
	int x, y, z, i;
}a[maxn];

inline bool cmp(Node x, Node y){
	return x.x < y.x;
}

int id[maxn], ans[maxn];

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z), a[i].i = i;
	sort(a + 1, a + 1 + n, cmp);
	s = 0, t = n * 2 + 1;
	addEdge(s, 1, k, 0), addEdge(n, t, inf, 0);
	for(int i = 1;i <= n;i++){
		addEdge(i, i + n, 1, -a[i].z), id[i] = cnt;
		addEdge(i, i < n ? i + 1 : t, inf, 0);
		int x = t;
		for(int j = i + 1;j <= n;j++){
			if(a[j].x > a[i].x + a[i].y - 1){
				x = j;
				break;
			}
		}
		//printf("%d %d--\n", i, x);
		addEdge(i + n, x, inf, 0);
	}
	dinic();
	for(int i = 1;i <= n;i++) ans[a[i].i] = edge[id[i]].val;
	for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
}