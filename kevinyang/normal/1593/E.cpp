#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>indegrees(n+1);
		queue<int>q;
		vector<vector<int>>adj(n+1);
		for(int i = 1; i<n; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			indegrees[x]++; indegrees[y]++;
		}
		vector<int>dis(n+1,(int)1e9);
		for(int i = 1; i<=n; i++){
			if(adj[i].size()<=1){
				q.push(i);
				dis[i] = 0;
			}
		}
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				indegrees[nxt]--;
				if(indegrees[nxt]==1){
					q.push(nxt);
					dis[nxt] = dis[cur]+1;
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i<=n; i++){
			if(dis[i]<k)cnt++;
		}
		cout << n-cnt << "\n";
	}
	return 0;
}