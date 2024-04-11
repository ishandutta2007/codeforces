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
#define S second
#define F first
const int N=5e5+99;
ll n,m,x,y,w[N],mark[N],a[N],mark1[N],dp1[N],dp2[N];
vector<ll> g[N];
void dfs(ll x,ll par){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(mark[g[x][i]] && g[x][i]!=par)
			w[g[x][i]]++,w[x]--;
	}
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			dfs(g[x][i],x);
			w[x]+=w[g[x][i]];
		}
	}
	if(w[x]==0) a[x]=1;
}
void dfs1(ll x){
	mark1[x]=1;
	vector<ll> v;
	v.pb(0),v.pb(0),v.pb(0);
	f(i,0,g[x].size()){
		if(!mark1[g[x][i]]){
			dfs1(g[x][i]);
			maxm(dp2[x],dp2[g[x][i]]);
			maxm(dp1[x],dp1[g[x][i]]+a[g[x][i]]);
			v[0]=dp1[g[x][i]]+a[g[x][i]];
			sort(v.begin(),v.end());	
		}
	}
	maxm(dp2[x],v[1]+v[2]);
}
int main(){
	Get(n,m);
	f(i,0,m){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);	
	}
	dfs(1,0);
	dfs1(1);
	cout<<dp2[1];
}