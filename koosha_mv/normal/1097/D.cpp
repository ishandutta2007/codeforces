#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const ll N=1e5+9,mod=1e9+7,M=50;

ll fac[N],ifac[N],p,q,b,cn,m,nd[N],ans,x,y;
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
ll C(int k,int n){return fac[n]*ifac[n-k]%mod*ifac[k]%mod;}
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll makoos(ll o){
	x=1,y=1,xgcd(o,mod,x,y);
	return (x+mod)%mod;
}
ll n,k,t;
ll dp[M][M][10020];
vector<ll> d;
vector<pair<ll,ll> > pr;

ll solve(ll x){
	ll res=1,cx=x;
	f(i,0,pr.size()){
		ll t=0;
		while(cx%pr[i].F==0)
			t++,cx/=pr[i].F;
		if(t>0) p=(dp[t][pr[i].S][k]-dp[t-1][pr[i].S][k]+mod)%mod;
		else p=dp[t][pr[i].S][k];
		res=res*p%mod*(t+1ll)%mod;
	}
	x%=mod;
	return res*x%mod;
}
int main(){
	Get(n,k);
	dp[0][0][0]=1;
	f(j,0,M){
		dp[j][j][0]=makoos(j+1ll);
		f(l,1,k+1){
			f(i,0,j+1){
				dp[i][j][l]=dp[j][j][l-1];
				if(i>0) dp[i][j][l]=(dp[i][j][l]+mod-dp[i-1][j][l-1]);
				dp[i][j][l]=dp[i][j][l]*makoos(i+1)%mod;
				if(i>0) dp[i][j][l]=(dp[i][j][l]+dp[i-1][j][l])%mod;	
			}
		}
	}
	cn=n;
	for(ll i=2;i*i<=cn;i++){
		if(cn%i==0){
			pr.pb(mp(i,0));
			while(cn%i==0)
				pr[pr.size()-1].S++,cn/=i;
		}
	}
	if(cn>1)
		pr.pb(mp(cn,1));
	for(ll j=1;j*j<=n;j++){
		if(n%j==0){
			ans+=solve(j),ans%=mod;
			if(j*j!=n)
				ans+=solve(n/j),ans%=mod;
		}
	}
	cout<<ans%mod;
}