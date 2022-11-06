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
		vector<int>people(n+1);
		vector<int>happiness(n+1);
		for(int i = 1; i<=n; i++){
			cin >> people[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> happiness[i];
		}
		vector<vector<int>>adj(n+1);
		for(int i = 1; i<n; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vector<vector<int>>dag(n+1);
		vector<vector<int>>dag2(n+1);
		queue<int>q;
		vector<bool>vis(n+1);
		q.push(1);
		vis[1] = true;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int nxt: adj[cur]){
				if(!vis[nxt]){
					vis[nxt] = true;
					dag[nxt].push_back(cur);
					dag2[cur].push_back(nxt);
					q.push(nxt);
				}
			}
		}
		vector<int>dp(n+1);
		vector<int>happydp(n+1);
		vector<int>indegrees(n+1);
		for(int i = 1; i<=n; i++){
			//cout << i << ": ";
			for(int nxt: dag[i]){
				indegrees[nxt]++;
				//cout << nxt << " ";
			}
			//cout << "\n";
		}
		bool f = true;
		for(int i = 1; i<=n; i++){
			if(indegrees[i]==0){
				q.push(i);
				dp[i] = people[i];
				happydp[i] = (dp[i]+happiness[i])/2;
			}
		}
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int nxt: dag[cur]){
				dp[nxt]+=dp[cur];
				indegrees[nxt]--;
				if(indegrees[nxt]==0){
					dp[nxt]+=people[nxt];
					happydp[nxt] = (dp[nxt]+happiness[nxt])/2;
					q.push(nxt);
				}
			}
		}
		for(int i = 1; i<=n; i++){
			if((dp[i]+happiness[i])%2!=0){
				f = false;
			}
		}
		//cout << f << "\n";
		for(int i = 1; i<=n; i++){
			if(happydp[i]>dp[i]){
				f = false;
			}
			if(happydp[i]<0){
				f = false;
			}
		}
		//cout << f << "\n";
		for(int i = 1; i<=n; i++){
			int total = 0;
			for(int nxt:dag2[i]){
				total+=happydp[nxt];
			}
			if(total>happydp[i]){
				f = false;
			}
		}

		for(int i = 1; i<=n; i++){
			//cout << dp[i] << " ";
		}
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}