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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99;

int n,m,u,v,ans,a[N],dp[N];
vector<int> g[N];

void solve(int x){
	if(dp[x]>-1) return ;
	if(a[x]) dp[x]=1;
	f(i,0,g[x].size()){
		solve(g[x][i]);
		if(a[g[x][i]]==0 && a[x]==1){
			maxm(dp[x],dp[g[x][i]]+1);
		}
		else
			maxm(dp[x],dp[g[x][i]]);
	}
	maxm(ans,dp[x]);
}

int main(){
	fill(dp,dp+N,-1);
	cin>>n>>m;
	f(i,0,n) gett(a[i]);
	f(i,0,m){
		Gett(u,v);
		g[v].pb(u);
	}
	f(i,0,n)
		solve(i);
	cout<<ans;
}