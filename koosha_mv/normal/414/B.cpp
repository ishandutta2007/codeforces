#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=2005;
ll ans,n,k,fac[N*2],mod=1e9+7,p,pr[N],cnt,l;
int ci,taj[N];

//math
ll x,y,g;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll c(ll r,ll n){if(r>n) return 0;if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}

int main(){
	fac[0]=1;
	f(i,1,N*2) fac[i]=fac[i-1]*i%mod;
	Gett(n,k);
	f(i,2,N){
		l=1;
		for(int j=2;j*j<=i;j++)
			if(i%j==0)
				l=0;
		if(l) pr[cnt++]=i;
	}
	f(i,1,n+1){
		f(j,0,cnt) taj[pr[j]]=0;
		ci=i;
		f(j,0,cnt)
			while(ci%pr[j]==0)
				ci/=pr[j],taj[pr[j]]++;
		p=1;
		f(j,0,cnt)
			p=p*c(k-1,taj[pr[j]]+k-1)%mod;
		(ans+=p)%=mod;
	}
	cout<<ans;
}