#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+99,mod=1e9+7;
int n,a[N],x,y,ans[N],h[N],dp[N];
vector<int> g[N];
void dfs1(int x,int par){
	dp[x]=-1+((a[x]==1)*2);
	f_(i,g[x].size()-1,0){
		if(g[x][i]!=par){
			dfs1(g[x][i],x);
			dp[x]+=max(0,dp[g[x][i]]);
		}
		else
			g[x].erase(g[x].begin()+i);
	}
}
void dfs2(int x,int par,int c){
	ans[x]=dp[x]+max(c,0);
	int p=-1+((a[x]==1)*2)+max(c,0);
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			p+=max(dp[g[x][i]],0);
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			dfs2(g[x][i],x,p-max(dp[g[x][i]],0));
	}
}
int main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	f(i,1,n+1) cout<<ans[i]<<" ";
}