#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>psa(n+1);
	for(int i = 1; i<=n; i++){
		psa[i] = psa[i-1]+arr[i];
	}
	vector<int>dp(n+1);
	for(int i = 1; i<=n; i++){
		dp[i] = (psa[i]+i-1)/i;
		dp[i] = max(dp[i],dp[i-1]);
	}
	vector<int>ans(n+1);
	for(int i = 1; i<=n; i++){
		ans[i] = max(dp[i],(psa[n]+i-1)/i);
	}
	int q;
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		if(t<ans[n]){
			cout << "-1\n";
			continue;
		}
		int low = 0; int high = n+1; int mid = (low+high)/2;
		while(low+1<high){
			if(ans[mid]<=t){
				high = mid;
			}
			else{
				low = mid;
			}
			mid = (low+high)/2;
		}
		cout << high << "\n";
	}
	return 0;
}