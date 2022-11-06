#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp(7000,vector<int>(200,-(int)1e9));
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		while(x%2==0){
			a[i]++;
			x/=2;
		}
		while(x%5==0){
			b[i]++;
			x/=5;
		}
	}
	dp[0][0] = 0;
	for(int t = 1; t<=n; t++){
		for(int j = n; j>=1; j--){
			for(int i = 6000; i>=b[t]; i--){
				dp[i][j] = max(dp[i][j],dp[i-b[t]][j-1]+a[t]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i<=6000; i++){
		ans = max(ans,min(i,dp[i][k]));
	}
	cout << ans << "\n";
	return 0;
}