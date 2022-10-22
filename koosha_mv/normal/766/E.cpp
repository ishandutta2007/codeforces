#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e5+10;
ll dp[N][20],n,x,y,sub[N],a[N],mark[N][20],d=2;
ll ans;
vector<int> g[N];
ll e(ll x){
	return (x*(x-1))/d;
}
void dfs(int x,int par){
	sub[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			sub[x]+=sub[g[x][i]];
			f(j,0,20)
				dp[x][j]+=dp[g[x][i]][j];
		}
	}
	int c=a[x];
	f(i,0,20){
		if(c%2==1)
			dp[x][i]=sub[x]-dp[x][i],mark[x][i]=1;
		c/=2;
	}
}
void Get_ans(int x,int par){
	ans+=a[x];
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			Get_ans(g[x][i],x);
			f(j,0,20){
				if(mark[x][j])
					ans-=(e(dp[g[x][i]][j])+e(sub[g[x][i]]-dp[g[x][i]][j]))*(1ll<<j);
				else
					ans-=dp[g[x][i]][j]*(sub[g[x][i]]-dp[g[x][i]][j])*(1ll<<j);
			}
		}
	f(i,0,20){
		if(mark[x][i])
			ans+=(e(dp[x][i])+e(sub[x]-dp[x][i]))*(1ll<<i);
		else
			ans+=dp[x][i]*(sub[x]-dp[x][i])*(1ll<<i);
	}
}
int main(){
	cin>>n;
	f(i,1,n+1)
		cin>>a[i];
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	Get_ans(1,0);
	cout<<ans<<endl;
}