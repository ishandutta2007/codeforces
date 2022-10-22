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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second

const int N=1e5+9;

int n,rt=1,x,y,dp1[N],dp2[N],F[N],m1[N],m2[N],mnd[N],mxd[N],brg,ans=-1;
vector<int> g[N];

void dfs_dp(int x,int par){
	dp2[x]=N;
	if(g[x].size()==1) dp2[x]=0;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs_dp(g[x][i],x);
			maxm(dp1[x],dp1[g[x][i]]+1);
			minm(dp2[x],dp2[g[x][i]]+1);
		}
	
}
void dfs1(int x,int par,int cp){
	m1[x]=max(dp1[x],cp);
	int mx=cp;
	f_(i,g[x].size()-1,0)
		if(g[x][i]!=par){
			F[g[x][i]]=mx;
			maxm(mx,dp1[g[x][i]]+1);
		}
	mx=0;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs1(g[x][i],x,max(F[g[x][i]],mx)+1);
			maxm(mx,dp1[g[x][i]]+1);
		}
}
void dfs2(int x,int par,int cp){
	m2[x]=min(cp,dp2[x]);
	if(g[x].size()==1) m2[x]=cp;
	int mn=cp;
	f_(i,g[x].size()-1,0)
		if(g[x][i]!=par){
			F[g[x][i]]=mn;
			minm(mn,dp2[g[x][i]]+1);
		}
	mn=cp;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs2(g[x][i],x,min(F[g[x][i]],mn)+1);
			minm(mn,dp2[g[x][i]]+1);
		}
}
void dfs(int x,int par,int dist){
	minm(mnd[dist],int(g[x].size()));
	maxm(mxd[dist],int(g[x].size()));
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x,dist+1);
}
bool check(int x){
	fill(mnd,mnd+N,1e9);
	fill(mxd,mxd+N,0);
	dfs(x,0,0);
	f(i,0,N) if(mnd[i]!=mxd[i] && mnd[i]<N) return 0;
	return 1;
}
int main(){
	cin>>n;
	if(n<=2) return cout<<1,0; 
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(;g[rt].size()==1;rt++){}
	rt++;
	dfs_dp(rt,0);
	dfs1(rt,0,0);
	fill(F,F+N,N);
	dfs2(rt,0,N);
	f(i,1,n+1){
		if(g[i].size()==1 && brg==0 && m1[i]==m2[i]){
			brg++;
			if(check(i)) ans=i;
		}
		if(g[i].size()>1 && m1[i]==m2[i] && check(i)) ans=i;
	}
	cout<<ans;
}