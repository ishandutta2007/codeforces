#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dp(100001);
vector<vector<int>>adj(100001);
int mod = (int)1e9+7;
void dfs(int n, int u){
	dp[n] = 1;
	for(int nxt: adj[n]){
		if(nxt==u){

		}
		else{
			dfs(nxt,n);
			dp[n]+=dp[nxt];
		}
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i<=n; i++){
			adj[i].clear();
		}
		for(int i = 0; i<n-1; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y); adj[y].push_back(x);
		}
		dfs(1,0);
		for(int i = 1; i<=n; i++){
			dp[i] = (n-dp[i])*dp[i];
		}
		sort(dp.begin()+1,dp.begin()+1+n);
		int m;
		cin >> m;
		vector<int>factors(m);
		int mm= m;
		for(int i = 0; i<m; i++){
			cin >> factors[i];
		}
		sort(factors.begin(),factors.end());
		while(m>n-1){
			factors[n-2] *=factors[m-1];
			factors[n-2]%=mod;
			m--;
		}
		int ans = 0;
		mm--;
		mm= min(mm,n-2);
		for(int i = n; i>=2; i--){
			if(mm>=0){
				ans+=dp[i]*factors[mm];
			}
			else ans+=dp[i];
			ans%=mod;
			mm--;
		}
		/*
		for(int i = 2; i<=n; i++){
			cout << dp[i] << " ";
		}
		cout << "\n";
		for(int i = 0; i<n-1; i++){
			cout << factors[i] << " ";
		}
		cout << "\n";
		*/
		cout << ans << "\n";
		for(int i = 0; i<=n; i++){
			dp[i] = 0;
		}
	}
	return 0;
}