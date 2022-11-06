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
		string s;
		cin >> s;
		vector<int>dp(n+10);//dp[i] is the maximum number of changes required to make the string correct until index i
		for(int i = 1; i<=n+5; i++){
			dp[i] = (int)1e18;
		}
		int ans = (int)1e18;
		for(int add = 0; add<4; add++){
			for(int i = 1; i<=n; i++){
				if(i+1<=n+add){
					int count = 0;
					if(s[(i-1+add)%n]=='L')count++;
					if(s[(i+add)%n]=='R')count++;
					dp[i+1] = min(dp[i+1],dp[i-1]+count);
				}
				if(i+2<=n+add){
					if(true){
						int count = 0;
						if(s[(i-1+add)%n]=='L')count++;
						if(s[(i+add)%n]=='R')count++;
						if(s[(i+1+add)%n]=='R')count++;
						dp[i+2] = min(dp[i+2],dp[i-1]+count);
					}
					if(true){
						int count = 0;
						if(s[(i-1+add)%n]=='L')count++;
						if(s[(i+add)%n]=='L')count++;
						if(s[(i+1+add)%n]=='R')count++;
						dp[i+2] = min(dp[i+2],dp[i-1]+count);
					}
				}
				if(i+3<=n+add){
					if(true){
						int count = 0;
						if(s[(i-1+add)%n]=='L')count++;
						if(s[(i+add)%n]=='L')count++;
						if(s[(i+1+add)%n]=='R')count++;
						if(s[(i+2+add)%n]=='R')count++;
						dp[i+3] = min(dp[i+3],dp[i-1]+count);
					}
				}
			}
			ans = min(ans,dp[n]);
			for(int i = 1; i<=n+5; i++){
				dp[i] = (int)1e18;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}