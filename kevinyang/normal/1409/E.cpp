#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		vector<int>dp(n+1);//dp[i] is the number of points it covers if right border is less or equal to ith point
		int left = 0;
		for(int i = 0; i<n; i++){
			int right = arr[i];
			while(right-arr[left]>k){
				left++;
			}
			dp[i+1] = max(i-left+1,dp[i]);
		}
		int mx = 0;
		int right = n-1;
		for(int i = n-1; i>=0; i--){
			left = arr[i];
			while(arr[right]-left>k){
				right--;
			}
			mx = max(mx,dp[i]+right-i+1);
		}
		cout << mx << "\n";
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
		}
	}
	return 0;
}