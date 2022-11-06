#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		vector<vector<int>>factors(200005);
		for(int i = 1; i<=200000; i++){
			for(int j = i; j<=200000; j+=i){
				factors[j].push_back(i);
			}
		}
		sort(arr.begin(),arr.end());
		vector<int>dp(200005);
		vector<int>dp2(200005);
		int ans = 0;
		for(int i = 0; i<n; i++){
			int v = 0;
			for(int j: factors[arr[i]]){
					v = max(v,dp[j]+1);
			}
			dp[arr[i]] = v;
			ans = max(ans,dp[arr[i]]);
		}
		cout << n-ans << "\n";
	}
	return 0;
}