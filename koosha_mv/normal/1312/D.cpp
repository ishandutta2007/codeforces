#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+99,mod=998244353;
ll n,m,ans,fac[N],p,tvn[N];
//math
ll x,y,g;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r>n) return 0;if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}
ll tavan(ll x,ll y){ll p;if(y==0) return 1;if(y%2==0){p=tavan(x,y/2);return (p*p)%mod;}return (tavan(x,y-1)*x)%mod;}

int main(){
	fac[0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	tvn[0]=1;
	f(i,1,N) tvn[i]=(tvn[i-1]*2)%mod;
	if(n==2) return cout<<0,0;
	cin>>n>>m;
	f(i,2,m+1){
		p=(((entekhab(n-2,i-1)*tvn[n-3])%mod*(n-2))%mod)%mod;
		ans=(ans+p)%mod;
	}
	cout<<ans;
}