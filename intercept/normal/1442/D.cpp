#include<bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
const int M=3009;
int n,k;
int t[M];
vector<ll>s[M];
ll solve(int l,int r,ll *f){
	ll dp[M],g[M];
	for(int i=0;i<=k;++i)dp[i]=f[i];
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;++i){
		for(int j=0;j<=k;++j)g[j]=dp[j];
		for(int j=k;j>=1;--j){
			if(j>=t[i])g[j]=max(g[j],dp[j-t[i]]+s[i][t[i]]);
			if(j<t[i])g[k]=max(g[k],dp[k-j]+s[i][j]);
		}
		for(int j=0;j<=k;++j)dp[j]=g[j];
	}
	
	if(l==r)return dp[k];
	ll ans=solve(mid+1,r,dp);
	for(int i=0;i<=k;++i)dp[i]=f[i];
	for(int i=mid+1;i<=r;++i){
		for(int j=0;j<=k;++j)g[j]=dp[j];
		for(int j=k;j>=1;--j){
			if(j>=t[i])g[j]=max(g[j],dp[j-t[i]]+s[i][t[i]]);
			if(j<t[i])g[k]=max(g[k],dp[k-j]+s[i][j]);
		}
		for(int j=0;j<=k;++j)dp[j]=g[j];
	}
	ans=max(ans,solve(l,mid,dp));
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&t[i]);
		s[i].pb(0);
		for(int j=1,x;j<=t[i];++j){
			scanf("%d",&x);
			s[i].pb(x);
			s[i][j]+=s[i][j-1];
		}
	}
	ll f[M];
	for(int i=0;i<=k;++i)f[i]=0;
	printf("%lld",solve(1,n,f));
	return 0;
}