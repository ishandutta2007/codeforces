#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define get(x) scanf("%I64d",&x)
#define gett(x) scanf("%d",&x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,mod=1e9+7;

int n,k,ans,a[N],dp[N],fac[N],Pow[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	dp[0]=1;
	fac[0]=1;
	cin>>n>>k;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1) fac[i]=1ll*fac[i-1]*(k+1-i)%mod;
	f(i,0,N) if(i<=k) Pow[i]=pow(n,k-i,mod);
	
	f(i,1,n+1){
		int k=1;
		f(j,i+1,n+1) k=1ll*k*a[j]%mod;
		f(c1,1,i+1){
			int res=1ll*dp[i-c1]*fac[c1]%mod*Pow[c1]%mod;
			res=1ll*res*k%mod;
			if(c1&1) Add(ans,res);
			else Add(ans,mod-res);
		}
		f_(j,n,1) Add(dp[j],1ll*dp[j-1]*a[i]%mod);
	}
	cout<<1ll*ans*pow(pow(n,k,mod),mod-2,mod)%mod;
}