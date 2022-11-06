#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,c;
		cin >> n >> c;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>arr2(n+1);
		for(int i = 1; i<n; i++){
			cin >> arr2[i];
		}
		vector<pair<int,int>>dp(n+1);//min number of days to reach job 1 and money remaining
		if(true){
			int cur = 0;
			for(int i = 1; i<n; i++){
				int time = (arr2[i]-cur+arr[i]-1)/arr[i];
				cur+=time*arr[i]; cur-=arr2[i];
				dp[i+1].first = dp[i].first+time+1;
				dp[i+1].second = cur;
			}
		}
		int ans = (int)1e18;
		for(int i = 1; i<=n; i++){
			ans = min(ans,dp[i].first+(c-dp[i].second+arr[i]-1)/arr[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}