#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>>vals(n+1);
		for(int i = 1; i<=n; i++){
			int x,y;
			cin >> x >> y;
			vals[x].push_back(i);
			vals[y].push_back(i);
		}
		bool f = true;
		for(int i = 1; i<=n; i++){
			if(vals[i].size()>2)f = false;
		}
		if(!f){
			cout << "NO\n";
			continue;
		}
		vector<vector<int>>adj(n+1);
		for(int i = 1; i<=n; i++){
			if(vals[i].size()==2){
				int x = vals[i][0]; int y = vals[i][1];
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		}
		queue<int>q;
		vector<bool>vis(n+1);
		vector<int>dis(n+1);
		for(int i = 1; i<=n; i++){
			if(vis[i])continue;
			vis[i] = true;
			q.push(i);
			while(q.size()){
				int cur = q.front(); q.pop();
				for(int nxt: adj[cur]){
					if(vis[nxt])continue;
					vis[nxt] = true;
					dis[nxt] = dis[cur]+1;
					q.push(nxt);
				}
			}
		}
		for(int i = 1; i<=n; i++){
			for(int nxt: adj[i]){
				if(dis[i]%2==dis[nxt]%2)f = false;
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}