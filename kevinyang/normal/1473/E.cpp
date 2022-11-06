#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>>adj(n+1);
	for(int i = 1; i<=m; i++){
		int x,y,w;
		cin >> x >> y >> w;
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
	}
	vector<vector<bool>>vis(n+1,vector<bool>(4));
	vector<vector<int>>dis(n+1,vector<int>(4,(int)1e18));
	dis[1][0] = 0;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	pq.push({0,{1,0}});
	while(pq.size()){
		auto p = pq.top(); pq.pop();
		if(vis[p.second.first][p.second.second])continue;
		vis[p.second.first][p.second.second] = true;
		for(int d = 0; d<4; d++){
			if((p.second.second&1)&&!(d&1))continue;
			if((p.second.second&2)&&!(d&2))continue;
			for(pair<int,int>nxt: adj[p.second.first]){
				int extra = 0;
				if(!(p.second.second&1)&&(d&1))extra-=nxt.first;
				if(!(p.second.second&2)&&(d&2))extra+=nxt.first;
				int dist = p.first+extra+nxt.first;
				if(dis[nxt.second][d]>dist){
					dis[nxt.second][d] = dist;
					pq.push({dist,{nxt.second,d}});
				}	
			}
		}
	}
	for(int i = 2; i<=n; i++){
		cout << dis[i][3] << " ";
	}
	cout << "\n";
	return 0;
}