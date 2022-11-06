#include <bits/stdc++.h>
using namespace std;
long long dp[2000001];
long long m = 1e9+7;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 3; i<=2000000; i++){
		dp[i] = dp[i-1]+2*dp[i-2];
		if(i%3==0)dp[i]++;
		dp[i]%=m;
	}
	while(t--){
		int n;
		cin >> n;
		cout << dp[n]*4%m << "\n";
	}
	return 0;
}