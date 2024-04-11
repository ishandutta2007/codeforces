#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define m(x) x=x%mod;
const int N=255,mod=1e9+7;
//math
ll x,y,g,fac[N],dp[N],n,k,s1,s2,p1,p2;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}
ll tavan(ll x,ll y){
	if(y==0) return 1;
	if(y%2==0){
		ll o=tavan(x,y/2);
		return (o*o)%mod;
	}
	return (tavan(x,y-1)*x)%mod;
}
int main(){
	cin>>n>>k;
	fac[0]=1;
	
	f(i,1,N-1) fac[i]=(fac[i-1]*i)%mod;
	
	p1=tavan(k-1,n);
	f(i,1,n+1){
		dp[i]=tavan(k,i*n);
		s1=tavan(k,i);
		s2=tavan(k-1,i);
		s1=(s1+mod-s2)%mod;
		f(j,1,n+1)
			dp[i]=(dp[i]+mod-(((entekhab(j,n)*tavan(s2,j))%mod)*tavan(s1,n-j)%mod))%mod;
		f(j,1,i){
			dp[i]=(dp[i]+mod-((((entekhab(j,i)*tavan(p1,j))%mod)*dp[i-j])%mod))%mod;
		}
	}
	cout<<dp[n];
}