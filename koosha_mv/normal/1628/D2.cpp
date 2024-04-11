#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e6+99,mod=1e9+7;

int n,t,inv2,a[N];

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

void Main(){
	int n,m,k,ans=0;
	cin>>n>>m>>k; n=n-m;
	if(n==0){
		cout<<1ll*m*k%mod<<'\n';
		return ;
	}
	int p=pow(inv2,n+m-1,mod);
	f(i,1,m+1){
		int u=n-1,r=m-i;
		Add(ans,1ll*i*C(u,u+r)%mod*p%mod);
		p=2ll*p%mod;
	}
	cout<<1ll*ans*k%mod<<'\n';
}

main(){
	inv2=pow(2,mod-2,mod);
	make_fac();
	cin>>t;
	while(t--){
		Main();
	}
}