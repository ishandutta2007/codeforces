#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const ll M=21,Mx=1048576;
ll dp[Mx],g[M][M],t[M],x,p1,ans,n,a[M][Mx];
vector<ll> v[M];
ll aa(ll x,ll y){
	if(a[x][y]!=-1) return a[x][y];
	if(y==0) return 0;
	f_(i,M-2,0){
		if(y>=t[i])
			return g[x][i+1]+aa(x,y-t[i]);
	}
}
ll dfs(ll x){
	if(x==0) return 0;
	if(dp[x]!=-1) return dp[x];
	dp[x]=1e15;
	ll cx=x;
	f_(i,M-2,0){
		if(t[i]<=cx){
			minm(dp[x],dfs(x-t[i])+aa(i+1,x-t[i]));
			cx-=t[i];
		}
	}
	return dp[x];
}
ll solve(ll x,ll y){
	p1=0,ans=0;
	f(i,0,v[x].size()){
		while(p1<v[y].size() && v[y][p1]<v[x][i])
			p1++;
		ans+=p1;
	}
	return ans;
}

int main(){
	t[0]=1;
	f(i,1,M) t[i]=t[i-1]*2;
	cin>>n;
	f(i,0,n){
		get(x);
		v[x].pb(i);
	}
	f(i,1,M){
		f(j,1,M)
			g[i][j]=solve(i,j);
	}
	fill(dp,dp+Mx,-1);
	f(i,0,M) f(j,0,Mx) a[i][j]=-1;
	cout<<dfs(Mx-1);
}