#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=10000,mod=998244353;
ll n,a[N],dp[N],ans;
ll x,y,g,fac[N];
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r>n) return 0; if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}
int main(){
	cin>>n;fac[0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	f(i,0,n)
		get(a[i]);
	f_(i,n-1,0){
		if(a[i]>=1){
			f(j,i+a[i]+1,n+1){
				dp[i]=(dp[i]+(dp[j]*entekhab(a[i],j-i-1))%mod)%mod;
			}
			dp[i]=(dp[i]+entekhab(a[i],n-i-1))%mod;
		}

		ans=(ans+dp[i])%mod;
	}
	cout<<ans;
}