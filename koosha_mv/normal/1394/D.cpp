#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define gett(x) scanf("%d",&x);
#define minm(a,b) a=min(a,b);
#define sz(x) int(x.size())
#define ll long long
#define pb push_back

const int N=2e5+99;
const ll inf=1e13;

int n,u,v,t[N],h[N];
ll ans,dp0[N],dp1[N];
vector<int> g[N];

void dfs(int x,int par){
	ll sum=0;
	vector<ll> e,v;
	v.pb(0);
	dp0[x]=dp1[x]=inf;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			sum+=dp0[g[x][i]];
			e.pb(dp0[g[x][i]]-dp1[g[x][i]]);
		}
	sort(e.begin(),e.end());
	reverse(e.begin(),e.end());
	f(i,0,e.size()) v.pb(e[i]);
	f(i,0,v.size()){
		if(i) v[i]+=v[i-1];
		if(1<x){
			minm(dp0[x],sum-v[i]+1ll*max(i+1,sz(v)-1-i)*t[x]);
			minm(dp1[x],sum-v[i]+1ll*max(i,sz(v)-i)*t[x]);
		}
		else
			minm(dp0[x],sum-v[i]+1ll*max(i,sz(v)-1-i)*t[x])
	}
	if(h[x]<h[par]) dp0[x]=inf;
	if(h[par]<h[x]) dp1[x]=inf;
}

int main(){
	cin>>n;
	f(i,1,n+1) gett(t[i]);
	f(i,1,n+1) gett(h[i]);
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	cout<<dp0[1];
}