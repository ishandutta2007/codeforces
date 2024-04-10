#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	vector<int>hm(1000);
	vector<int>dp(1<<20);
	for(int i = 0; i<20; i++){
		hm['a'+i] = i;
	}
	for(int i = 0; i<s.length(); i++){
		int mask = 0;
		for(int j = i; j<min(i+20,(int)s.length()); j++){
			if(mask&(1<<hm[s[j]]))break;
			mask^=(1<<hm[s[j]]);
			dp[mask]= __builtin_popcount(mask);
		}
	}
	for(int i = 0; i<20; i++){
		for(int j = 0; j<(1<<20); j++){
			if(j&(1<<i)){
				dp[j] = max(dp[j],dp[j^(1<<i)]);
			}
		}
	}
	int mxv = (1<<20)-1;
	int ans = 0;
	for(int i = 0; i<s.length(); i++){
		int mask = 0;
		for(int j = i; j<min(i+20,(int)s.length()); j++){
			if(mask&(1<<hm[s[j]]))break;
			mask^=(1<<hm[s[j]]);
			ans = max(ans,__builtin_popcount(mask)+dp[mxv^mask]);
		}
	}
	cout << ans << "\n";
	return 0;
}