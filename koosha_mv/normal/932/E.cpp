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

const int N=5004;

ll n,k,mod=1e9+7,fac[N],x,y,g,s[N][N],ans,l,sfr;
map<ll,ll> g2;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){
	r=min(r,n-r);
	if(r==0) return 1;
	ll ans=g2[n-r];
	x=1,y=1,g=xgcd(fac[r],mod,x,y);
	ans=(ans*((x+mod)%mod))%mod;
	return ans;
}

ll tavan(ll x,ll y){
	if(y==0) return 1;
	if(y%2==0){
		ll p=tavan(x,y/2);
		return (p*p)%mod;
	}
	return (tavan(x,y-1)*x)%mod;
}
int main(){
	fac[0]=1;s[0][0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	
	f(i,1,N){
		f(j,1,i+1)
			s[i][j]=(((s[i-1][j]*j)%mod)+s[i-1][j-1])%mod;
	}
	cin>>n>>k;
	g2[n]=1;
	f_(i,n-1,max(n-k-3,sfr))
		g2[i]=(g2[i+1]*(i+1))%mod;
	f(i,1,min(k,n)+1){

		l=(s[k][i]*fac[i])%mod;
		l=(l*entekhab(i,n))%mod;
		l=(l*tavan(2,n-i))%mod;
		ans=(ans+l)%mod;
	}
	cout<<ans;
}