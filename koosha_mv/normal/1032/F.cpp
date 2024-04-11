#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=3e5+9,mod=998244353;
//0:saresh ba kas bashe & 1:saresh bi kas bashe & 2:saresh tanha bashe 
ll n,dp[N][3],f1[N],x,y;
vector<int> g[N];
int dfs(int x,int par){
	dp[x][2]=dp[x][1]=1;
	ll men=1,ans1=1;
	f_(i,g[x].size()-1,0){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			f1[g[x][i]]=ans1;
			ans1*=(dp[g[x][i]][2]+dp[g[x][i]][0]*2);ans1%=mod;
		}
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dp[x][0]=(dp[x][0]+(((dp[x][1]*(dp[g[x][i]][1]+dp[g[x][i]][2]))%mod)*f1[g[x][i]]))%mod;
			dp[x][2]*=(dp[g[x][i]][2]+dp[g[x][i]][0]);dp[x][2]%=mod;
			dp[x][1]*=(dp[g[x][i]][2]+dp[g[x][i]][0]*2);dp[x][1]%=mod;
			men*=(dp[g[x][i]][2]+dp[g[x][i]][0]);men%=mod;
		}
	}
	dp[x][1]=(dp[x][1]-men+mod)%mod;
}
int main(){
	cin>>n;
	if(n==1){cout<<1;return 0;}
	f(i,1,n){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	cout<<(dp[1][0]+dp[1][2])%mod;
}