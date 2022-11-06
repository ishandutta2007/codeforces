#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;	
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		int delta = 0;
		int cursum = 1;
		map<int,int>dp;
		dp[arr[1]] = 1;
		for(int i = 2; i<=n; i++){
			int v = dp[-delta];
			dp[-delta] = cursum;
			cursum+=cursum-v;
			cursum+=mod;
			cursum%=mod;
			delta+=arr[i];
		}
		cout << cursum << "\n";
	}
	return 0;
}