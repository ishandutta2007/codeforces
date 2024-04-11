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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9,mod=1e9+7,K=206;
int n,k,x,y,rt,sub[N];
vector<int> g[N];

ll ans,dp[N][K],t2[N],fac[N],ifac[N],a[K],b[K][K];
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
ll C(int k,int n){return fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

void make_b(){
	b[0][0]=1;
	f(i,1,K)
		f(j,i,K)
			f(l,1,j+1)
				b[i][j]=(b[i][j]+b[i-1][j-l]*C(l,j))%mod;
}

ll e(ll x,ll y){
	return b[x][k];
}
void dfs(int x,int par){
	sub[x]=1,dp[x][0]=2ll;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x);
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			f_(j,min(sub[g[x][i]],k),2){
				ans=(ans+dp[g[x][i]][j-1]*(t2[n-sub[g[x][i]]]-1)%mod*e(j,k))%mod;
				dp[g[x][i]][j]=(dp[g[x][i]][j]+dp[g[x][i]][j-1])%mod;
			}
			ans=(ans+(t2[sub[g[x][i]]]-1ll)*(t2[n-sub[g[x][i]]]-1ll))%mod;
			dp[g[x][i]][1]=(dp[g[x][i]][1]+(t2[sub[g[x][i]]]-1ll))%mod;
		}
		
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			sub[x]=sub[x]+sub[g[x][i]];
			f_(j,min(sub[x],k),0){
				dp[x][j]=dp[x][j]*dp[g[x][i]][0]%mod;
				f(l,max(j-sub[g[x][i]],0),min(j,sub[x]-sub[g[x][i]]))
					dp[x][j]=(dp[x][j]+dp[x][l]*dp[g[x][i]][j-l])%mod;
			}
		}
	f(i,1,k+1) a[i]=dp[x][i];
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			f(j,1,min(sub[g[x][i]],k)+1)
				a[j]=(a[j]+mod-(dp[g[x][i]][j]*t2[sub[x]-sub[g[x][i]]]%mod))%mod;
		}
	f(i,1,k+1)
		ans=(ans+e(i,k)*a[i]%mod*t2[n-sub[x]])%mod;
}
int main(){
	make_fac();
	make_b();
	t2[0]=1;
	f(i,1,N) t2[i]=t2[i-1]*2ll%mod;
	
	Gett(n,k);
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	printf("%I64d",ans);
}