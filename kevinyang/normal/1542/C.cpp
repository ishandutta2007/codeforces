#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int lcm = 1;
	vector<int>arr(55,(int)1e18);
	for(int i = 1; i<1000; i++){
		lcm = lcm*i/__gcd(lcm,i);
		if(lcm>(int)1e16)break;
		arr[i] = lcm;
	}
	arr[0] = 0;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>dp(55);
		int cur = 0;
		for(int i = 50; i>=1; i--){
			dp[i] = n/arr[i]-cur;
			cur+=dp[i];
		}
		//cout << "\n";
		int ans = 0;
		for(int i = 1; i<=50; i++){
			//cout << dp[i] << " ";
			ans+=(i+1)*dp[i];
		}
		//cout << "\n";
		cout << ans%mod << "\n";
	}
	return 0;
}