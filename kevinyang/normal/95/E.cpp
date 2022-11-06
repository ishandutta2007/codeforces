#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>freq(n+1);
	vector<vector<int>>adj(n+1);
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<bool>vis(n+1);
	for(int i = 1; i<=n; i++){
		if(vis[i])continue;
		vis[i] = true;
		queue<int>q;
		q.push(i);
		int cnt = 1;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(vis[nxt])continue;
				vis[nxt] = true;
				q.push(nxt);
				cnt++;
			}
		}
		freq[cnt]++;
	}
	vector<int>dp(n+1,(int)1e9);
	dp[0] = 0;
	for(int i = 1; i<=n; i++){
		if(!freq[i])continue;
		vector<pair<int,int>>arr;
		int k = freq[i];
		int cur = 1;
		while(k>=cur){
			k-=cur;
			arr.push_back({cur*i,cur});
			cur*=2;
		}
		if(k>0){
			arr.push_back({k*i,k});
		}
		for(pair<int,int>nxt: arr){
			int w = nxt.first; int v = nxt.second;
			for(int i = n; i>=w; i--){
				dp[i] = min(dp[i],dp[i-w]+v);
			}
		}
	}
	int ans = (int)1e9;
	for(int i = 1; i<=n; i++){
		bool f = true;
		string s = to_string(i);
		for(char nxt: s){
			if(nxt=='4'||nxt=='7')continue;
			f = false;
		}
		if(f){
			ans = min(ans,dp[i]);
		}
	}
	if(ans>(int)1e6){
		cout << "-1\n";
		return 0;
	}
	ans--;
	cout << ans << "\n";
	return 0;
}