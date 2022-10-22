#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,dp1[N],dp2[N],dp3[N],x,y,ans;
// 1:asli & 2:rishe brdashte & 3:rishe not ok
vector<int> g[N];
int dfs2(ll x,ll par){
	dp2[x]=1;
	ll mn=1e9;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs2(g[x][i],x);
			dp2[x]+=dp3[g[x][i]];
			dp3[x]+=dp1[g[x][i]];
			minm(mn,dp2[g[x][i]]-dp1[g[x][i]]);	
		}
	}
	dp1[x]=dp3[x]+mn;
	minm(dp3[x],dp2[x]);
	minm(dp1[x],dp2[x]);
	return 0;
}
int dfs(ll x,ll par,ll dis){
	if(dis==2){
		dfs2(x,par);
		ans+=min(dp3[x],dp1[x]);
		return 0;
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			dfs(g[x][i],x,dis+1);
	}
	return 0;
}
int main(){
	
	cin>>n;
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);g[y].pb(x);
	}
	
	dfs(1,0,0);
	cout<<ans;
}