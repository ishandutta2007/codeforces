#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+99;
ll n,m,w[N],e=1e6,cnt=1,dp[N],dp1[N],mark[N],ans,mx,x,y,s;
vector<ll> g[N];
map<ll,ll> brshi;
void dfs(int x,int par){
	mark[x]=1;
	dp[x]=w[x];
	ll p=0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par && mark[g[x][i]]==1)
			dp1[x]=1;
	}
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0){
			dfs(g[x][i],x);
			dp1[x]+=dp1[g[x][i]];
			maxm(p,dp[g[x][i]]);
		}
	}
	dp[x]+=p;
	if(dp1[x]==0){
		ans-=w[x];
		maxm(mx,dp[x]);
	}
}
int main(){
	cin>>n>>m;
	f(i,1,n+1){
		get(w[i]);
		ans+=w[i];
	}
	f(i,0,m){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	cin>>s;
	dfs(s,0);
	cout<<ans+mx;
}