#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define F first
#define s second
const int N=2e5+9;
ll n,dp[N][2],ans[N][2],x,y,z,k,men[N][2];
vector<pair<int,int> > g[N];
void dfs1(int x,int par){
	dp[x][0]=dp[x][1]=1;
	f(i,0,g[x].size()){
		if(g[x][i].F!=par){
			dfs1(g[x][i].F,x);
			if(g[x][i].s==1){
				dp[x][1]+=dp[g[x][i].F][1];
				dp[x][0]+=dp[g[x][i].F][1];
			}
			else
				dp[x][0]+=dp[g[x][i].F][0];
		}
	}
}
int dfs(int x,int par,int j){
	if(x==1){ans[x][0]=dp[x][0],ans[x][1]=dp[x][1];}
	else{
		if(j==1){
			ans[x][1]=ans[par][1];
			ans[x][0]=ans[x][1]+dp[x][0]-dp[x][1];
		}
		else{
			ans[x][1]=dp[x][1];
			ans[x][0]=ans[par][0];
		}
	}
	f(i,0,g[x].size()){
		if(g[x][i].F!=par){
			dfs(g[x][i].F,x,g[x][i].s);
		}
	}
}
int main(){
	cin>>n;
	f(i,1,n){
		cin>>x>>y>>z;
		g[x].pb(make_pair(y,z));
		g[y].pb(make_pair(x,z));}
	dfs1(1,0);
	dfs(1,0,0);
	f(i,1,n+1){
		ans[i][0]+=ans[i-1][0];
	}
	cout<<ans[n][0]-n;
}