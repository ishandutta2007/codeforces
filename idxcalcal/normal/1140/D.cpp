#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
ll dp[1005][1005],n,w[1005];
inline int min(int a,int b){return a<b?a:b;}
int dfs(int l,int r){
	if(dp[l][r])return dp[l][r];
	if(r-l==2)return dp[l][r]=w[l]*w[l+1]*w[l+2];
	ll ans=1e18;
	ans=min(ans,w[l]*w[l+1]*w[r]+dfs(l+1,r));
	ans=min(ans,w[l]*w[r-1]*w[r]+dfs(l,r-1));
	for(int i=l+2;i<=r-2;++i)ans=min(ans,w[l]*w[i]*w[r]+dfs(l,i)+dfs(i,r));
	return dp[l][r]=ans;
}
signed main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)w[i]=w[i+n]=i;
	ll ans=1e18;
	for(int i=1;i<=n;++i)ans=min(ans,dfs(i,i+n-1));
	cout<<ans;
	return 0;
}