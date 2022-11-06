#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<int>>dp(n+1,vector<int>(26));
	vector<vector<int>>adj(n+1);
	for(int i = 1; i<=m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	vector<int>indegrees(n+1);
	queue<int>q;
	for(int i = 1; i<=n; i++){
		for(int nxt: adj[i]){
			indegrees[nxt]++;
		}
	}
	for(int i = 1; i<=n; i++){
		if(indegrees[i]==0){
			q.push(i);
			dp[i][s[i-1]-'a']++;
		}
	}
	vector<bool>vis(n+1);
	while(q.size()){
		int cur = q.front(); q.pop();
		vis[cur] = true;
		for(int nxt: adj[cur]){
			indegrees[nxt]--;
			for(int i = 0; i<26; i++){
				if(s[nxt-1]==(char)('a'+i)){
					dp[nxt][i] = max(dp[nxt][i],1+dp[cur][i]);
				}
				else{
					dp[nxt][i] = max(dp[nxt][i],dp[cur][i]);
				}
			}
			if(indegrees[nxt]==0){
				q.push(nxt);
			}
		}
	}
	if(count(vis.begin(),vis.end(),true)!=n){
		cout << "-1\n";
	}
	else{
		int ans = 0;
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<26; j++){
				ans = max(ans,dp[i][j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}