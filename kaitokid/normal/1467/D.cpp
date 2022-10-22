#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll dp[5009][5009],h[5009];
ll n,a[5009],k,q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
        dp[0][i]=1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
    {
        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {cin>>a[i];
        h[i]+=dp[k][i];
        for(int j=1;j<=k;j++)
        { ll r=(dp[j-1][i-1]+dp[j-1][i+1])*dp[k-j][i];
        r%=mod;
            h[i]=(h[i]+r)%mod;
        }

    ans+=(a[i]*h[i])%mod;
    }
    while(q--)
    {
        ll x, y;
        cin>>x>>y;
        ans-=((a[x]*h[x])%mod);
        if(ans<0)ans+=mod;
        a[x]=y;
        ans+=((a[x]*h[x])%mod);
        ans%=mod;
        cout<<ans<<endl;
    }

      return 0;
}