#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 200005;

int adj[123][123];
int dist[123];

int bfs(int x, int y){
	memset(dist, 0x3f, sizeof(dist));
	dist[x] = 0;
	queue<int> que; que.push(x);
	while(!que.empty()){
		int x = que.front(); que.pop();
		for(int i=0; i<123; i++){
			if(dist[i] > dist[x] + adj[x][i]){
				dist[i] = dist[x] + adj[x][i];
				que.push(i);
			}
		}
	}
	return dist[y];
}

vector<int> bt[69];
int n;
lint a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%lld",&a[i]);
		for(int j=0; j<60; j++){
			if((a[i] >> j) & 1){
				bt[j].push_back(i);
			}
		}
	}
	vector<pi> edg;
	vector<int> vtx;
	for(int i=0; i<60; i++){
		if(bt[i].size() >= 3){
			puts("3");
			return 0;
		}
		if(bt[i].size() == 2){
			edg.emplace_back(bt[i][0], bt[i][1]);
			vtx.push_back(bt[i][0]);
			vtx.push_back(bt[i][1]);
		}
	}
	sort(edg.begin(), edg.end());
	edg.resize(unique(edg.begin(), edg.end()) - edg.begin());
	sort(vtx.begin(), vtx.end());
	vtx.resize(unique(vtx.begin(), vtx.end()) - vtx.begin());
	for(auto &i : edg){
		i.first = lower_bound(vtx.begin(), vtx.end(), i.first) - vtx.begin();
		i.second = lower_bound(vtx.begin(), vtx.end(), i.second) - vtx.begin();
	}
	int ret = 1e9;
	for(int i=0; i<edg.size(); i++){
		memset(adj, 0x3f, sizeof(adj));
		for(int j=0; j<edg.size(); j++){
			if(j == i) continue;
			adj[edg[j].first][edg[j].second] = 1;
			adj[edg[j].second][edg[j].first] = 1;
		}
		ret = min(ret, bfs(edg[i].first, edg[i].second));
	}
	ret++;
	if(ret > 1e8) ret = -1;
	cout <<  ret << endl;
}