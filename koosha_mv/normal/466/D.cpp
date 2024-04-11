#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
const int N=2e3+7,mod=1e9+7;
ll n,h,dp[N][N],a[N],e,ans;
int main(){
	cin>>n>>h;
	dp[0][0]=1;
	f(i,1,n+1){
		scanf("%I64d",&a[i]);
		e=h-a[i];
		if(e<0){cout<<0;return 0;}
		dp[i][e]=dp[i-1][e];
		if(e>0){
			dp[i][e]=(dp[i][e]+dp[i-1][e-1])%mod;
			dp[i][e-1]=(dp[i-1][e-1]*e+dp[i-1][e]*e)%mod;
		}
		//cout<<i<<" : "<<endl;
		//f(j,0,h+1)
		//	cout<<dp[i][j]<<" ";
		//cout<<endl;
	}
	cout<<dp[n][0];
}