#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
const ll mod=998244353;
vector<int>g[mn];
ll dp[mn][3];
void dfs(int x,int p){
	dp[x][0]=dp[x][1]=dp[x][2]=1;
	for(int y:g[x])if(y!=p){
		dfs(y,x);
		dp[x][0]*=2*(dp[y][0]+dp[y][1]+dp[y][2])%mod+dp[y][2];
		dp[x][1]*=(2*dp[y][0]+dp[y][1]+dp[y][2])%mod+dp[y][2];
		dp[x][2]*=dp[y][0]+dp[y][1]+dp[y][2];
		dp[x][0]%=mod,dp[x][1]%=mod,dp[x][2]%=mod;
	}
	dp[x][0]-=dp[x][2],dp[x][1]-=dp[x][2];
	dp[x][0]%=mod,dp[x][1]%=mod;
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)cerr<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<'\n';
    ll ans=0;
	ans=(dp[1][0]+dp[1][1]+dp[1][2]-1)%mod;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
}