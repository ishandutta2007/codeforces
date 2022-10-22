#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
const ll mod=1e9+7;
ll dp[5010][5010];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll n,k;
ll solve(ll a,ll b){
    if(dp[a][b]!=-1)return dp[a][b];
    if(a>n)return dp[a][b]=0;
    if(b==k)return dp[a][b]=po(2,n-a);
    return dp[a][b]=((n-a)*solve(a+1,b+1)+a*solve(a,b+1))%mod;
}
int main(){
    scanf("%lld%lld",&n,&k);
    memset(dp,-1,sizeof(dp));
    printf("%lld",solve(0,0));
}