#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
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

const int N=6005;

int n,u,v,c,ans,s[N],t[N],a[N],dp[2][N],par[N];
vector<int> g[N];

bool check_par(int u,int v){
	if(s[u]<=s[v] && s[v]<=t[u]) return 1;
	return 0;
}
void dfs(int x){
	s[x]=++c;
	f(i,0,g[x].size())
		if(g[x][i]!=par[x])
			par[g[x][i]]=x,dfs(g[x][i]);
	t[x]=c;
}
int calc0(int u){
	if(dp[0][u]) return dp[0][u];
	dp[0][u]=1;
	f(i,1,n+1)
		if(check_par(u,i) && a[u]<a[i])
			maxm(dp[0][u],calc0(i)+1);
	return dp[0][u];
}
int calc1(int u){
	if(dp[1][u] || u==1) return dp[1][u];
	dp[1][u]=1;
	f(i,1,n+1)
		if(!check_par(u,i) && !check_par(i,u) && a[i]>a[par[u]])
			maxm(dp[1][u],calc0(i)+1);
	f(i,2,n+1)
		if(check_par(i,u) && a[par[i]]>a[par[u]])
			maxm(dp[1][u],calc1(i)+1);
	return dp[1][u];
}

int main(){
	cin>>n;
	f(i,1,n+1) gett(a[i]);
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	f(i,1,n+1){
		maxm(ans,calc0(i));
		maxm(ans,calc1(i));
		if(i!=1 && a[par[i]]>a[i] && sz(g[i])==1) maxm(ans,calc1(i)+1);
	}
	cout<<ans;
}