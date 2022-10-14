#include <bits/stdc++.h>

using namespace std ;
const int maxn = 1e6 + 10 ;
typedef long long ll ;
int a[maxn] , b[maxn] , dp[maxn] , dp2[maxn];
int m  ;
int check(int n){
	if(n != m){
		dp2[n] = dp2[n-1] ;
		dp[n] = dp[n-1] + 100;
	}
	//cout<<dp[n]<<" "<<dp[n/4]<<" "<<dp2[n]<<" "<<dp2[n/4]<<endl;
        int ind=n/4-(n-m);
        if(ind<0)ind=0;
		if((dp[n] - dp[n/4]) >= (dp2[n] - dp2[ind]))
			return 1 ;
		else
			return 0 ;

}
int main(){
	int t = 1;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		m = n ;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i] ;
		}
		for(int i = 1 ; i <= n ; i++){
			cin >> b[i] ;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i = 1 ; i  <= n ; i++){
			dp[i] = dp[i-1] + a[i] ;
			dp2[i] = dp2[i-1] + b[i] ;
		}
		int ans = n ;
		while(check(ans) == 0){
			ans++;
		}
		cout << ans - n << "\n";
	}
}