#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
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

const int N=5009,mod=998244353;

int n,a,b,p,e,dp[N][N],stcc[N],ans[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
int C(int x){
	return x*(x-1)/2;	
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	p=1ll*pow(b,mod-2,mod)*a%mod;
	e=(mod+1-p);
	dp[0][0]=1;
	stcc[0]=1;
	f(i,0,n+1){
		f(j,0,i+1){
			Add(dp[i+1][j],1ll*dp[i][j]*pow(p,j,mod)%mod);
			Add(dp[i+1][j+1],1ll*dp[i][j]*pow(e,i-j,mod)%mod);
		}
	}
	f(i,1,n+1){
		f(j,1,i){
			Add(ans[i],1ll*dp[i][j]*stcc[j]%mod*((1ll*C(j)+ans[j]+ans[i-j]+1ll*j*(i-j))%mod)%mod);
			Add(stcc[i],1ll*dp[i][j]*stcc[j]%mod);
		}
		int mv=stcc[i];
		stcc[i]=(mod+1-stcc[i])%mod;
		Add(ans[i],1ll*stcc[i]*C(i)%mod);
		ans[i]=1ll*ans[i]*pow(mv,mod-2,mod)%mod;
	}
	cout<<ans[n];
}