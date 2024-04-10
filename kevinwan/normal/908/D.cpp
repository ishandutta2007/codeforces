#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
inline ll p(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
inline ll inv(ll x){
    return p(x,mod-2);
}
const int mn=1e3+10;
ll dp[mn][mn],sum[mn][mn];
ll pr;
int main()
{
    ll k,pa,pb;
    cin>>k>>pa>>pb;
    int i,j;
    dp[0][0]=dp[0][1]=1;
    pr=pa*inv(pa+pb)%mod;
    for(i=2;i<=k;i++)dp[0][i]=pr*dp[0][i-1]%mod;
    for(i=1;i<k;i++){
        for(j=1;j<=k;j++){
            if(i>=j)dp[i][j]=dp[i-j][j]*(1-pr);
            dp[i][j]+=dp[i][j-1]*pr;
            dp[i][j]%=mod;
        }
    }
    ll ans=0;
    for(i=0;i<k;i++){
        for(j=k-i;j<k;j++){
            ans+=dp[i][j]*(1-pr)%mod*(i+j);
            ans%=mod;
        }
        ans+=inv(1-pr)*dp[i][j]+(i+j-1)*dp[i][j];
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}