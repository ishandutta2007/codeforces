#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1e6+9,mod=998244353;
ll fac[N*2],b3[N*2],x,y,ans,k=1,n,g,gh,k2;
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
ll tavan(ll x,ll y){
	ll p;
	if(y==0) return 1;
	if(y%2==0){
		p=tavan(x,y/2);
		return (p*p)%mod;
	}
	return (tavan(x,y-1)*x)%mod;
}
int main(){
	fac[0]=1,b3[0]=1;f(i,1,N-1) fac[i]=(fac[i-1]*i)%mod;
	f(i,1,N-1) b3[i]=(b3[i-1]*(ll)3)%mod;
	cin>>n;ans=1;
	f(i,0,n){
		k=(k*(b3[n]-3))%mod;
		ans=(ans*(b3[n]))%mod;
	}
	gh=ans;
	ans=(ans+mod-k)%mod;
	f(i,1,n+1){
		k=tavan(b3[n-i]-1,n);
		k=(k*entekhab(i,n)*((ll)3))%mod;
		if(i>=2){
			k2=tavan(b3[n-i],n);
			k2=(k2*entekhab(i,n))%mod;
			k2=(k2*(b3[i]-3))%mod;
		}
		k=(k+k2)%mod;
		if(i%2==1)
			ans=(ans+k)%mod;
		else
			ans=(ans+mod-k)%mod;
	}
	cout<<ans;
}