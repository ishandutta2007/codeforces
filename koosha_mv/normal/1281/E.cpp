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
ll n,t,x,y;
ll ans1,ans2,dp[N],w;
vector<pair<ll,ll> > g[N];
void dfs(ll x,ll par,ll lp){
	dp[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i].F!=par){
			dfs(g[x][i].F,x,g[x][i].S);
			dp[x]+=dp[g[x][i].F];
		}
	}
	if(x!=1){
		ans1+=(dp[x]%2)*lp;
		ans2+=1ll*min(dp[x],n*2-dp[x])*1ll*lp;
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		f(i,1,n*2+1) g[i].clear();
		ans1=0,ans2=0;
		f(i,1,2*n){
			Get(x,y);get(w);
			g[x].pb(mp(y,w));
			g[y].pb(mp(x,w));
		}
		dfs(1,0,0);
		cout<<ans1<<" "<<ans2<<endl;
	}
}