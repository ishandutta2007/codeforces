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
		vector<pair<int,int>>edges;
		for(int i = 0; i<m; i++){
			int type;
			cin >> type;
			if(type){
				int x,y;
				cin >> x >> y;
				adj[x].push_back(y);
			}
			else{
				int x,y;
				cin >> x >> y;
				edges.push_back(make_pair(x,y));
			}
		}
		vector<bool>starters(n+1);
		for(int i = 1; i<=n; i++){
			starters[i] = true;
		}
		vector<int>indegrees(n+1);
		for(int i = 1; i<=n; i++){
			for(int nxt: adj[i]){
				starters[nxt] = false;
				indegrees[nxt]++;
			}
		}
		//cerr << "yeet\n";
		queue<int>q;
		vector<int>sorted;
		vector<bool>vis(n+1);
		for(int i = 1; i<=n; i++){
			if(starters[i]){
				q.push(i);
				sorted.push_back(i);
				vis[i] = true;
			}
		}
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int nxt: adj[cur]){
				indegrees[nxt]--;
				if(indegrees[nxt]==0){
					vis[nxt] = true;
					q.push(nxt);
					sorted.push_back(nxt);
				}
			}
		}
		//cerr << "yeet\n";
		bool visall = true;
		for(int i = 1; i<=n; i++){
			if(!vis[i])visall = false;
		}
		if(!visall){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<int>indices(n+1);
		for(int i = 0; i<n; i++){
			indices[sorted[i]] = i;
		}
		for(pair<int,int>p:edges){
			int i1 = indices[p.first];
			int i2 = indices[p.second];
			if(i1<i2){
				cout << p.first << " " << p.second << "\n";
			}
			else{
				cout << p.second << " " << p.first << "\n";
			}
		}
		for(int i = 1; i<=n; i++){
			for(int nxt: adj[i]){
				cout << i << " " << nxt << "\n";
			}
		}
	}
	return 0;
}