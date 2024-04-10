#include <bits/stdc++.h>
using namespace std;
map <int,bool> m;
int main(){
	int n,a[100010],dp[100010],l,k;
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	dp[n]=0;
	for (int i=n-1; i>=0; i--){
		if (m[a[i]]){
			dp[i]=dp[i+1];
		}
		else{
			dp[i]=dp[i+1]+1;
		}
		m[a[i]]=1;
	}
	while (k--){
		cin >> l;
		cout << dp[l-1] << '\n';
	}
	return 0;
}