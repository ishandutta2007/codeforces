#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i]; arr[i]++;
	}
	vector<int>dp(n+1);
	vector<int>dp2(n+1);
	for(int i = 1; i<=n; i++){
		if(i!=n){
			dp[i] = min(dp[i-1]+d,a+3*d+dp2[i-1])+a*(arr[i]-1)+c;
			dp[i] = min(dp[i],a+3*d+dp2[i-1]+min(a*(arr[i]+1),b+a));
			dp2[i] = min(dp[i-1]+d,a+3*d+dp2[i-1]) + min(b,arr[i]*a);
		}
		else{
			int v1 = 2*d+dp2[i-1]+a+a*(arr[i]-1)+c;
			int v2 = d+dp[i-1]+a*(arr[i]-1)+c;
			int v3 = 3*d+dp2[i-1]+a+min(a*(arr[i]+1),b+a);
			cout << min({v1,v2,v3})-d << "\n";
		}
	}
	return 0;
}