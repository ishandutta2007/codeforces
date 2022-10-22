#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int n,dp1[1000009],dp2[1000009],mod=1e9+7;
int main(){
	cin>>n;
	dp1[1]=1,dp2[1]=0;
	f(i,2,n+1){
		if(i%2==0) dp2[i]=(dp1[i-1]+1+dp2[i-1])%mod,dp1[i]=dp1[i-1];
		else dp1[i]=(dp2[i-1]+1+dp1[i-1])%mod,dp2[i]=dp2[i-1];
	}
	cout<<(dp1[n]+dp2[n])%mod;
}