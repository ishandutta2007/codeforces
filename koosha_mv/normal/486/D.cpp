#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,d,a[2099],x,y,ans,mod=1e9+7,e=1e4,mark[2099];
vector<int> g[2099];
int dfs(int x,int root,int par){
	ll j=1;
	if(a[x]>a[root] || (a[root]/e)-(a[x]/e)>d) return 0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			j=(j*(dfs(g[x][i],root,x)+1))%mod;
	}
	return j;
}
int main(){
	cin>>d>>n;
	f(i,1,n+1){
		cin>>a[i];
		mark[a[i]]++;
		a[i]=a[i]*e+mark[a[i]];
	}
	f(i,0,n-1){
		cin>>x>>y;
		g[x].pb(y),g[y].pb(x);
	}
	f(i,1,n+1)
		ans=(ans+dfs(i,i,-1))%mod;
	
	cout<<ans;
}