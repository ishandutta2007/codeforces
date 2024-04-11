#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210;

struct maxflow{
	struct edg{int pos, cap, rev;};
	vector<edg> gph[MAXN];
	int n;

	void init(int _n){
		n = _n;
		for(int i=0; i<MAXN; i++) gph[i].clear();
	}
	  
	void add_edge(int s, int e, int x){
		gph[s].push_back({e, x, (int)gph[e].size()});
		gph[e].push_back({s, 0, (int)gph[s].size()-1});
	}
	  
	int pa[MAXN], pe[MAXN];

	bool bfs(){
		bool vis[MAXN] = {};
		queue<int> que;
		que.push(0);
		vis[0] = 1;
		while(!que.empty()){
			int x = que.front(); 
			que.pop();
			for(int i=0; i<gph[x].size(); i++){
				edg e = gph[x][i];
				if(e.cap > 0 && !vis[e.pos]){
					vis[e.pos] = 1;
					pa[e.pos] = x;
					pe[e.pos] = i;
					que.push(e.pos);
				}
			}
		}
		return vis[n];
	}
 
	int match(){
		int ret = 0;
		while(bfs()){
			int minv = 1e9;
			for(int pos = n; pos; pos = pa[pos]){
				minv = min(minv, gph[pa[pos]][pe[pos]].cap);
			}
			for(int pos = n; pos; pos = pa[pos]){
				int rev = gph[pa[pos]][pe[pos]].rev;
				gph[pa[pos]][pe[pos]].cap -= minv;
				gph[pos][rev].cap += minv;
			}
			ret += minv;
		}
		return ret;
	}

	int getcap(int x, int y){
		for(auto &i : gph[x]){
			if(i.pos == y) return i.cap;
		}
		return 0;
	}
}maxflow;
 
set<int> soinsu;
int n, m, a[105], s[105], e[105];

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		int v = a[i];
		for(int i=2; i*i<=v; i++){
			if(v % i == 0){
				soinsu.insert(i);
				while(v % i == 0) v /= i;
			}
		}
		if(v != 1) soinsu.insert(v);
	}
	for(int i=0; i<m; i++){
		cin >> s[i] >> e[i];
		if(s[i] % 2 == 1) swap(s[i], e[i]);
	}
	int ret = 0;
	for(auto &i : soinsu){
		maxflow.init(n+1);
		for(int j=1; j<=n; j++){
			int cnt = 0, v = a[j];
			while(v % i == 0) v /= i, cnt++;
			if(j % 2 == 0) maxflow.add_edge(0, j, cnt);
			else maxflow.add_edge(j, n+1, cnt);
		}
		for(int i=0; i<m; i++){
			maxflow.add_edge(s[i], e[i], 100);
		}
		ret += maxflow.match();
	}
	cout << ret;
}