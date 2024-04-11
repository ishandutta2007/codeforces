#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 100;

struct mincostflow{
	struct edg{ int pos, cap, rev, cost; };
	vector<edg> gph[MAXN];

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
				if(i.cap > 0 && phi[i.pos]> phi[x] + i.cost){
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
				if(j.cap>0) j.cost += phi[i] - phi[j.pos];
			}
		}
		priority_queue<pi, vector<pi>, greater<pi> > pq;
		pq.push(pi(0, src));
		dist[src] = 0;
		while(!pq.empty()){
			auto x = pq.top(); pq.pop();
			if(dist[x.second] != x.first) continue;
			for(auto &i : gph[x.second]){
				if(i.cap > 0 && dist[i.pos] > x.first + i.cost){
					dist[i.pos] = x.first + i.cost;
					pq.push(pi(dist[i.pos], i.pos));
				}
			}
		}
	}

	bool vis[MAXN];
	int ptr[MAXN];

	int dfs(int pos, int sink, int flow){
		vis[pos] = 1;
		if(pos==sink) return flow;
		for(; ptr[pos] < gph[pos].size(); ptr[pos]++){
			edg &i = gph[pos][ptr[pos]];
			if(!vis[i.pos] && dist[i.pos] == i.cost + dist[pos] &&
				i.cap > 0){
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

	int match(int src, int sink){
		prep(src, sink);
		for(int i=0; i<=sink; i++) dist[i] += phi[sink] - phi[src];
		int ret = 0;
		while(dist[sink] < 0){
			memset(ptr, 0, sizeof(ptr));
			memset(vis, 0, sizeof(vis));
			int tmp = 0;
			while((tmp = dfs(src, sink, 1e9))){
				ret += dist[sink] * tmp;
				memset(vis, 0, sizeof(vis));
			}
			tmp = 1e9;
			for(int i=0; i<=sink; i++){
				if(vis[i]){
					for(auto &j : gph[i]){
						if(j.cap > 0 && !vis[j.pos]){
							tmp = min(tmp, dist[i] + j.cost - dist[j.pos]);
						}
					}
				}
			}
			if(tmp > 1e9 - 200) break;
			for(int i=0; i<=sink; i++) if(!vis[i]) dist[i] += tmp;
		}
		return ret;
	}
}mf;

pi a[MAXN];
int n, k, c[MAXN], d[MAXN];
int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	for(int i=0; i<n; i++) cin >> d[i+1];
	for(int i=0; i<n; i++) c[i] = d[a[i].first];
	sort(a, a+n);
	for(int i=1; i<=n; i++) mf.add_edge(i-1, i, k-1, 0);
	int ans = 0;
	for(int i=0; i<n; i++) ans += c[i];
	for(int i=1; i<n; i++){
		if(a[i-1].first == a[i].first){
			if(a[i-1].second + 1 == a[i].second) ans += -c[a[i].second];
			else mf.add_edge(a[i-1].second + 1, a[i].second, 1, -c[a[i].second]);
		}
	}
	cout << ans + mf.match(0, n);
}