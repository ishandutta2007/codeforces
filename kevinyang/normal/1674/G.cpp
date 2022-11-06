#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<vector<int>>rev(mxn);
bool find(int x, int y){
	for(int nxt: adj[x]){
		if(nxt==y)continue;
		return true;
	}
	return false;
}
bool find2(int x, int y){
	for(int nxt: rev[x]){
		if(nxt==y)continue;
		return true;
	}
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>indegrees(n+1);
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		rev[y].push_back(x);
		indegrees[y]++;
	}
	vector<int>dp(n+1,1);
	queue<int>q;
	for(int i = 1; i<=n; i++){
		if(indegrees[i]==0){
			q.push(i);
		}
	}
	while(q.size()){
		int cur = q.front(); q.pop();
		for(int nxt: adj[cur]){
			indegrees[nxt]--;
			if(find(cur,nxt)&&find2(nxt,cur)){
				dp[nxt] = max(dp[nxt],dp[cur]+1);
			}
			if(indegrees[nxt]==0){
				q.push(nxt);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans = max(ans,dp[i]);
	}
	cout << ans << "\n";
	return 0;
}