#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
using lint = long long;
using pi = pair<lint, lint>;

struct maxflow{
	struct edg{ int pos; lint cap; int rev; };
	vector<edg> gph[MAXN];
	void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
	void add_edge(int s, int e, lint x){
		gph[s].push_back({e, x, (int)gph[e].size()});
		gph[e].push_back({s, 0, (int)gph[s].size()-1});
	}
	int dis[MAXN], pnt[MAXN];
	bool bfs(int src, int sink){
		memset(dis, 0, sizeof(dis));
		memset(pnt, 0, sizeof(pnt));
		queue<int> que;
		que.push(src);
		dis[src] = 1;
		while(!que.empty()){
			int x = que.front();
			que.pop();
			for(auto &e : gph[x]){
				if(e.cap > 0 && !dis[e.pos]){
					dis[e.pos] = dis[x] + 1;
					que.push(e.pos);
				}
			}
		}
		return dis[sink] > 0;
	}
	lint dfs(int x, int sink, lint f){
		if(x == sink) return f;
		for(; pnt[x] < gph[x].size(); pnt[x]++){
			edg e = gph[x][pnt[x]];
			if(e.cap > 0 && dis[e.pos] == dis[x] + 1){
				lint w = dfs(e.pos, sink, min(f, e.cap));
				if(w){
					gph[x][pnt[x]].cap -= w;
					gph[e.pos][e.rev].cap += w;
					return w;
				}
			}
		}
		return 0;
	}
	lint match(int src, int sink){
		lint ret = 0;
		while(bfs(src, sink)){
			int r;
			while((r = dfs(src, sink, 1e15))) ret += r;
		}
		return ret;
	}
}mf;

int n, m;
lint Esum, deg[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		mf.add_edge(0, i, 2 * x);
	}
	for(int i=1; i<=m; i++){
		int s, e, x; scanf("%d %d %d",&s,&e,&x);
		deg[s]+=x;
		deg[e]+=x;
		Esum+=x;
		mf.add_edge(s, e, x);
		mf.add_edge(e, s, x);
	}
	for(int i=1; i<=n; i++) mf.add_edge(i, n + 1, deg[i]);
	cout << (2 * Esum - mf.match(0, n + 1)) / 2 << endl;
}