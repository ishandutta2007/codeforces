#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll mark2[200009],dp[200009],ans,x,y,n,sefid[200009],siah[200009],mark1[200009],tse,tsi;
vector<ll> g[200009];
void dfs1(ll x,ll dis){
	mark1[x]=1;
	f(i,0,g[x].size()){
		if(mark1[g[x][i]]==0){
			dfs1(g[x][i],dis+1);
			sefid[x]+=sefid[g[x][i]],siah[x]+=siah[g[x][i]];
		}
	}
	sefid[x]+=(dis%2==0),siah[x]+=dis%2;
	dp[1]+=(dis+1)/2;
	tse+=(dis%2==0),tsi+=(dis%2==1);
}
void dfs2(ll x,ll dis,ll gh){
	mark2[x]=1;
	if(x!=1){
		if(dis%2==0) dp[x]=dp[gh]-sefid[x]+(tsi-siah[x]);
		else dp[x]=dp[gh]-siah[x]+(tse-sefid[x]);
	}
	ans+=dp[x];
	f(i,0,g[x].size()){
		if(mark2[g[x][i]]==0)
			dfs2(g[x][i],dis+1,x);}
}
int main(){
	cin>>n;
	f(i,0,n-1){cin>>x>>y,g[x].pb(y),g[y].pb(x);}
	dfs1(1,0);
	dfs2(1,0,0);
	cout<<ans/2;
}