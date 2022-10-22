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

const int N=1e7+99,K=19,mod=998244353,lmc=720720;

int n,t,x,y,k,M,ans,a[N],Pow[K],dp[lmc][K];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

main(){
	cin>>n>>a[0]>>x>>y>>k>>M;
	Pow[0]=1;
	f(i,1,K) Pow[i]=1ll*n*Pow[i-1]%mod;
	f(i,1,n){
		a[i]=(1ll*x*a[i-1]+y)%M;
	}
	f(i,0,n){
		int x;
		x=a[i]/lmc*lmc;
		a[i]%=lmc;
		Add(ans,1ll*x*k%mod*pow(n,k-1,mod)%mod);
	}
   f(i,1,lmc){
   	f_(j,k,1){
   		int x=i/j*j;
   		dp[i][j]=1ll*(n-1)*dp[i][j+1]%mod;
   		Add(dp[i][j],dp[x][j+1]);
   		Add(dp[i][j],1ll*i*Pow[k-j]%mod);
   		//cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
		}
	}
	f(i,0,n){
		Add(ans,dp[a[i]][1]);
	}
	cout<<ans;
}
/*
3 1 1 1 2 100
*/