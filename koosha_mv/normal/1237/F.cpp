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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3609,mod=998244353,M=2400;

//math
ll p,fac[N],ifac[N],dp[2][N];
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
ll C(int k,int n){ if(k>n) return 0; return fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

ll h,w,n,a,b,c,d,t0,t1,ans,row[N],col[N];
vector<ll> v[2];

void make1(){
	ll t=0;
	row[h]=1;
	f(i,0,h+1){
		if(row[i]==0) t++,t0++;
		else{
			if(t>1) v[0].pb(t-1);
			t=0;
		}
	}
}
void make2(){
	ll t=0;
	col[w]=1;
	f(i,0,w+1){
		if(col[i]==0) t++,t1++;
		else{
			if(t>1) v[1].pb(t-1);
			t=0;
		}
	}
}
ll e(ll x,ll y){
	return C(x,y-x+1);
}
void solve(int src){
	dp[src][0]=1;
	f(i,0,v[src].size()){
		f_(j,M-1,1){
			f(k,1,min(v[src][i]/2+2,j+1))
				dp[src][j]=(dp[src][j]+dp[src][j-k]*e(k,v[src][i]))%mod;
		}
	}
}
main(){
	make_fac();
	cin>>h>>w>>n;
	f(i,0,n){
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		row[a]++,row[c]++,col[b]++,col[d]++;
		if(a==c) row[a--];
		else col[b]--;
	}
	make1();
	make2();
	solve(0);
	solve(1);
	f(i,0,M){
		f(j,0,M){
			p=dp[0][i]*dp[1][j]%mod*C(i,t1-j*2)%mod*C(j,t0-i*2)%mod*fac[i]%mod*fac[j]%mod;
			ans=(ans+p)%mod;
		}
	}
	cout<<ans;
}