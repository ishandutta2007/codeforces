#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<pair<int,int>>>adj(200001);
vector<int>dp(200001);//number of paths of 1's that lead up to node i
vector<int>dp2(200001);//number of paths of 0's that lead up to node i
vector<int>dp3(200001);// 1's then 0 (at least one of each)
vector<int>dp4(200001);// 0's then 1 (at least one of each)
int ans = 0;
void dfs(int u, int p, int w){
	for(pair<int,int> nxt: adj[u]){
		if(nxt.second==p)continue;
		dfs(nxt.second,u,nxt.first);
		if(nxt.first==1){
			dp[u]++; dp[u]+=dp[nxt.second];
			dp4[u]+=dp2[nxt.second]+dp4[nxt.second];
		}
		else{
			dp2[u]++; dp2[u]+=dp2[nxt.second];
			dp3[u]+=dp[nxt.second]+dp3[nxt.second];
		}
	}
	ans+=2*dp[u]+2*dp2[u]+dp3[u]+dp4[u];
	//cout << u << "\n";
	for(pair<int,int>nxt: adj[u]){
		if(nxt.second==p)continue;
		if(nxt.first==1){
			int v = dp[nxt.second]+1;
			ans+=v*dp2[u];
			//cout << v*dp2[u] << " ";
			int rem1 = dp[u]-v;
			ans+=rem1*(dp2[nxt.second]+dp4[nxt.second]);
			//cout << rem1*(dp2[nxt.second]+dp4[nxt.second]) << " ";
			ans+=rem1*(dp[nxt.second]+1);
			//cout << rem1*(dp[nxt.second]+1) << " ";
		}
		else{
			int rem0 = dp2[u]-1-dp2[nxt.second];
			ans+=rem0*(dp[nxt.second]+dp3[nxt.second]);
			//cout << rem0*(dp[nxt.second]+dp3[nxt.second]) << " ";
			ans+=rem0*(dp2[nxt.second]+1);
			//cout << rem0*(dp2[nxt.second]+1) << " ";
		}
		//cout << "\n";
	}
	//cout << "\n";
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n-1; i++){
		int x,y,c;
		cin >> x >> y >> c;
		adj[x].push_back({c,y});
		adj[y].push_back({c,x});
	}
	dfs(1,0,0);
	cout << ans << "\n";
	return 0;
}