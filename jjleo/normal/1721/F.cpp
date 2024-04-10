#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

const int inf = 0x3f3f3f3f;

struct Edge{
	int to, val, next;
}edge[maxn * 4];

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

int n1, n2, m, Q;
map<pair<int, int>, int> mp;
pair<int, int> e[maxn];
bool vis[maxn], tag[maxn];

void dfs(int i){
	if(vis[i]) return;
	vis[i] = true;
	for(int j = head[i];~j;j = edge[j].next){
		if(edge[j].val) dfs(edge[j].to);
	}
}

vector<pair<int, int> > v;

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d%d%d", &n1, &n2, &m, &Q);
	s = n1 + n2 + 1, t = s + 1;
	for(int i = 1;i <= m;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		y += n1;
		mp[{x, y}] = mp[{y, x}] = i;
		e[i] = {x, y};
		addEdge(x, y, inf);
	}
	for(int i = 1;i <= n1;i++) addEdge(s, i, 1);
	for(int i = 1;i <= n2;i++) addEdge(i + n1, t, 1);
	int ans1 = dinic();
	dfs(s);
	for(int i = 1;i <= n1;i++) tag[i] = !vis[i];
	for(int i = n1 + 1;i <= n1 + n2;i++) tag[i] = vis[i];
	memset(head, -1, sizeof(head)), cnt = -1;
	for(int i = 1;i <= m;i++){
		int x = e[i].first, y = e[i].second;
		if(tag[y]) swap(x, y);
		if(tag[x] && !tag[y]) addEdge(x, y, 1);
	}
	for(int i = 1;i <= n1 + n2;i++){
		if(tag[i]) addEdge(s, i, 1);
		else addEdge(i, t, 1);
	}
	int ans2 = dinic();
	assert(ans1 == ans2);
	for(int i = 1;i <= n1 + n2;i++) if(tag[i]){
		for(int j = head[i];~j;j = edge[j].next){
			if(edge[j].val == 0){
				v.push_back({i, mp[{i, edge[j].to}]});
				break;
			}
		}
	}
	long long sum = 0;
	for(auto it : v) sum += it.second;
	while(Q--){
		int opt;
		scanf("%d", &opt);
		if(opt == 1){
			puts("1"), fflush(stdout);
			printf("%d\n", v.back().first <= n1 ? v.back().first : -(v.back().first - n1)), fflush(stdout);
			sum -= v.back().second;
			v.pop_back();
			printf("%lld\n", sum), fflush(stdout);
		}else{
			printf("%d\n", v.size()), fflush(stdout);
			for(auto it : v) printf("%d ", it.second);puts(""), fflush(stdout);
		}
	}
}