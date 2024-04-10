#include <bits/stdc++.h>
#define maxn 100086

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

int n, m, K;
int x, y;
bool match[maxn], vis[maxn];
vector<int> v, w[maxn];
ll f[105][105];
int g[105][105];

void Dfs(int i){
	if(vis[i]) return;
	vis[i] = true;
	for(int j = head[i];~j;j = edge[j].next){
		int to = edge[j].to;
		if(to == s || to == t) continue;
		if(match[i] && match[to] && edge[j].val && i > to) Dfs(to);
		else if(i < to) Dfs(to);
	}
}

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &K);
	s = n * 2 + 1, t = s + 1;
	for(int i = 1;i <= n;i++) addEdge(s, i, 1), addEdge(i + n, t, 1);
	while(m--){
		scanf("%d%d", &x, &y);
		addEdge(x, y + n, 1);
	}
	dinic();
	for(int i = head[s];~i;i = edge[i].next) match[edge[i].to] = !edge[i].val;
	for(int i = head[t];~i;i = edge[i].next) match[edge[i].to] = edge[i].val;
	for(int i = 1;i <= n;i++) if(!match[i]) Dfs(i);
	for(int i = 1;i <= n;i++) if(match[i] && !vis[i]) v.push_back(i);
	for(int i = 1;i <= n;i++) if(match[i + n] && vis[i + n]) v.push_back(-i);
	memset(f, -0x3f, sizeof(f)), f[0][0] = 0;
	for(int i = 1;i <= K;i++){
		scanf("%d%d", &x, &y);
		for(int j = max(0, (int)v.size() - n + i + 1);j <= v.size();j++){
			for(int k = 0;k <= j;k++){
				ll val = f[i - 1][j - k] + max(0ll, x - 1ll * k * y);
				if(val > f[i][j]) f[i][j] = val, g[i][j] = k;
			}
		}
	}
	int j = 0;
	for(int i = 1;i <= v.size();i++) if(f[K][i] > f[K][j]) j = i;
	int ans = K;
	for(int i = K;i;i--){
		for(int k = 1;k <= g[i][j];k++) w[i].push_back(v.back()), v.pop_back(), ans++;
		j -= g[i][j];
	}
	printf("%d\n", ans);
	for(int i = 1;i <= K;i++){
		for(int j = 0;j < w[i].size();j++) printf("%d ", w[i][j]);
		printf("0 ");
	}
	
}