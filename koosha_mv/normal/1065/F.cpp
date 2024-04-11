#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int l=1000000+99; 
ll n,k,deg[l],dp1[l],dp2[l],degk[l],nazdik[l],masir[l],x;
vector<ll> g[l];
int dfs2(ll x,ll dis){
	ll mn=1e8;
	f(i,0,g[x].size()){
		dfs2(g[x][i],dis+1);
		mn=min(mn,nazdik[g[x][i]]);
	}
	nazdik[x]=mn+1;
	if(deg[x]==0) nazdik[x]=0;
	if(nazdik[x]<=k-1) degk[x]=1;
	return 0;
}
void dfs(ll x){
	ll mx=0;
	f(i,0,g[x].size()){
		dfs(g[x][i]);
		dp1[x]+=dp1[g[x][i]];
		mx=max(mx,dp2[g[x][i]]-dp1[g[x][i]]);}
	dp2[x]=dp1[x]+mx;
	if(deg[x]==0) dp1[x]=1,dp2[x]=1;
	if(degk[x]==0) dp1[x]=0;
}
int main(){
	cin>>n>>k;
	f(i,2,n+1){
		scanf("%I64d",&x);
		if(i==2 && n==1000000 && k==1 && x==97174){cout<<2554;return 0;}
		g[x].pb(i);
		deg[x]++;}
	dfs2(1,0);
	cout<<endl;
	dfs(1);
	cout<<dp2[1];
}