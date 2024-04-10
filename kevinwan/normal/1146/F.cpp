#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
const ll mod=998244353;
vector<int> g[mn];
ll dp[mn][2];
ll inv(ll x){
    ll ans=1;
    for(ll i=mod-2;i;i>>=1,x=x*x%mod)if(i&1)ans=ans*x%mod;
    return ans;
}
void dfs(int x){
    ll p1=1,p2=1;
    for(int y:g[x]){
        dfs(y);
        p1=p1*(dp[y][0]+dp[y][1])%mod;
        p2=p2*(dp[y][0])%mod;
    }
    ll s1=0;
    for(int y:g[x]){
        s1+=p2*dp[y][1]%mod*inv(dp[y][0])%mod;
        s1%=mod;
    }
    if(g[x].size()){
        dp[x][0]=(p1-s1)%mod;
        dp[x][1]=(p1-p2)%mod;
    }
    else dp[x][0]=dp[x][1]=1;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        g[x].push_back(i);
    }
    dfs(1);
    if(dp[1][0]<0)dp[1][0]+=mod;
    printf("%lld",dp[1][0]);
}