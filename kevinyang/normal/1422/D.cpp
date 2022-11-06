#include <bits/stdc++.h>
using namespace std;
#define int long long
int dist(pair<int,int>a, pair<int,int>b){
	return min(abs(a.first-b.first),abs(a.second-b.second));
}
int dist2(pair<int,int>a, pair<int,int>b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}
pair<int,int> rev(pair<int,int>a){
	return make_pair(a.second,a.first);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int sx,sy,fx,fy;
	cin >> sx >> sy >> fx >> fy;
	set<pair<int,int>>s;
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		s.insert({x,y});
	}
	m = s.size();
	vector<pair<int,int>>arr;
	for(pair<int,int>nxt: s){
		arr.push_back(nxt);
	}
	set<pair<int,int>>s2;
	for(int i = 0; i<m; i++){
		s2.insert(rev(arr[i]));
	}
	map<pair<int,int>,int>hm;
	for(int i = 0; i<m; i++){
		hm[arr[i]] = i+2;
	}
	vector<vector<pair<int,int>>>adj(m+5);
	for(int i = 0; i<m; i++){
		if(s.lower_bound(arr[i])!=s.begin()){
			pair<int,int>p = *--s.lower_bound(arr[i]);
			adj[hm[arr[i]]].push_back({dist(p,arr[i]),hm[p]});
		}
		if(s.upper_bound(arr[i])!=s.end()){
			pair<int,int>p = *s.upper_bound(arr[i]);
			adj[hm[arr[i]]].push_back({dist(p,arr[i]),hm[p]});
		}
		if(s2.lower_bound(rev(arr[i]))!=s2.begin()){
			pair<int,int>p = *--s2.lower_bound(rev(arr[i]));
			adj[hm[arr[i]]].push_back({dist(rev(p),arr[i]),hm[rev(p)]});
		}
		if(s2.upper_bound(rev(arr[i]))!=s2.end()){
			pair<int,int>p = *s2.upper_bound(rev(arr[i]));
			adj[hm[arr[i]]].push_back({dist(rev(p),arr[i]),hm[rev(p)]});
		}
		adj[1].push_back({dist(make_pair(sx,sy),arr[i]),hm[arr[i]]});
		adj[hm[arr[i]]].push_back({dist2(make_pair(fx,fy),arr[i]),m+2});
	}
	adj[1].push_back({dist2(make_pair(sx,sy),make_pair(fx,fy)),m+2});
	vector<int>dis(m+5,(int)1e18);
	dis[1] = 0;
	vector<bool>vis(m+5);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,1});
	while(!pq.empty()){
		pair<int,int>cur = pq.top(); pq.pop();
		if(vis[cur.second])continue;
		vis[cur.second] = true;
		for(pair<int,int>nxt: adj[cur.second]){
			if(dis[cur.second]+nxt.first<dis[nxt.second]){
				dis[nxt.second] = dis[cur.second]+nxt.first;
				pq.push({dis[nxt.second],nxt.second});
			}
		}
	}
	cout << dis[m+2] << "\n";
	return 0;
}