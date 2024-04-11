#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;
const ll inf=1e18;

int n,t,u,v,w[N],mark[N];
ll dp0[N],dp1[N];
vector<int> g[N];
vector<int> ans;
bool vis[N][2];

void dfs(int x,int par){
	ll mx=0;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			dp0[x]+=dp0[g[x][i]];
			maxm(mx,dp0[g[x][i]]-dp1[g[x][i]]);
		}
	dp1[x]=dp0[x]-mx;
	if(dp1[x]+w[x]==dp0[x])
		dp0[x]=dp1[x]+w[x],mark[x]=2;
	if(dp1[x]+w[x]<dp0[x])
		dp0[x]=dp1[x]+w[x],mark[x]=1;
	if(g[x].size()==1 && x!=1)
		dp0[x]=w[x];
}
void dfs(int x,int par,int source){
	if(vis[x][source]) return ;
	vis[x][source]=1;
	ll mx=-1,t=0;
	if(g[x].size()==1 && x!=1){
		if(!source) ans.pb(x);
		return ;
	}
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			maxm(mx,dp0[g[x][i]]-dp1[g[x][i]]);
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			t+=((dp0[g[x][i]]-dp1[g[x][i]])==mx);
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			if((source || (!source && mark[x])) && dp0[g[x][i]]-dp1[g[x][i]]==mx)
				dfs(g[x][i],x,1);
			if((!source && mark[x]!=1) || dp0[g[x][i]]-dp1[g[x][i]]!=mx|| t>1)
				dfs(g[x][i],x,0);
		}
	if(mark[x] && !source) ans.pb(x);
}

int main(){
	cin>>n;
	f(i,1,n+1) gett(w[i]);
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	dfs(1,0,0);
	cout<<dp0[1]<<" "<<ans.size()<<'\n';
	sort(ans.begin(),ans.end());
	print(ans,ans.size());
}