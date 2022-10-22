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
const int N=2020;
ll n,m,x,y,cnt=1,dp[N],z[N],mark1[N],w[N],mark2[N],sub[N],ans1,ans,sum,a;
vector<int> g1[N],g[N];
void dfs1(int x,int par){
	mark1[x]=1;
	f(i,0,g1[x].size()){
		if(mark1[g1[x][i]]==1 && g1[x][i]!=par)
			z[x]++,z[g1[x][i]]--;
	}
	f(i,0,g1[x].size()){
		if(mark1[g1[x][i]]==0){
			dfs1(g1[x][i],x);
			z[x]+=z[g1[x][i]];
		}
	}
}
void dfs2(int x,int cn){
	mark2[x]=1;
	w[cn]++;
	f(i,0,g1[x].size()){
		if(mark2[g1[x][i]]==0){
			if(z[g1[x][i]]==0){
				cnt++;
				g[cn].pb(cnt);
				g[cnt].pb(cn);
				dfs2(g1[x][i],cnt);
			}
			else
				dfs2(g1[x][i],cn);
		}
	}
}
void dfs(int x,int par){
	sub[x]=w[x];
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			sub[x]+=sub[g[x][i]];
		}
	}
	ans+=sub[x]*w[x];
}
ll solve(int par){
	f(i,0,N) dp[i]=0,sub[i]=0;
	sum=0,ans=0,a=0;
	dp[0]=1;
	dfs(par,0);
	f(j,0,g[par].size()){
		sum+=sub[g[par][j]];
		f_(i,N-1,sub[g[par][j]])
			dp[i]=(dp[i] || dp[i-sub[g[par][j]]]);
	}
	f(i,0,N){
		if(dp[i]==1)
			maxm(a,i*(sum-i));
	}
	return a+ans;
}
int main(){
	Get(n,m);
	f(i,0,m){
		Get(x,y);
		g1[x].pb(y);
		g1[y].pb(x);
	}
	dfs1(1,0);
	
	dfs2(1,1);cnt++;
	
	f(pr,0,cnt)
		maxm(ans1,solve(pr));
	
	cout<<ans1<<endl;
}