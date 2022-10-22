#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll t,c,n,dp[2009];
int main(){
	f(i,1,2009)
		dp[i]=1e18;
	cin>>n;
	f(i,0,n){
		cin>>t>>c;t++;
		f_(j,n,1) dp[j]=min(dp[j],dp[max(int(j-t),0)]+c);
	}
	cout<<dp[n];
}