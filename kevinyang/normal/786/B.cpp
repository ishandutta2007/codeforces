#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>arr;
int sz;
void init(int n){
	sz = 1;
	while(sz<n)sz*=2;
}
vector<int>dis(1200000,(int)1e18);
vector<bool>vis(1200000);
vector<int>nodes;
void getnums(int l, int r, int x, int lx, int rx){
	if(lx>=l&&rx<=r){
		nodes.push_back(x);
		return;
	}
	if(lx>=r||l>=rx)return;
	int m = (lx+rx)/2;
	getnums(l,r,2*x+1,lx,m);
	getnums(l,r,2*x+2,m,rx);
}
vector<vector<pair<int,int>>>adj(1200000);
int getdis(int i, int x, int lx, int rx){
	if(rx-lx==1){
		return dis[x];
	}
	int m = (lx+rx)/2;
	if(i<m){
		return getdis(i,2*x+1,lx,m);
	}
	else{
		return getdis(i,2*x+2,m,rx);
	}
}
void build(int x, int lx, int rx){
	if(rx-lx==1){
		adj[x+2*sz].push_back({0,x});
		return;
	}
	adj[2*x+1].push_back({0,x});
	adj[2*x+2].push_back({0,x});
	adj[x+2*sz].push_back({0,2*x+1+2*sz});
	adj[x+2*sz].push_back({0,2*x+2+2*sz});
	int m = (lx+rx)/2;
	build(2*x+1,lx,m);
	build(2*x+2,m,rx);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q,s;
	cin >> n >> q >> s;
	init(n);
	build(0,0,sz);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	if(true){
		s--;
		getnums(s,s+1,0,0,sz);
		int start = nodes[0];
		nodes.clear();
		dis[start] = 0;
		pq.push({0,start});
	}
	for(int i = 0; i<q; i++){
		int cm;
		cin >> cm;
		if(cm==1){
			int x,y,w;
			cin >> x >> y >> w;
			x--; y--;
			getnums(x,x+1,0,0,sz);
			x = nodes[0];
			nodes.clear();
			getnums(y,y+1,0,0,sz);
			y = nodes[0];
			nodes.clear();
			adj[x].push_back({w,y});
		}
		else if(cm==2){
			int x,l,r,w;
			cin >> x >> l >> r >> w;
			x--; l--; r--;
			getnums(x,x+1,0,0,sz);
			x = nodes[0];
			nodes.clear();
			getnums(l,r+1,0,0,sz);
			for(int nxt: nodes){
				adj[x].push_back({w,2*sz+nxt});
			}
			nodes.clear();
		}
		else{
			int y,l,r,w;
			cin >> y >> l >> r >> w;
			y--; l--; r--;
			getnums(y,y+1,0,0,sz);
			y = nodes[0];
			nodes.clear();
			getnums(l,r+1,0,0,sz);
			for(int nxt: nodes){
				adj[nxt].push_back({w,y});
			}
			nodes.clear();
		}
	}
	while(pq.size()){
		pair<int,int>cur = pq.top(); pq.pop();
		if(vis[cur.second])continue;
		vis[cur.second] = true;
		for(pair<int,int>nxt: adj[cur.second]){
			if(dis[nxt.second]>dis[cur.second]+nxt.first){
				dis[nxt.second] = dis[cur.second]+nxt.first;
				pq.push({dis[nxt.second],nxt.second});
			}
		}
	}

	for(int i = 0; i<n; i++){
		int v = getdis(i,0,0,sz);
		if(v==(int)1e18)cout << "-1 ";
		else cout << v << " ";
	}
	return 0;
}