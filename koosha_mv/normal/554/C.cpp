#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll j=1,mod=1e9+7,fac[1000],n,a[1001],sum,x,y,g;
ll xgcd(ll a, ll b, ll &x, ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1,gcd=xgcd(b,a%b,x1,y1);
	x=y1;
	y=x1- (long long)(a/b)*y1;
	return gcd;
}
ll entekhab(ll r,ll n){
	if(r==0)
		return 1;
	ll ans=1;
	ans=fac[n];
	x=1,y=1,g=xgcd(fac[r],mod,x,y);
	ans=(ans*((x+mod)%mod))%mod;
	x=1,y=1,g=xgcd(fac[n-r],mod,x,y);
	ans=((ans*((x+mod)%mod)))%mod;
	return ans;
}
int main(){
	fac[0]=1;
	f(i,1,1010){fac[i]=(fac[i-1]*i)%mod;}
	cin>>n;
	f_(i,n-1,0) {cin>>a[i];sum+=a[i];}
	f(i,0,n){
		j*=entekhab(a[i]-1,sum-1);
		j=j%mod;
		sum-=a[i];}
	cout<<j;
}