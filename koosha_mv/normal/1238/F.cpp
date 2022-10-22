#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll mx,q,dp1[300009],deg[300009],n,x,y,pdr;
vector<int> g[300009];
int dfs1(int x,int par){
	if(deg[x]==1 ){dp1[x]=1;return 0;}
	ll ans=deg[x]-(x!=pdr);
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs1(g[x][i],x),dp1[x]=max(dp1[x],dp1[g[x][i]]);
		}
	}
	dp1[x]+=ans;
	return 0;
}
int dfs2(int x,int par){
	ll ans=0,mx1=0,mx2=0;
	if(deg[x]==1) return 0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs2(g[x][i],x);
			if(dp1[g[x][i]]>=mx1) mx2=mx1,mx1=dp1[g[x][i]];
			else mx2=max(mx2,dp1[g[x][i]]);
		}
	}
	mx=max(mx,mx1+mx2+deg[x]-1);return 0;
}
int main(){
	cin>>q;
	f(sal,0,q){
		mx=0;
		f(i,1,n+1) dp1[i]=0,deg[i]=0,g[i].clear();
		cin>>n;
		f(i,0,n-1) {cin>>x>>y;g[x].pb(y),g[y].pb(x),deg[x]++,deg[y]++;
			if(deg[x]>1) pdr=x;
			if(deg[y]>1) pdr=y;
		}
		dfs1(pdr,0);
		dfs2(pdr,0);
		if(n<=2) cout<<n<<endl;
		else cout<<min(mx,n)<<endl;
	}
}