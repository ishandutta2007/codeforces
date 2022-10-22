#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll int
#define pb push_back
const int N=403,mod=1e9+7;
ll dp[N][N],x,y,k,n,rt,ans=1e9,edge[N][N],pdr[N];
vector<int> g[N],v[N][N];
int dfs1(int x,int par){
	pdr[x]=par;
	dp[x][0]=1;dp[x][1]=0;
	f(i,2,k+1) dp[x][i]=1e5;
	f(p,0,g[x].size()){
		if(g[x][p]!=par){
			dfs1(g[x][p],x);
			f_(i,k,1){
				dp[x][i]++;
				v[x][i].pb(0);
				f(j,1,i){
					if(dp[x][i]>dp[x][j]+dp[g[x][p]][i-j]){
						dp[x][i]=dp[x][j]+dp[g[x][p]][i-j];
						v[x][i]=v[x][j];
						v[x][i].pb(i-j);
					}
				}
			}
		} 
	}
}
int dfs2(int x,int s,int par){
	ll p1=0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			if(v[x][s][p1]==0)
				cout<<edge[x][g[x][i]]<<" ";
			else 
				dfs2(g[x][i],v[x][s][p1],x);
			p1++;
		}
	}
}
int main(){
	cin>>n>>k;
	f(i,1,n){
		cin>>x>>y;
		edge[x][y]=i;edge[y][x]=i;
		g[x].pb(y);g[y].pb(x);}
	dfs1(1,0);
	f(i,1,n+1){
		if(dp[i][k]+(i!=1)<ans){
			ans=dp[i][k]+(i!=1);
			rt=i;}
	}
	cout<<ans<<endl;
	if(ans){
		if(pdr[rt]>=1)
			cout<<edge[pdr[rt]][rt]<<" ";
		dfs2(rt,k,pdr[rt]);
	}
}