#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

const int MAXN = 2016;
struct mincostflow{
	struct edg{ int pos, cap, rev, cost, idx; };
	vector<edg> gph[MAXN];

	void clear(){
		for(int i=0; i<MAXN; i++) gph[i].clear();
	}

	void add_edge(int s, int e, int x, int c, int i){
		gph[s].push_back({e, x, (int)gph[e].size(), c, i});
		gph[e].push_back({s, 0, (int)gph[s].size()-1, -c, -1});
	}

	int dist[MAXN], pa[MAXN], pe[MAXN];
	bool inque[MAXN];

	bool spfa(int src, int sink){
		bool ok = 0;
		memset(dist, 0x3f, sizeof(dist));
		queue<int> que;
		dist[src] = 0;
		inque[src] = 1;
		que.push(src);
		while(!que.empty()){
			int x = que.front();
			que.pop();
			if(x == sink) ok = 1;
			inque[x] = 0;
			for(int i=0; i<gph[x].size(); i++){
				edg e = gph[x][i];
				if(e.cap > 0 && dist[e.pos] > dist[x] + e.cost){
					dist[e.pos] = dist[x] + e.cost;
					pa[e.pos] = x;
					pe[e.pos] = i;
					if(!inque[e.pos]){
						inque[e.pos] = 1;
						que.push(e.pos);
					}
				}
			}
		}
		return ok;
	}

	int match(int src, int sink){
		int ret = 0;
		while(spfa(src, sink)){
			int cap = 1e9;
			for(int pos = sink; pos != src; pos = pa[pos]){
				cap = min(cap, gph[pa[pos]][pe[pos]].cap);
			}
			ret += dist[sink] * cap;
			for(int pos = sink; pos != src; pos = pa[pos]){
				int rev = gph[pa[pos]][pe[pos]].rev;
				gph[pa[pos]][pe[pos]].cap -= cap;
				gph[pos][rev].cap += cap;
			}
		}
		return ret;
	}
}mcmf;

vector<int> v;

int n, k, s[1005], e[1005], x[1005];
int used[1005];

int main(){
	v.push_back(0);
	v.push_back(2e9 + 10);
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> s[i] >> e[i] >> x[i];
		e[i] += s[i];
		v.push_back(s[i]);
		v.push_back(e[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i=0; i<n; i++){
		s[i] = lower_bound(v.begin(), v.end(), s[i]) - v.begin();
		e[i] = lower_bound(v.begin(), v.end(), e[i]) - v.begin();
	}
	for(int i=0; i<v.size()-1; i++){
		mcmf.add_edge(i, i+1, k, 0, -1);
	}
	for(int i=0; i<n; i++){
		mcmf.add_edge(s[i], e[i], 1, -x[i], i);
	}
	mcmf.match(0, v.size()-1);
	for(int i=0; i<v.size(); i++){
		for(auto &j : mcmf.gph[i]){
			if(~j.idx){
				used[j.idx] = (j.cap ? 0 : 1);
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%d ", used[i]);
	}
}