#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int p;
		cin >> p;
		int n = 1<<p;
		vector<vector<int>>adj(n+1);
		vector<pair<int,int>>edges(n);
		map<pair<int,int>,int>hm;
		for(int i = 1; i<n; i++){
			int x,y;
			cin >> x >> y;
			edges[i] = {x,y};
			adj[x].push_back(y);
			adj[y].push_back(x);
			hm[{x,y}] = i;
			hm[{y,x}] = i;
		}
		queue<pair<int,int>>vals;
		for(int i = 1; i<n; i++){
			vals.push({i,i+n});
		}
		queue<int>q;
		vector<bool>vis(n+1);
		vector<int>ans(n+1);
		vector<int>ans2(n+1);
		ans[1] = n;
		vector<int>dis(n+1);
		dis[1] = n;
		q.push(1); vis[1] = true;
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(vis[nxt])continue;
				vis[nxt] = true;
				pair<int,int>p = vals.front(); vals.pop();
				if(dis[cur]==0){
					dis[nxt] = n;
					int idx = hm[{cur,nxt}];
					ans2[idx] = p.first;
					ans[nxt] = p.second;
				}
				else{
					dis[nxt] = 0;
					int idx = hm[{cur,nxt}];
					ans2[idx] = p.second;
					ans[nxt] = p.first;
				}
				q.push(nxt);
			}
		}
		cout << "1\n";
		for(int i = 1; i<=n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		for(int i = 1; i<n; i++){
			cout << ans2[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}