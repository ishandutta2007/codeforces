#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+9,mod=1e9+7;

int n,h,w,x,y,ans,dp0[N],dp1[N];
pair<int,pair<int,int> > p[N];

//math
ll fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
ll C(int k,int n){return fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int calc(int fr1,int fr2,int to1,int to2){
	if(to1<fr1 || to2<fr2) return 0;
	return C(to1-fr1,(to1-fr1)+(to2-fr2));
}

int main(){
	make_fac();
	
	cin>>h>>w>>n;
	ans=calc(1,1,h,w);
	f(i,0,n){
		Gett(x,y);
		p[i]=mp(x+y,mp(x,y));
	}
	sort(p,p+n);
	f(i,0,n){
		dp1[i]=calc(1,1,p[i].S.F,p[i].S.S);
		f(j,0,i){
			add(dp0[i],1ll*dp1[j]*calc(p[j].S.F,p[j].S.S,p[i].S.F,p[i].S.S)%mod);
			add(dp1[i],1ll*dp0[j]*calc(p[j].S.F,p[j].S.S,p[i].S.F,p[i].S.S)%mod)
		}
	}
	f(i,0,n){
		dp0[i]=1ll*dp0[i]*calc(p[i].S.F,p[i].S.S,h,w)%mod;
		dp1[i]=1ll*dp1[i]*calc(p[i].S.F,p[i].S.S,h,w)%mod;
		add(ans,dp0[i]);
		add(ans,mod-dp1[i]);
	}
	cout<<ans;
}