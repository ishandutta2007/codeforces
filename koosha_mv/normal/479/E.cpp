#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll n,a,b,k,dp[5003][5003],sum[5003],ans=0,mod=1e9+7;
int main(){
	cin>>n>>a>>b>>k;
	dp[0][a]=1;
	if(a==b || a==b-1 || a==b+1){cout<<0;return 0;}
	if(a>b){
		f(i,1,k+1){
			sum[n+1]=0;
			f_(j,n,b+1)
				sum[j]=(sum[j+1]+dp[i-1][j])%mod;
			f(j,b+1,n+1)
				dp[i][j]=(sum[(j+b)/2+1]+mod-dp[i-1][j])%mod;
		}
	}
	else{
		f(i,1,k+1){
			sum[0]=0;
			f(j,1,b)
				sum[j]=(sum[j-1]+dp[i-1][j])%mod;
			f(j,1,b){
				dp[i][j]=((sum[((j+b)/2-1)+((b-j)%2)]+mod)-dp[i-1][j])%mod;
			}
		}
	}
	f(i,1,n+1) ans+=dp[k][i],ans%=mod;
	cout<<ans;
}