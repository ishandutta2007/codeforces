#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1003,mod=1e9+7;
ll m,n,k,s[N][N],ans,x,y,fac[1000009],g,a;
ll xgcd(ll a, ll b, ll &x, ll &y){
	if(b==0){x=1;y=0;return a;}
	ll x1,y1,gcd=xgcd(b,a%b,x1,y1);
	x=y1;
	y=x1- (long long)(a/b)*y1;
	return gcd;
}
ll tarkib(ll r,ll n){
	ll ans=1;
	ans=fac[n];
	x=1,y=1,g=xgcd(fac[n-r],mod,x,y);
	ans=(ans*((x+mod)%mod))%mod;
	return ans;
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
ll p(ll q,ll w){
	return (q*w)%mod;
}
int main(){
	cin>>n>>m>>k;
	if(m==1){cout<<tavan(k,n);return 0;}
	s[0][0]=1;fac[0]=1;
	f(i,1,1000001) fac[i]=(fac[i-1]*i)%mod;
	f(i,1,N){
		f(j,1,i+1)
			s[i][j]=(s[i-1][j-1]+(s[i-1][j]*j))%mod;
	}
	f(i,1,min(n,k)+1){
		f(j,max((ll)0,i*2-k),i+1){
			a=(s[n][i]*s[n][i])%mod;
			a=p(a,entekhab(i,k));
			a=p(a,entekhab(j,i));
			a=p(a,entekhab(i-j,k-i));
			a=p(a,fac[i]),a=p(a,fac[i]);
			a=p(a,tavan(j,(m-2)*n));
			ans=(ans+a)%mod;
		}
	}
	cout<<ans<<endl;
}