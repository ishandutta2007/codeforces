#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(pair<int,int>a, pair<int,int>b){
	return a.first+a.second > b.first+b.second;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,r;
	cin >> n >> r;
	vector<pair<int,int>>pos;
	vector<pair<int,int>>neg;
	for(int i = 0; i<n; i++){
		int x,y;
		cin >> x >> y;
		if(y>=0){
			pos.push_back({x,y});
		}
		else{
			neg.push_back({x,y});
		}
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end(),comp);
	int cnt = 0;
	for(pair<int,int>nxt: pos){
		if(r>=nxt.first){
			cnt++;
			r+=nxt.second;
		}
	}
	int m = neg.size();
	vector<vector<int>>dp(m+1,vector<int>(60005,-(int)1e18));
	for(int i = 0; i<=r; i++){
		dp[0][i] = 0;
	}
	int ans = 0;
	for(int t = 1; t<=m; t++){
		for(int i = 60000; i>=0; i--){
			if(i-neg[t-1].second<=60000&&i-neg[t-1].second>=neg[t-1].first){
				dp[t][i] = max(dp[t][i],dp[t-1][i-neg[t-1].second]+1);
				ans = max(ans,dp[t][i]);
			}
			dp[t][i] = max(dp[t][i],dp[t-1][i]);
			dp[t][i] = max(dp[t][i],dp[t][i+1]);
		}
	}
	cout << cnt+ans << "\n";
	return 0;
}