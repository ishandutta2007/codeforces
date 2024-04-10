#include <bits/stdc++.h>
#define maxn 300086 
using namespace std;

typedef long long ll; 

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

ll dfs(int u, ll flow){
	ll nowflow = 0;// 
	if(u == t) return flow;
	for(int i = cur[u];i != -1;i = edge[i].next){
		cur[u] = i;//0    
		int v = edge[i].to;
		int w = edge[i].val;
		if(d[v] == d[u] + 1 && w > 0){
			ll k = dfs(v, min(flow-nowflow, (ll)w));
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

ll dinic(){
	ll ans = 0;
	while(bfs()){
		ans += dfs(s, inf);
	}
	return ans;
}

int n, m;
int x, y, z;
ll ans;

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	s = 0, t = n + m + 1;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		addEdge(i, t, x);
	}
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &x, &y, &z);
		ans += z;
		addEdge(s, n + i, z);
		addEdge(n + i, x, inf);
		addEdge(n + i, y, inf);
	}
	printf("%lld", ans - dinic());
}