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
	edge[++cnt] = (Edge){v, w, head[u], f}, head[u] = cnt;
	edge[++cnt] = (Edge){u, 0, head[v], -f}, head[v] = cnt;
}

int from[maxn];

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
				d[v] = d[u] + f, from[v] = i;
				if(!inq[v]){
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return d[t] != inf;
}


int EK(){
	int ans = 0;
	while(bfs()){
		int flow = inf;
		for(int i = t;i ^ s;i = edge[from[i] ^ 1].to) flow = min(flow, edge[from[i]].val);
		ans += flow;
		for(int i = t;i ^ s;i = edge[from[i] ^ 1].to){
			edge[from[i]].val -= flow, edge[from[i] ^ 1].val += flow;
			costsum += flow * edge[from[i]].cost;
		}
	}
	return ans;
}

int n, m, k;
int x;
vector<int> v[2];

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &k);
	int P = n + 1, S = n + 2;
	s = n + 3, t = n + 4;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		addEdge(i, P, 1, -x);
		addEdge(s, i, 1, 0);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		addEdge(i, S, 1, -x);
	}
	addEdge(P, t, m, 0), addEdge(S, t, k, 0);
	EK();
	printf("%d\n", -costsum);
	for(int i = head[P];~i;i = edge[i].next){
		if(edge[i].to <= n && edge[i].val) v[0].push_back(edge[i].to);
	}
	for(int i = head[S];~i;i = edge[i].next){
		if(edge[i].to <= n && edge[i].val) v[1].push_back(edge[i].to);
	}
	for(int i = 0;i < v[0].size();i++) printf("%d ", v[0][i]);
	puts("");
	for(int i = 0;i < v[1].size();i++) printf("%d ", v[1][i]);
}