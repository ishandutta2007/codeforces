#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,t,u,v,s1,s2,a[N],b[N],c[N],dp0[N],dp1[N];
ll ans;
vector<int> g[N];

void dfs1(int x,int par){
	if(x!=1) minm(a[x],a[par]);
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs1(g[x][i],x);
}
void dfs(int x,int par){
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x),dp1[x]+=dp1[g[x][i]],dp0[x]+=dp0[g[x][i]];
	if(c[x]+b[x]==1){
		if(c[x]==1) dp1[x]++;
		else dp0[x]++;
	}
	ll p=min(dp0[x],dp1[x]);
	ans+=1ll*a[x]*p;
	dp0[x]-=p;
	dp1[x]-=p;
}

int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i]>>b[i]>>c[i];
		s1+=b[i],s2+=c[i];
	}
	if(s1!=s2) return cout<<-1,0;
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,0);
	dfs(1,0);
	cout<<ans*2ll;
}