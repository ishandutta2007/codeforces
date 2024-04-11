#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+9;
int n,x,y,dp[N],dp1[N],sub[N],brg;
vector<int> g[N];

void dfs1(int x,int dist){
	f(i,0,g[x].size())
		dfs1(g[x][i],dist+1);
	if(!g[x].size()){
		brg++;
		dp[x]=1;return ;
	}
	if(!(dist%2)){
		dp[x]=N;
		f(i,0,g[x].size())
			minm(dp[x],dp[g[x][i]]);
	}
	else{
		dp[x]=0;
		f(i,0,g[x].size())
			dp[x]+=dp[g[x][i]];
	}
}
void dfs2(int x,int dist){
	f(i,0,g[x].size())
		dfs2(g[x][i],dist+1);
	if(!g[x].size()){
		dp1[x]=1;
		return ;
	}
	if(!(dist%2)){
		dp1[x]=0;
		f(i,0,g[x].size())
			dp1[x]+=dp1[g[x][i]];
	}
	else{
		dp1[x]=N;
		f(i,0,g[x].size())
			minm(dp1[x],dp1[g[x][i]]);
	}
}
int main(){
	cin>>n;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
	}
	dfs1(1,0);
	dfs2(1,0);
	cout<<brg-dp[1]+1<<" "<<dp1[1];
}