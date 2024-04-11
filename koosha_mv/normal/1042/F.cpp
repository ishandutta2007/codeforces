#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,rt,t,k,u,v;
vector<int> g[N];
pair<int,int> dp[N];

void dfs(int u,int par){
	vector<int> v;
	int ans=0;
	dp[u].S=N;
	f(i,0,g[u].size())
		if(g[u][i]!=par){
			dfs(g[u][i],u);
			v.pb(dp[g[u][i]].S);
			dp[u].F+=dp[g[u][i]].F;
		}
	if(sz(g[u])==1) dp[u]=mp(1,1);
	sort(v.begin(),v.end());
	f(i,0,sz(v)){
		ans+=(v[i]>k/2 || (v[i]<=k/2 && (i==sz(v)-1 || v[i]+v[i+1]>k)));
		if(dp[u].S==N && (v[i]>k/2 || (v[i]<=k/2 && (i==sz(v)-1 || v[i]+v[i+1]>k)))) dp[u].S=v[i]+1;
	}
	dp[u].F-=sz(v)-ans;
}

int main(){
	cin>>n>>k;
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	while(g[++rt].size()<2){}
	dfs(rt,0);
	cout<<dp[rt].F;
}