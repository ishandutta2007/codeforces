#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 106046694639597709LL;
const int mod2 = 243984991979324837LL;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>dp(10005); dp[0] = 1;
	vector<int>dp2(10005); dp2[0] = 1;
	vector<vector<int>>add(n+1);
	vector<vector<int>>rem(n+5);
	vector<bool>vis(n+1);

	while(q--){
		int l,r,x;
		cin >> l >> r >> x;
		add[l].push_back(x);
		rem[r+1].push_back(x);
	}
	for(int i = 1; i<=n; i++){
		for(int nxt: add[i]){
			for(int j = 10004; j>=nxt; j--){
				dp[j]+=dp[j-nxt];
				dp[j]%=mod;
				dp2[j]+=dp2[j-nxt];
				dp2[j]%=mod2;
			}
		}
		for(int nxt: rem[i]){
			for(int j = nxt; j<=10004; j++){
				dp[j]-=dp[j-nxt];
				dp2[j]-=dp2[j-nxt];
				dp[j]+=mod; dp[j]%=mod;
				dp2[j]+=mod2; dp2[j]%=mod2;
			}
		}
		for(int j = 1; j<=n; j++){
			if(dp[j]>0||dp2[j]>0)vis[j] = true;
			//cout << dp[j] << " ";
		}
		//cout << "\n";
	}
	vector<int>ans;
	for(int i = 1; i<=n; i++){
		if(vis[i])ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for(int nxt: ans){
		cout << nxt << " ";
	}
	cout << "\n";
	return 0;
}