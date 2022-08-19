#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 10;

struct mf{
	struct edg{ int pos, cap, rev, cost; };
vector<edg> gph[MAXN];
void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
void add_edge(int s, int e, int x, int c){
	gph[s].push_back({e, x, (int)gph[e].size(), c});
	gph[e].push_back({s, 0, (int)gph[s].size()-1, -c});
}
int phi[MAXN], inque[MAXN], dist[MAXN];
void prep(int src, int sink){
	memset(phi, 0x3f, sizeof(phi));
	memset(dist, 0x3f, sizeof(dist));
	queue<int> que;
	que.push(src);
	inque[src] = 1;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		inque[x] = 0;
		for(auto &i : gph[x]){
			if(i.cap > 0 && phi[i.pos] > phi[x] + i.cost){
				phi[i.pos] = phi[x] + i.cost;
				if(!inque[i.pos]){
					inque[i.pos] = 1;
					que.push(i.pos);
				}
			}
		}
	}
	for(int i=0; i<MAXN; i++){
		for(auto &j : gph[i]){
			if(j.cap > 0) j.cost += phi[i] - phi[j.pos];
		}
	}
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(pi(0, src));
	dist[src] = 0;
	while(!pq.empty()){
		auto l = pq.top();
		pq.pop();
		if(dist[l.second] != l.first) continue;
		for(auto &i : gph[l.second]){
			if(i.cap > 0 && dist[i.pos] > l.first + i.cost){
				dist[i.pos] = l.first + i.cost;
				pq.push(pi(dist[i.pos], i.pos));
			}
		}
	}
}
bool vis[MAXN];
int ptr[MAXN];
int dfs(int pos, int sink, int flow){
	vis[pos] = 1;
	if(pos == sink) return flow;
	for(; ptr[pos] < gph[pos].size(); ptr[pos]++){
		auto &i = gph[pos][ptr[pos]];
		if(!vis[i.pos] && dist[i.pos] == i.cost + dist[pos] && i.cap > 0){
			int ret = dfs(i.pos, sink, min(i.cap, flow));
			if(ret != 0){
				i.cap -= ret;
				gph[i.pos][i.rev].cap += ret;
				return ret;
			}
		}
	}
	return 0;
}
int match(int src, int sink, int sz = MAXN){
	prep(src, sink);
	for(int i=0; i<sz; i++) dist[i] += phi[sink] - phi[src];
	int ret = 0;
	while(true){
		memset(ptr, 0, sizeof(ptr));
		memset(vis, 0, sizeof(vis));
		int tmp = 0;
		while((tmp = dfs(src, sink, 1e9))){
			ret += dist[sink] * tmp;
			memset(vis, 0, sizeof(vis));
		}
		tmp = 1e9;
		for(int i=0; i<sz; i++){
			if(!vis[i]) continue;
			for(auto &j : gph[i]){
				if(j.cap > 0 && !vis[j.pos]){
					tmp = min(tmp, (dist[i] + j.cost) - dist[j.pos]);
				}
			}
		}
		if(tmp > 1e9 - 200) break;
		for(int i=0; i<sz; i++){
			if(!vis[i]) dist[i] += tmp;
		}
	}
	return ret;
}
}mf;

int f(int x, int y){
	if(x == y) return 0;
	if(x > y) return x * y;
	return -x * y;
}

int main(){
	int t; cin >> t;
	while(t--){
		mf.clear();
		int a[3], b[3];
		for(int i=0; i<3; i++) cin >> a[i];
		for(int i=0; i<3; i++) cin >> b[i];
		for(int i=0; i<3; i++){
			mf.add_edge(0, i + 1, a[i], 0);
			mf.add_edge(i + 4, 7, b[i], 0);
			for(int j=0; j<3; j++){
				mf.add_edge(i + 1, j + 4, 1e9, -f(i, j));
			}
		}
		printf("%d\n", -mf.match(0, 7));
	}
}