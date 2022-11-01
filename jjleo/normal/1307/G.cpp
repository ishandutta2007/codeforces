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

vector<pair<int, int> > v;

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
		v.push_back({ans, costsum});
	}
	return ans;
}

int n, m;
int x, y, z;

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	s = 1, t = n;
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		addEdge(x, y, 1, z);
	}
	EK();
	scanf("%d", &m);
	while(m--){
		scanf("%d", &x);
		double ans = inf;
		for(int i = 0;i < v.size();i++) ans = min(ans, 1.0 * (v[i].second + x) / v[i].first);
		printf("%.10lf\n", ans);
	}
}