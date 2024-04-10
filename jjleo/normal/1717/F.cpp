#include <bits/stdc++.h>
#define maxn 10086

using namespace std;

const int inf = 0x3f3f3f3f;

struct Edge{
	int to, val, next;
}edge[maxn * 30];

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

int val[maxn];

void addEdge(int u, int v, int l, int r){
	addEdge(u, v, r - l);
	val[u] -= l, val[v] += l;
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

bool cal(int n){
	addEdge(t, s, 0, inf);
	int sum = 0, S = s, T = t;
	s = n + 1, t = n + 2;
	for(int i = 1;i <= n;i++){
		if(val[i] > 0) addEdge(s, i, val[i]), sum += val[i];
		else addEdge(i, t, -val[i]);
	}
	int ans = dinic();
	s = S, t = T;
	return ans == sum;
}

int n, m;
int a[maxn], b[maxn];
int u[maxn], v[maxn];

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &u[i], &v[i]);
		b[u[i]]--, b[v[i]]++;
	}
	for(int i = 1;i <= n;i++) if(a[i] && (b[i] & 1)) return printf("NO"), 0;
	s = n + 1, t = n + 2;
	for(int i = 1;i <= n;i++){
		b[i] /= 2;
		if(a[i]){
			if(b[i] > 0) addEdge(i, t, b[i], b[i]);
			else if(b[i] < 0) addEdge(s, i, -b[i], -b[i]);
		}else{
			addEdge(s, i, 0, m), addEdge(i, t, 0, m);
		}
	}
	for(int i = 1;i <= m;i++){
		addEdge(u[i], v[i], 0, 1);
	}
	if(!cal(t)) return printf("NO"), 0;
	dinic();
	puts("YES");
	for(int i = 1;i <= m;i++){
		for(int j = head[u[i]];~j;j = edge[j].next){
			if(edge[j].to == v[i]){
				if(edge[j].val == 0) printf("%d %d\n", u[i], v[i]);
				else printf("%d %d\n", v[i], u[i]);
				break;
			}
		}
	}
}