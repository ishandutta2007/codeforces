#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
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

int n,u,v,dp1[N],dp2[N],dp3[N],dp4[N],ans[N]; //1 : ghablesh 2: badesh 3 : hichvaght 4: baresh ndri
vector<pair<int,int> > g[N];

void dfs(int x,int par){
	dp3[x]=1;
	int p=0,res=1;
	f(i,0,g[x].size()){
		if(g[x][i].S!=par){
			dfs(g[x][i].S,x);
			dp1[x]=1ll*dp1[x]*ans[g[x][i].S]%mod;
			dp2[x]=1ll*dp2[x]*ans[g[x][i].S]%mod;
			if(!p){ 
				dp3[x]=1ll*dp3[x]*(dp1[g[x][i].S]+dp3[g[x][i].S])%mod;
				dp1[x]=(dp1[x]+1ll*res*(dp2[g[x][i].S]+dp4[g[x][i].S])%mod)%mod;
			}
			else{	
				dp3[x]=1ll*dp3[x]*ans[g[x][i].S]%mod;
				dp2[x]=(dp2[x]+1ll*res*(dp2[g[x][i].S]+dp4[g[x][i].S])%mod)%mod;
			}
			res=1ll*res*((1ll*dp1[g[x][i].S]+dp3[g[x][i].S])%mod)%mod;
		}
		else p=1;
	}
	dp4[x]=res;
	ans[x]=(1ll*dp1[x]+1ll*dp2[x]+1ll*dp4[x])%mod;
//	cout<<x<<" : "<<dp1[x]<<" "<<dp2[x]<<" "<<dp3[x]<<" "<<dp4[x]<<" ANS : "<<ans[x]<<endl;
}

int main(){
	cin>>n;
	f(i,1,n){
		cin>>u>>v;
		g[u].pb(mp(i,v));
		g[v].pb(mp(i,u));
	}
	dfs(1,0);
	cout<<ans[1];
}