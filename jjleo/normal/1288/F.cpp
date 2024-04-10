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

int n1, n2, m, r, b;
int x, y;
int val[maxn];
int id[maxn];

char S[maxn];
int sum;


int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d%d%d%d", &n1, &n2, &m, &r, &b);
	s = n1 + n2 + 1, t = n1 + n2 + 2;
	scanf("%s", S + 1);
	for(int i = 1;i <= n1;i++){
		if(S[i] == 'B'){
			addEdge(i, t, inf, 0), val[i]--, val[t]++;
		}else if(S[i] == 'R'){
			addEdge(s, i, inf, 0), val[s]--, val[i]++;
		}else{
			addEdge(s, i, inf, 0), addEdge(i, t, inf, 0);
		}
	} 
	scanf("%s", S + 1);
	for(int i = 1;i <= n2;i++){
		if(S[i] == 'R'){
			addEdge(i + n1, t, inf, 0), val[i + n1]--, val[t]++;
		}else if(S[i] == 'B'){
			addEdge(s, i + n1, inf, 0), val[s]--, val[i + n1]++;
		}else{
			addEdge(s, i + n1, inf, 0), addEdge(i + n1, t, inf, 0);
		}
	} 
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &x, &y);
		addEdge(x, y + n1, 1, r), addEdge(y + n1, x, 1, b);
		id[i] = cnt;
	}
	addEdge(t, s, inf, 0);
	s += 2, t += 2; 
	for(int i = 1;i <= n1 + n2 + 2;i++){
		if(val[i] > 0) addEdge(s, i, val[i], 0), sum += val[i];
		else if(val[i] < 0) addEdge(i, t, -val[i], 0); 
	}
	if(dinic() != sum) return printf("-1"), 0;
	printf("%d\n", costsum);
	for(int i = 1;i <= m;i++){
		if(edge[id[i]].val) printf("B");
		else if(edge[id[i] - 2].val) printf("R");
		else printf("U");
	}
}