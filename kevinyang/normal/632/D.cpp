#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>dp(1000005);
	vector<int>freq(1000005);
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		if(arr[i]>1000000)continue;
		freq[arr[i]]++;
	}
	for(int i = 1; i<=1000000; i++){
		for(int j = i; j<=1000000; j+=i){
			dp[j]+=freq[i];
		}
	}
	int mx = 0; int lcm = 1;
	for(int i = 1; i<=m; i++){
		if(dp[i]>mx){
			mx = dp[i]; lcm = i;
		}
	}
	cout << lcm << " " << mx << "\n";
	for(int i = 1; i<=n; i++){
		if(lcm%arr[i]==0){
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}