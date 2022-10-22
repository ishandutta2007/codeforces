#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=2e5+9;
ll n,k,ans,ansf1,x,y;
ll dp[N][7],dp2[N][7],m[6];
vector<int> g[N];
void bbr_jolo(int x){
	f(i,0,k)
		m[i]=dp[x][(i+k-1)%k];
	f(i,0,k)
		dp[x][i]=m[i];
}
void dfs1(int x,int par,int dis){
	ansf1+=(dis+k-1)/k;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs1(g[x][i],x,dis+1);
			f(j,0,k){
				dp[x][j]+=dp[g[x][i]][j];
			}
		}
	}
	bbr_jolo(x);
	dp[x][0]++;
}
void dfs2(int x,int par){
	if(x!=1){
		dp2[x][6]=dp2[par][6]+(dp2[par][0]-dp[x][k-1])-dp[x][0];
		ansf1+=dp2[x][6];
		f(i,0,k)
			dp2[x][i]=dp2[par][(i+k-1)%k]-dp[x][(i+k-2)%k];
		f(i,0,k)
			dp2[x][i]+=dp[x][i];
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs2(g[x][i],x);
		}
	}
}
int main(){
	cin>>n>>k;
	f(i,0,n-1){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs1(1,0,0);
	f(i,0,k) dp2[1][i]=dp[1][i];
	dp2[1][6]=ansf1;
	dfs2(1,0);
	cout<<ansf1/2;
}