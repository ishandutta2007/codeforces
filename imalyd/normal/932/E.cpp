#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int p=1000000007;
ll n,k,ans,s[5005][5005];
ll expo(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%p;
		b>>=1,a=a*a%p;
	}
	return ans;
}
ll a(ll m){
	ll ans=1;
	for(;m;m--)(ans*=(n-m+1)%p)%=p;
	return ans;
}
int main(){
	cin>>n>>k;
	s[0][0]=1;
	for(ll i=1;i<=k;i++)for(ll j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+j*s[i-1][j]%p)%p;
	for(ll i=0;i<=min(n,k);i++){
		(ans+=(a(i)*s[k][i]%p)*expo(2,n-i)%p)%=p;//s
	}
	cout<<ans;
	return 0;
}