#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>adj(n+1);
		for(int i = 1; i<=m; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		vector<int>dis(n+1);
		vector<bool>vis(n+1);
		queue<int>q;
		vis[1] = true;
		q.push(1);
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(vis[nxt])continue;
				vis[nxt] = true;
				dis[nxt] = dis[cur]+1;
				q.push(nxt);
			}
		}
		vector<int>mn(n+1);
		for(int i = 1; i<=n; i++){
			mn[i] = dis[i];
		}
		for(int i = 1; i<=n; i++){
			for(int nxt: adj[i]){
				mn[i] = min(mn[i],dis[nxt]);
			}
		}
		vector<vector<int>>adj2(n+1);
		for(int i = 1; i<=n; i++){
			for(int nxt: adj[i]){
				if(dis[i]<dis[nxt]){
					adj2[nxt].push_back(i);
				}
			}
		}
		vector<int>indegrees(n+1);
		for(int i = 1; i<=n; i++){
			for(int nxt: adj2[i]){
				indegrees[nxt]++;
			}
		}
		for(int i = 1; i<=n; i++){
			if(indegrees[i]==0){
				q.push(i);
			}
		}
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj2[cur]){
				indegrees[nxt]--;
				mn[nxt] = min(mn[nxt],mn[cur]);
				if(indegrees[nxt]==0){
					q.push(nxt);
				}
			}
		}
		for(int i = 1; i<=n; i++){
			cout << mn[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}