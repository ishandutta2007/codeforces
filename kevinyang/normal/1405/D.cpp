#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,a,b,da,db;
		cin >> n >> a >> b >> da >> db;
		vector<vector<int>>adj(n+1);
		for(int i = 0; i<n-1; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y); adj[y].push_back(x);
		}
		if(true){
			vector<bool>vis(n+1); vector<int>dis(n+1);
			queue<int>q;
			q.push(a); vis[a] = true;
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(int nxt:adj[cur]){
					if(!vis[nxt]){
						vis[nxt] = true; dis[nxt] = dis[cur]+1;
						q.push(nxt);
					}
				}
			}
			if(dis[b]<=da){
				cout << "Alice\n";
				continue;
			}
		}
		if(true){
			int start = 0;
			if(true){
				vector<bool>vis(n+1); vector<int>dis(n+1);
				queue<int>q;
				q.push(a); vis[a] = true;
				while(!q.empty()){
					int cur = q.front(); q.pop();
					for(int nxt:adj[cur]){
						if(!vis[nxt]){
							vis[nxt] = true; dis[nxt] = dis[cur]+1;
							q.push(nxt);
						}
					}
				}
				int mx = 0;
				for(int i = 1; i<=n; i++){
					if(dis[i]>mx){
						mx = dis[i]; start = i;
					}
				}
			}
			if(true){
				vector<bool>vis(n+1); vector<int>dis(n+1);
				queue<int>q;
				q.push(start); vis[start] = true;
				while(!q.empty()){
					int cur = q.front(); q.pop();
					for(int nxt:adj[cur]){
						if(!vis[nxt]){
							vis[nxt] = true; dis[nxt] = dis[cur]+1;
							q.push(nxt);
						}
					}
				}
				int dia = 0;
				for(int i = 1; i<=n; i++){
					dia = max(dia,dis[i]);

				}
				if(da*2>=dia){
					cout << "Alice\n";
					continue;
				}
			}
			
		}
		if(da*2<db){
			cout << "Bob\n";
		}
		else{
			cout << "Alice\n";
		}
	}
	return 0;
}