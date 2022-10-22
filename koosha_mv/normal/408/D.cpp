#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,dp[1009],x,b[1009],mod=1e9+7;
int main(){
	dp[1]=2;b[1]=2;
	cin>>n;cin>>x;
	f(i,2,n+1){
		cin>>x;
		dp[i]=(((b[i-1]+mod)-b[x-1])+2)%mod;
		b[i]=(b[i-1]+dp[i])%mod;}
	cout<<b[n];
}