#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=3e5+9;
ll a[N][4],n,dp[2][N],gas[N],x,y,z,mx;
vector<pair<ll,ll> > g[N];
void dfs(int x,int par){
	f(i,0,g[x].size()){
		if(g[x][i].first!=par){
			dfs(g[x][i].first,x);
			dp[0][x]=max(dp[0][x],dp[0][g[x][i].first]-g[x][i].second);
			a[x][0]=dp[0][g[x][i].first]-g[x][i].second;
			sort(a[x],a[x]+3);
		}
	}
	dp[1][x]=a[x][1]+a[x][2]+gas[x];dp[0][x]+=gas[x];
}
int main(){
	cin>>n;
	f(i,1,n+1) cin>>gas[i];
	f(i,0,n-1){
		cin>>x>>y>>z;
		g[x].pb(make_pair(y,z));
		g[y].pb(make_pair(x,z));
	}
	dfs(1,0);
	f(i,1,n+1) mx=max(mx,dp[1][i]);
	cout<<mx;
}