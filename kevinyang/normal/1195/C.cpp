#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	map<int,int>dp;
	map<int,int>dp2;
	vector<int>arr(n+1);
	vector<int>arr2(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> arr2[i];
	}
	for(int i = 1; i<=n; i++){
		dp[i] = max(dp2[i-1]+arr[i],dp[i-1]);
		dp2[i] = max(dp[i-1]+arr2[i],dp2[i-1]);
	}
	cout << max(dp[n],dp2[n]) << "\n";
	return 0;
}