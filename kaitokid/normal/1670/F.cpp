#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n,z;
ll c[1009][1009];
ll dp[64][2009],sum;
ll go(ll x,ll num)
{
    if(x==-1)return 1;
    if(dp[x][num]!=-1)return dp[x][num];
    int u=(((1LL<<x)&z)!=0);
    dp[x][num]=0;
    for(ll i=u;i<=min(num,n);i+=2)
    {
        ll r=2*(num-i);
        if(x>0 && (sum&(1LL<<(x-1))))r++;
        r=min(r,2*n);
        dp[x][num]+=c[n][i]*go(x-1,r);
        dp[x][num]%=mod;
    }
    return dp[x][num];


    }
    ll cal(ll x)
    {
        if(x<z)return 0;

        memset(dp,-1,sizeof dp);
        sum=x;
        for(ll i=62;i>=0;i--)
            if(sum&(1LL<<i))return go(i,1);
    }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    c[0][0]=1;
    for(int i=1;i<=1004;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    ll l,r;
    cin>>n>>l>>r>>z;

    cout<<(cal(r)-cal(l-1)+mod)%mod;

    return 0;
}