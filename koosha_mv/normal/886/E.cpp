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
//math
const int N=1e6+4,mod=1e9+7;
ll x,y,g,fac[N],dp[N],n,k,ans;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){
	if(r==0) return 1;
	ll ans=1;
	ans=fac[n];
	x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);
	ans=((ans*((x+mod)%mod)))%mod;return ans;
}
int main(){
	fac[0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	cin>>n>>k;
	dp[k+1]=fac[k];
	f(i,k+2,n){
		dp[i]=(dp[i-1]*i)%mod;
		dp[i]=(dp[i]+(((entekhab(k,i-1)*((fac[i-k-1]+mod-dp[i-k-1])%mod))%mod)*fac[k]))%mod;
	}
	f(i,k+1,n){
		ans=(ans+((dp[i]*fac[n-i-1])%mod)*entekhab(i,n-1))%mod;
	}
	cout<<ans;
}