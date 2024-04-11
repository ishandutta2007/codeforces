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

const int N=1e6+99,mod=1e9+7;

int fact[N],ifact[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void math(){fact[0]=1; f(i,1,N) fact[i]=1ll*fact[i-1]*i%mod; ifact[N-1]=pow(fact[N-1],mod-2,mod);f_(i,N-2,0) ifact[i]=1ll*ifact[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fact[n]*ifact[n-k]%mod*ifact[k]%mod;}

int n,k,ans,a[N],F[N],sz[N];
vector<int> g[N];

void dfs1(int u,int p){
	int sum=0,res=0;
	sz[u]=1;
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs1(v,u);
		sz[u]+=sz[v];
		F[v]=C(k,sz[v]);
		Add(sum,F[v]);
	}
	res=(C(k,sz[u])-sum+mod)%mod;
	Add(ans,1ll*res*(n-sz[u])%mod*sz[u]%mod);
	Add(sum,C(k,n-sz[u]));
	for(auto v : g[u]){
		if(v==p) continue ;
		Add(sum,mod-C(k,sz[v]));
		res=(C(k,n-sz[v])-sum+mod)%mod;
		Add(ans,1ll*res*sz[v]%mod*(n-sz[v])%mod);
		Add(sum,C(k,sz[v]));
	}
}
void dfs2(int u,int p){
	int res=C(k,n);
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs2(v,u);
		Add(res,mod-C(k,sz[v]));
	}
	Add(res,mod-C(k,n-sz[u]));
	Add(ans,1ll*res*n%mod);
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	math();
	cin>>n>>k;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,1);
	dfs2(1,1);
	cout<<ans<<'\n';
}