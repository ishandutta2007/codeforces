#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

const int N=2020;

int n,mod,a[N],ans[N],dp[N][N],ps[N][N],f[N][N],t[N][N];
vector<int> g[N];

int fact[N],ifact[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void math(){fact[0]=1; f(i,1,N) fact[i]=1ll*fact[i-1]*i%mod; ifact[N-1]=pow(fact[N-1],mod-2,mod);f_(i,N-2,0) ifact[i]=1ll*ifact[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fact[n]*ifact[n-k]%mod*ifact[k]%mod;}

void dfs1(int u,int p){
	f(i,0,g[u].size()){
		if(g[u][i]==p){
			g[u].erase(g[u].begin()+i);
		}
	}
	for(auto v : g[u]){
		dfs1(v,u);
	}
	f(x,1,n+1){
		dp[u][x]=1;
		for(auto v : g[u]){
			dp[u][x]=1ll*dp[u][x]*ps[v][x]%mod;
		}
	}	
	f(i,0,g[u].size()){
		int v=g[u][i];
		if(i==0){
			f(j,1,n+1){
				f[v][j]=1;
			}
		}
		else{
			int prv=g[u][i-1];
			f(j,1,n+1){
				f[v][j]=1ll*f[prv][j]*ps[prv][j]%mod;
			}
		}
	}
	f_(i,((ll) g[u].size())-1,0){
		int v=g[u][i];
		if(v==g[u].back()){
			f(j,1,n+1){
				t[v][j]=1;
			}
		}
		else{
			int nxt=g[u][i+1];
			f(j,1,n+1){
				t[v][j]=1ll*t[nxt][j]*ps[nxt][j]%mod;
			}
		}
	}
	if(u!=1){
		for(auto v : g[u]){
			if(v==p) continue ;
			int sum=0;
			f(x,1,n+1){
				Add(dp[u][x],1ll*sum*dp[v][x]%mod);
				Add(sum,1ll*f[v][x]*t[v][x]%mod);
			}
		}
	}
	//cout<<u<<" -> "<<endl;
	f(i,1,n+1){
		//cout<<dp[u][i]<<" ";
		ps[u][i]=(ps[u][i-1]+dp[u][i])%mod;
	}
	//cout<<endl;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>mod;
	math();
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,1);
	f(i,1,n) ans[i]=dp[1][i];
	//dbga(ans,1,n);
	f(i,1,n){
		f(j,1,i){
			Add(ans[i],mod-1ll*ans[j]*C(j,i)%mod);
		}
	}
	f(i,1,n){
		cout<<ans[i]<<" ";
	}
}