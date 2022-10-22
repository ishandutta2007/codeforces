#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=3e5+99;
ll ans[N],n,m,x,y,v,d,mark[N],e=3e5+80;
vector<pair<ll,ll> > v1[N];
vector<ll> g[N];
int dfs(ll x,ll sum,ll par,ll dis){
	f(i,0,v1[x].size()){
		sum+=v1[x][i].first;
		mark[min(dis+v1[x][i].second+1,e)]+=v1[x][i].first;
	}
	sum-=mark[dis];
	ans[x]=sum;
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			dfs(g[x][i],sum,x,dis+1);
	}
	f(i,0,v1[x].size()){
		sum+=v1[x][i].first;
		mark[min(dis+v1[x][i].second+1,e)]-=v1[x][i].first;
	}
}
int main(){
	cin>>n;
	f(i,0,n-1){
		scanf("%I64d%I64d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);}
	cin>>m;
	f(i,0,m){
		scanf("%I64d%I64d%I64d",&v,&d,&x);
		v1[v].pb(make_pair(x,d));
	}
	dfs(1,0,0,0);
	f(i,1,n+1) cout<<ans[i]<<" ";
}