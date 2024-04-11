#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=2e5+9;
ll dp[N],n,x,y,k,ans;
vector<int> g[N];
int dfs(int x,int par){
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);dp[x]+=dp[g[x][i]];
		}
	}
	ans+=min(dp[x],k-dp[x]);
}
int main(){
	cin>>n>>k;k*=2;
	f(i,0,k){ cin>>x; dp[x]++; }
	f(i,0,n-1){ cin>>x>>y; g[x].pb(y); g[y].pb(x); }
	dfs(1,0);
	cout<<ans;
}