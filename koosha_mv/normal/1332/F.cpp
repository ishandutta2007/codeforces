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
const int N=3e5+9;
int n,x,y;
ll dp1[N],dp2[N],ans[N],mod=998244353,jvb;
vector<int> g[N];
void dfs(int x,int par){
	ll p=1,p2=1;
	dp2[x]=dp1[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			dp2[x]=dp2[x]*((dp1[g[x][i]]+dp2[g[x][i]]+1ll+ans[g[x][i]])%mod)%mod;
			dp1[x]=dp1[x]*(dp2[g[x][i]]+1ll+ans[g[x][i]])%mod;
			p=(p*(ans[g[x][i]]+1ll))%mod;
			p2=(p2*(ans[g[x][i]]+1))%mod;
		}
	}
	ans[x]=(p2+dp1[x]+dp2[x]+mod*2-p*2-1)%mod;
}
int main(){
	cin>>n;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	cout<<ans[1];
}