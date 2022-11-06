#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>adj(n+1);
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	pair<int,int>ans;
	vector<int>arr;
	vector<bool>vis(n+1); vector<bool>vis2(n+1);
	vector<int>dis(n+1); vector<int>dis2(n+1);
	vector<int>path(n+1);
	queue<int>q;
	for(int i = 1; i<=n; i++){
		if(vis[i])continue;
		vis[i] = true;
		q.push(i);
		int dia = 0;
		int start = i;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(!vis[nxt]){
					vis[nxt] = true;
					dis[nxt] = dis[cur]+1;
					q.push(nxt);
					if(dis[nxt]>dia){
						dia = dis[nxt]; start = nxt;
					}
				}
			}
		}
		vis2[start] = true;
		q.push(start);
		dia = 0; int end = start;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(!vis2[nxt]){
					vis2[nxt] = true;
					dis2[nxt] = dis2[cur]+1;
					path[nxt] = cur;
					q.push(nxt);
					if(dis2[nxt]>dia){
						dia = dis2[nxt];
						end = nxt;
					}
				}
			}
		}
		for(int i = 0; i<dia/2; i++){
			end = path[end];
		}
		arr.push_back(end);
		ans = max(ans,{dia,end});
	}
	for(int nxt: arr){
		if(nxt!=ans.second){
			adj[nxt].push_back(ans.second);
			adj[ans.second].push_back(nxt);
		}
	}
	for(int i = 1; i<=n; i++){
		vis[i] = false; dis[i] = 0; vis2[i] = false; dis2[i] = 0;
	}
	q.push(1);vis[1] = true; int dia = 0; int end = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int nxt: adj[cur]){
			if(!vis[nxt]){
				vis[nxt] = true;
				dis[nxt] = dis[cur]+1;
				q.push(nxt);
				if(dia < dis[nxt]){
					dia = dis[nxt];
					end = nxt;
				}
			}
		}
	}
	q.push(end); vis2[end] = true;
	dia = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int nxt: adj[cur]){
			if(!vis2[nxt]){
				vis2[nxt] = true;
				dis2[nxt] = dis2[cur]+1;
				q.push(nxt);
				if(dia<dis2[nxt]){
					dia = dis2[nxt];
				}
			}
		}
	}
	cout << dia << "\n";
	for(int nxt: arr){
		if(nxt!=ans.second){
			cout << nxt << " " << ans.second << "\n";
		}
	}
	return 0;
}