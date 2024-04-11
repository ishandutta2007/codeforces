#include <bits/stdc++.h>
#include<algorithm>
#define salamkhoobichwtori 1e17
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll n,dp[5009][2509][2],a[5009];
int main(){
	cin>>n;
	f(i,2,n+2) cin>>a[i];
	f(i,0,2509) dp[0][i][1]=dp[0][i][0]=dp[1][i][1]=dp[1][i][0]=salamkhoobichwtori;
	dp[0][0][0]=0,dp[1][0][0]=0;
	f(i,2,n+2){
		f(j,0,n/2+2){
			dp[i][j][0]=1e17,dp[i][j][1]=1e17;
			dp[i][j][1]=min(dp[i-2][j-1][0]+max(a[i-1]-(a[i]-1),(ll)0),dp[i-2][j-1][1]+max((a[i-2]-1)-(a[i]-1),(ll)0))+max(a[i+1]-(a[i]-1),(ll)0);
			dp[i][j][0]=min(dp[i-1][j][0],dp[i][j][1]);}}
	f(i,1,(n+1)/2+1){
		cout<<dp[n+1][i][0]<<" ";
	}
}