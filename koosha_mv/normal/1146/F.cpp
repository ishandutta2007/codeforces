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
#define F first

const int N=2e5+9,mod=998244353;

int n,x,y,dp1[N],dp2[N];
vector<int> g[N];
void dfs(int x){
	dp1[x]=1,dp2[x]=1;
	int p=1,p0=1,p1=0;
	if(!g[x].size()) return ;
	f(i,0,g[x].size()){
		dfs(g[x][i]);
		dp1[x]=1ll*dp1[x]*(dp1[g[x][i]]+dp2[g[x][i]])%mod;
		p=1ll*p*dp2[g[x][i]];
		p1=((1ll*p1*dp2[g[x][i]])+(1ll*p0*dp1[g[x][i]]))%mod;
		p0=1ll*p0*dp2[g[x][i]]%mod;
	}
	dp2[x]=(dp1[x]+mod-p1)%mod;
	dp1[x]=(dp1[x]+mod-p0)%mod;
}
int main(){
	cin>>n;
	f(i,2,n+1){
		gett(x);
		g[x].pb(i);
	}
	dfs(1);
	cout<<dp2[1];
}