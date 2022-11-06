#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>adj(n+1);
		int s,t;
		cin >> s >> t;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		vector<bool>vis(n+1);
		vector<int>dis(n+1,(int)1e9);
		vector<int>cnt(n+1);
		vector<bool>vis2(n+1);
		vector<int>dis2(n+1,(int)1e9);
		vector<int>cnt2(n+1);
		dis[s] = 0;
		cnt[s] = 1;
		cnt2[t] = 1;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,s});
		while(pq.size()){
			pair<int,int> cur = pq.top(); pq.pop();
			if(vis[cur.second])continue;
			vis[cur.second] = true;
			for(int nxt: adj[cur.second]){
				if(dis[nxt]>dis[cur.second]+1){
					dis[nxt] = dis[cur.second]+1;
					cnt[nxt] = cnt[cur.second];
					pq.push({dis[nxt],nxt});
				}
				else if(dis[nxt]==dis[cur.second]+1){
					cnt[nxt]+=cnt[cur.second];
					cnt[nxt]%=mod;
				}
			}
		}
		pq.push({0,t});
		dis2[t] = 0;
		while(pq.size()){
			pair<int,int> cur = pq.top(); pq.pop();
			if(vis2[cur.second])continue;
			vis2[cur.second] = true;
			for(int nxt: adj[cur.second]){
				if(dis2[nxt]>dis2[cur.second]+1){
					dis2[nxt] = dis2[cur.second]+1;
					cnt2[nxt] = cnt2[cur.second];
					pq.push({dis2[nxt],nxt});
				}
				else if(dis2[nxt]==dis2[cur.second]+1){
					cnt2[nxt]+=cnt2[cur.second];
					cnt2[nxt]%=mod;
				}
			}
		}
		int ans = cnt[t];
		for(int i = 1; i<=n; i++){
			if(dis[i]+dis2[i]!=dis[t])continue;
			for(int nxt: adj[i]){
				if(dis[nxt]!=dis[i])continue;
				ans+=cnt[nxt]*cnt2[i]%mod;
				ans%=mod;
			}
			//cout << i << " " << ans << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}