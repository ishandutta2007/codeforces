#include <bits/stdc++.h>
#define maxn 6000086 
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
	edge[++cnt] = (Edge){v, w, head[u]}, head[u] = cnt;
	edge[++cnt] = (Edge){u, 0, head[v]}, head[v] = cnt;
}

bool bfs(){
	for(int i = 1;i <= t;i++) d[i] = -1;
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

int T, n;
int a[maxn], id[maxn];
vector<int> D[maxn]; 

int main(){
	for(int i = 1;i <= 5e4;i++) for(int j = i;j <= 5e4;j += i) D[j].push_back(i);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1;i <= n * 4 + 2;i++) head[i] = -1;
		cnt = -1;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), id[a[i]] = i;
		for(int i = 1;i <= n;i++) for(int j = 0;j < D[a[i]].size();j++){
			int x = D[a[i]][j];
			if(id[x]){
				if(a[i] ^ x) addEdge(id[x], i + n * 2, 1), addEdge(id[x] + n, i + n * 3, 1);
				addEdge(id[x], i + n * 3, 1);
			}
		}
		s = n * 4 + 1, t = s + 1;
		for(int i = 1;i <= n * 2;i++) addEdge(s, i, 1), addEdge(i + n * 2, t, 1);
		for(int i = 1;i <= n;i++) id[a[i]] = 0;
		printf("%d\n", n - (n * 2 - dinic()));
	}
	
}