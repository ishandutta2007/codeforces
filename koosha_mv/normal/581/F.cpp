#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=5003;
int dp[N][N],n,x,y,sub[N],pr=1;
vector<int> g[N];
void subt(int x,int par){
	if(g[x].size()==1) sub[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			subt(g[x][i],x);
			sub[x]+=sub[g[x][i]];
		}
	}
}
void dfs(int x,int par){
	// fuck
	f(i,1,N) dp[x][i]=1e6;
	if(g[x].size()==1) dp[x][1]=0,dp[x][0]=1e6;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			f_(j,sub[x],0){
				int p=1e6;
				f(l,0,min(sub[g[x][i]],j)+1){
					minm(p,dp[x][j-l]+dp[g[x][i]][l]);
					minm(p,dp[x][j-l]+dp[g[x][i]][sub[g[x][i]]-l]+1);
				}
				dp[x][j]=p;
			}
		}
	}
}
int main(){
	cin>>n;
	if(n==2){cout<<1;return 0;}
	f(i,1,n){
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	while(g[pr].size()==1) pr++;
	subt(pr,0);
	dfs(pr,0);
	cout<<dp[pr][sub[pr]/2];
}