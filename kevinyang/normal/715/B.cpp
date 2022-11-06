#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,len,s,t;
	cin >> n >> m >> len >> s >> t; s++; t++;
	vector<pair<int,int>>pending;
	vector<vector<pair<int,int>>>adj(n+1);
	for(int i = 0; i<m; i++){
		int x,y,w;
		cin >> x >> y >> w;
		x++; y++;
		if(w>0){
			adj[x].push_back({w,y});
			adj[y].push_back({w,x});
		}
		else{
			pending.push_back({x,y});
		}
	}
	if(pending.size()==0){
		vector<vector<pair<int,int>>>adj2(n+1);
		for(int i = 1; i<=n; i++){
			for(auto nxt: adj[i]){
				adj2[i].push_back(nxt);
			}
		}		
		vector<bool>vis(n+1);
		vector<int>dis(n+1,(int)2e9);
		dis[s] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,s});
		while(pq.size()){
			auto p = pq.top(); pq.pop();
			if(vis[p.second])continue;
			vis[p.second] = true;
			for(auto nxt: adj2[p.second]){
				if(nxt.first+dis[p.second]<dis[nxt.second]){
					dis[nxt.second] = nxt.first+dis[p.second];
					pq.push({dis[nxt.second],nxt.second});
				}
			}
		}
		if(dis[t]==len){
			cout << "YES\n";
			for(int i = 1; i<=n; i++){
				for(auto nxt: adj[i]){
					if(nxt.second>i){
						cout << i-1 << " " << nxt.second-1 << " " << nxt.first << "\n";
					}
				}
			}
			return 0;
		}
		else{
			cout << "NO\n";
			return 0;
		}
	}
	if(true){
		vector<vector<pair<int,int>>>adj2(n+1);
		for(int i = 1; i<=n; i++){
			for(auto nxt: adj[i]){
				adj2[i].push_back(nxt);
			}
		}		
		vector<bool>vis(n+1);
		vector<int>dis(n+1,(int)2e9);
		dis[s] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,s});
		while(pq.size()){
			auto p = pq.top(); pq.pop();
			if(vis[p.second])continue;
			vis[p.second] = true;
			for(auto nxt: adj2[p.second]){
				if(nxt.first+dis[p.second]<dis[nxt.second]){
					dis[nxt.second] = nxt.first+dis[p.second];
					pq.push({dis[nxt.second],nxt.second});
				}
			}
		}
		if(dis[t]<len){
			cout << "NO\n";
			return 0;
		}
	}
	if(true){
		vector<vector<pair<int,int>>>adj2(n+1);
		for(int i = 1; i<=n; i++){
			for(auto nxt: adj[i]){
				adj2[i].push_back(nxt);
			}
		}
		for(auto nxt: pending){
			adj2[nxt.first].push_back({1,nxt.second});
			adj2[nxt.second].push_back({1,nxt.first});
		}
		vector<bool>vis(n+1);
		vector<int>dis(n+1,(int)2e9);
		dis[s] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,s});
		while(pq.size()){
			auto p = pq.top(); pq.pop();
			if(vis[p.second])continue;
			vis[p.second] = true;
			for(auto nxt: adj2[p.second]){
				if(nxt.first+dis[p.second]<dis[nxt.second]){
					dis[nxt.second] = nxt.first+dis[p.second];
					pq.push({dis[nxt.second],nxt.second});
				}
			}
		}
		if(dis[t]>len){
			cout << "NO\n";
			return 0;
		}
	}
	pair<int,int>use = {0,0};
	while(true){
		vector<vector<pair<int,int>>>adj2(n+1);
		for(int i = 1; i<=n; i++){
			for(auto nxt: adj[i]){
				adj2[i].push_back(nxt);
			}
		}
		if(true){
			auto nxt = pending.back();
			adj2[nxt.first].push_back({1,nxt.second});
			adj2[nxt.second].push_back({1,nxt.first});
		}
		vector<bool>vis(n+1);
		vector<int>dis(n+1,(int)2e9);
		dis[s] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,s});
		while(pq.size()){
			auto p = pq.top(); pq.pop();
			if(vis[p.second])continue;
			vis[p.second] = true;
			for(auto nxt: adj2[p.second]){
				if(nxt.first+dis[p.second]<dis[nxt.second]){
					dis[nxt.second] = nxt.first+dis[p.second];
					pq.push({dis[nxt.second],nxt.second});
				}
			}
		}
		if(dis[t]<=len){
			use = pending.back();
			pending.pop_back();
			for(pair<int,int>nxt: pending){
				adj[nxt.first].push_back({(int)2e9,nxt.second});
				adj[nxt.second].push_back({(int)2e9,nxt.first});
			}
			break;
		}
		else{
			auto nxt = pending.back();
			adj[nxt.first].push_back({1,nxt.second});
			adj[nxt.second].push_back({1,nxt.first});
			pending.pop_back();
		}
	}
	//cerr << "nae\n";
	int low = 1; int high = (int)2e9; int mid = (low+high)/2;
	while(low+1<high){
		vector<vector<pair<int,int>>>adj2(n+1);
		for(int i = 1; i<=n; i++){
			for(auto nxt: adj[i]){
				adj2[i].push_back(nxt);
			}
		}
		adj2[use.first].push_back({mid,use.second});
		adj2[use.second].push_back({mid,use.first});
		vector<bool>vis(n+1);
		vector<int>dis(n+1,(int)2e9);
		dis[s] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,s});
		while(pq.size()){
			auto p = pq.top(); pq.pop();
			if(vis[p.second])continue;
			vis[p.second] = true;
			for(auto nxt: adj2[p.second]){
				if(nxt.first+dis[p.second]<dis[nxt.second]){
					dis[nxt.second] = nxt.first+dis[p.second];
					pq.push({dis[nxt.second],nxt.second});
				}
			}
		}
		if(dis[t]<=len)low = mid;
		else high = mid;
		mid = (low+high)/2;
		//cerr << low << " " << high << " " << mid << "\n";
	}
	adj[use.first].push_back({low,use.second});
	adj[use.second].push_back({low,use.first});
	cout << "YES\n";

	for(int i = 1; i<=n; i++){
		for(auto nxt: adj[i]){
			if(nxt.second>i){
				cout << i-1 << " " << nxt.second-1 << " " << nxt.first << "\n";
			}
		}
	}
	return 0;
}