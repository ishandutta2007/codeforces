#include<bits/stdc++.h>
using namespace std;
int t,e[1000005],i,n,ans,dp[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;for(i=1;i<=n;++i)cin>>e[i];
		sort(e+1,e+n+1);
		for(i=1;i<=n;++i){
			dp[i]=dp[i-1];
			if(i>=e[i])dp[i]=max(dp[i],dp[i-e[i]]+1);
		}
		cout<<dp[n]<<"\n";
	}
}