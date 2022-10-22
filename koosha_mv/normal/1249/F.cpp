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
const int N=209;
ll n,dp[N][N],a[N],b1[N][N],b2[N][N],k,ans,x,y;
vector<int> g[N],g1[N];
void dfs1(int x,int par){
	f(i,0,g1[x].size()){
		if(g1[x][i]!=par){
			g[x].pb(g1[x][i]);
			dfs1(g1[x][i],x);
		}
	}
}
void dfs(int x){
	dp[x][0]=a[x];
	f(i,0,g[x].size())
		dfs(g[x][i]);
	if(x==1) cout<<endl;
	f(i,0,g[x].size()){
		f(j,k/2,k+1){
			if(i==0)
				b1[g[x][i]][j]=dp[g[x][i]][j-1];
			else
				b1[g[x][i]][j]=b1[g[x][i-1]][j]+dp[g[x][i]][j-1];
		}
	}
	f_(i,g[x].size()-1,0){
		f(j,k/2,k+1){
			if(i==g[x].size()-1)
				b2[g[x][i]][j]=dp[g[x][i]][j-1];
			else
				b2[g[x][i]][j]=b2[g[x][i+1]][j]+dp[g[x][i]][j-1];
		}
	}
	f(i,0,g[x].size()){
		dp[x][0]+=dp[g[x][i]][k-1];
		f(j,1,k+1){
			ans=0;
			if(i>0)
				ans+=b1[g[x][i-1]][max(j,k-j)];
			if(i<g[x].size()-1)
				ans+=b2[g[x][i+1]][max(j,k-j)];
			ans+=dp[g[x][i]][j-1];
			maxm(dp[x][j],ans);
		}
	}
	f_(i,k-1,0)
		maxm(dp[x][i],dp[x][i+1]);
}
int main(){
	cin>>n>>k;k++;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n){
		cin>>x>>y;
		g1[x].pb(y);
		g1[y].pb(x);
	}
	dfs1(1,0);
	dfs(1);
	cout<<dp[1][0]<<endl;
}