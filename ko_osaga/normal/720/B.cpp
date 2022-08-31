#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

const int MAXN = 50005;
struct maxflow{
	struct edg{int pos, cap, rev;};
	vector<edg> gph[MAXN];

	void clear(){
		for(int i=0; i<MAXN; i++){
			gph[i].clear();
		}
	}

	void add_edge(int s, int e, int x){
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
			for(int i=0; i<gph[x].size(); i++){
				edg e = gph[x][i];
				if(e.cap > 0 && !dis[e.pos]){
					dis[e.pos] = dis[x] + 1;
					que.push(e.pos);
				}
			}
		}
		return dis[sink] > 0;
	}

	int dfs(int x, int sink, int f){
		if(x == sink) return f;
		for(; pnt[x] < gph[x].size(); pnt[x]++){
			edg e = gph[x][pnt[x]];
			if(e.cap > 0 && dis[e.pos] == dis[x] + 1){
				int w = dfs(e.pos, sink, min(f, e.cap));
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
			while((r = dfs(src, sink, 2e9))) ret += r;
		}
		return ret;
	}
}maxflow;

int n, m;

vector<pi> gph[10005];
vector<vector<int> > cyc;
vector<int> tree;
int par[10005], pac[10005], vis[10005], chk[10050];
bool instk[10005];

void dfs(int x, int p){
	vis[x] = 1;
	instk[x] = 1;
	for(auto &i : gph[x]){
		if(i.first == p) continue;
		if(vis[i.first] && instk[i.first]){
			vector<int> nc;
			nc.push_back(i.second);
			for(int j=x; j!=i.first; j=par[j]){
				chk[j] = 1;
				nc.push_back(pac[j]);
			}
			cyc.push_back(nc);
		}
		else if(!vis[i.first]){
			par[i.first] = x;
			pac[i.first] = i.second;
			dfs(i.first, x);
		}
	}
	instk[x] = 0;
}

int preocc[50005];

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e, x;
		cin >> s >> e >> x;
		gph[s].push_back({e, x});
		gph[e].push_back({s, x});
	}
	dfs(1, 0);
	for(int i=2; i<=n; i++){
		if(!chk[i]) tree.push_back(pac[i]);
	}
	int cn = cyc.size();
	int ret = 0;
	for(auto &j : tree){
		if(!preocc[j]) ret++;
		preocc[j] = 1;
	}
	for(int i=0; i<cyc.size(); i++){
		maxflow.add_edge(0, i+1, cyc[i].size() - 1);
		for(auto &j : cyc[i]){
			if(!preocc[j]) maxflow.add_edge(i+1, j + cn, 1);
		}
	}
	for(int i=1; i<=m; i++){
		maxflow.add_edge(i + cn, m + 1 + cn, 1);
	}
	cout <<ret +  maxflow.match(0, m + 1 + cn);
}