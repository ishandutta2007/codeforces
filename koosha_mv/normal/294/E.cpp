#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const ll N=5004;
ll n,x,y,w,ans=1e18,sub1[N],sub[N],pr=1,anss,mn,minn[N];
vector<pair<ll,ll> > g[N];
void bfs(ll x,ll par,ll srt,ll cp){
	sub[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i].F!=par){
			bfs(g[x][i].F,x,srt,g[x][i].S);
			anss+=g[x][i].S*(sub[g[x][i].F]*(n-sub[g[x][i].F]));
			sub[x]+=sub[g[x][i].F];
		}
	}
	minn[x]=(((srt-sub[x])*(n-(srt-sub[x])))-(sub[x]*(n-sub[x])))*cp;
}
void bodo(ll x,ll par,ll c){
	c=c+minn[x];
	minm(mn,c);
	f(i,0,g[x].size()){
		if(g[x][i].F!=par) bodo(g[x][i].F,x,c);
	}
}
ll solve(ll x,ll par){
	anss=0,mn=0;
	bfs(x,par,sub1[x],0);
	bodo(x,par,0);
	anss+=mn,mn=0;
	bfs(par,x,n-sub1[x],0);
	bodo(par,x,0);
	anss+=mn;
	return anss;
}
void dfs(ll x,ll par,ll cp){
	sub1[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i].F!=par){
			dfs(g[x][i].F,x,g[x][i].S);
			sub1[x]+=sub1[g[x][i].F];
		}
	}
	if(pr!=0) minm(ans,solve(x,par)+(sub1[x]*(n-sub1[x]))*cp);
}
int main(){
	cin>>n;
	f(i,1,n){
		cin>>x>>y>>w;
		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));
	}
	dfs(1,0,0);
	cout<<ans;
}