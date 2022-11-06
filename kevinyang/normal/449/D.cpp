#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>dp(1<<20);
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		dp[arr[i]]++;
	}
	for(int j = 0; j<20; j++){
		for(int i = (1<<20)-1; i>0; i--){
			if(i&(1<<j)){
				dp[i^(1<<j)]+=dp[i];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<(1<<20); i++){
		int cnt1 = __builtin_popcount(i);
		//if(dp[i]==0)continue;
		if(cnt1%2==1){
			ans+=modpow(2,dp[i]); ans%=mod;
		}
		else{
			ans-=modpow(2,dp[i]); ans+=mod; ans%=mod;
		}
	}
	ans = modpow(2,n)-ans;
	ans+=mod; ans%=mod;
	cout << ans << "\n";
	return 0;
}