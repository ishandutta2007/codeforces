#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll d,ans,n,cost[200009],g[200009],deg[200009],mark[200009],mark2[200009],mark3[200009];
vector<ll> g2[200009];
ll dfs(ll x){
	mark[x]=1;
	f(i,0,g2[x].size()){
		if(mark[g2[x][i]]==0) dfs(g2[x][i]);}}
ll dfs2(ll x){
	mark[x]=1;
	if(mark[g[x]]==1){return x;}	
	return dfs2(g[x]);}
ll dfs1(ll x){
	mark[x]=1;mark2[x]=1;
	f(i,0,g2[x].size()){
		if(mark2[g2[x][i]]==0) 
			dfs1(g2[x][i]);}
}
ll dfs3(ll x,ll mn){
	mark3[x]=1;mn=min(mn,cost[x]);
	if(mark3[g[x]]==1) return mn;
	return dfs3(g[x],mn);}
int main(){
	cin>>n;
	f(i,0,n) scanf("%I64d",&cost[i]);
	f(i,0,n){
		scanf("%I64d",&g[i]);g[i]--;
		if(g[i]==i){deg[i]=1;}
		g2[g[i]].push_back(i);}
	f(i,0,n){
		if(deg[i]==1){
			dfs(i);
			ans+=cost[i];
	}}
	f(i,0,n){
		if(mark[i]!=1){
			d=dfs2(i);
			dfs1(d);
			ans+=dfs3(d,1e9);
		}
	}
	cout<<ans;
}