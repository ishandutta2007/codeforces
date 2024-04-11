#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e5+9;
ll n,mod=1e9+7,a[N],ans,x,y;
vector<int> g[N];
map<ll,int> mark[N];
void dfs(int x,int par){
	mark[x][a[x]]++;
	if(par){
		for(auto it:mark[par])
			mark[x][__gcd(a[x],it.F)]+=it.S;
	}
	for(auto it:mark[x])
		ans=(ans+(it.F%mod)*(it.S%mod)%mod)%mod;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x);
	mark[x].clear();
}
int main(){
	cin>>n;
	f(i,1,n+1) get(a[i]);
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	cout<<ans<<endl;
}