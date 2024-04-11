#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,x,y,mx,ans,jvb=1e9;
vector<pair<int,int> > g[3090];
void dfs(ll x,ll par,ll m){
	mx=max(mx,m);
	f(i,0,g[x].size()){
		if(g[x][i].first!=par){
			if(g[x][i].second==1)
				dfs(g[x][i].first,x,max((ll)0,m-1));
			else{
				ans++;
				dfs(g[x][i].first,x,m+1);
			}
		}
	}
}
int main(){
	cin>>n;
	f(i,0,n-1){
		cin>>x>>y;
		g[x].pb(make_pair(y,1));
		g[y].pb(make_pair(x,0));
	}
	f(i,1,n+1){
		ans=0,mx=0;
		dfs(i,-1,0);
		jvb=min(jvb,ans-mx);
	}
	cout<<jvb;
}