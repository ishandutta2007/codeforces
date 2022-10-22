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

const int N=1e6+99;

int n,t,a[N],sz[N],dp[N];
vector<int> g[N];

void dfs(int u,int p){
	sz[u]=1;
	f(i,0,g[u].size()) if(g[u][i]==p) g[u].erase(g[u].begin()+i);
	for(auto v : g[u]){
		dfs(v,u);
		sz[u]+=sz[v];
	}
	if(g[u].size()==0){
		dp[u]=0;
		return ;
	}
	if(g[u].size()==1){
		dp[u]=sz[g[u][0]]-1;
		return ;
	}
	dp[u]=max(dp[g[u][0]]+sz[g[u][1]]-1,dp[g[u][1]]+sz[g[u][0]]-1);
}
void Main(){
	cin>>n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,1);
	cout<<dp[1]<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,1,n+1) g[i].clear();
	}
}