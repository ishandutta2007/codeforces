#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> primefactors(int x){
	set<int>s;
	int k = x;
	for(int i = 2; i*i<=x; i++){
		while(k%i==0){
			k/=i;
			s.insert(i);
		}
	}
	if(k>1)s.insert(k);
	vector<int>ans;
	for(int nxt: s)ans.push_back(nxt);
	return ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,a,b;
	cin >> n >> a >> b;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	set<int>s;
	s.insert(2);
	s.insert(3);
	for(int nxt: primefactors(arr[1]))s.insert(nxt);
	for(int nxt: primefactors(arr[n]))s.insert(nxt);
	for(int nxt: primefactors(arr[1]-1))s.insert(nxt);
	for(int nxt: primefactors(arr[n]-1))s.insert(nxt);
	for(int nxt: primefactors(arr[1]+1))s.insert(nxt);
	for(int nxt: primefactors(arr[n]+1))s.insert(nxt);
	int ans = (int)1e18;
	for(int nxt: s){
		vector<int>dp(n+1,(int)1e18);
		vector<int>dp2(n+1,(int)1e18);
		vector<int>dp3(n+1,(int)1e18);
		dp[0] = 0;
		for(int i = 1; i<=n; i++){
			dp2[i] = min(dp2[i-1],dp[i-1])+a;
			if(arr[i]%nxt==0){
				dp[i] = dp[i-1];
				dp3[i] = min({dp3[i-1],dp2[i-1],dp[i-1]});
			}
			else if(arr[i]%nxt==1||arr[i]%nxt==nxt-1){
				dp[i] = dp[i-1]+b;
				dp3[i] = min({dp3[i-1],dp2[i-1],dp[i-1]})+b;
			}
			dp[i] = min(dp[i],(int)1e18);
			dp2[i] = min(dp2[i],(int)1e18);
			dp3[i] = min(dp3[i],(int)1e18);
		}
		ans = min(ans,dp3[n]);
		ans = min(ans,dp2[n]);
		ans = min(ans,dp[n]);
	}
	cout << ans << "\n";
	return 0;
}