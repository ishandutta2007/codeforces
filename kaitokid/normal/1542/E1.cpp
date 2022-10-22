#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[59][2509],pr[59][2509];
ll pp[2509];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,mod;
    cin>>n>>mod;
    dp[0][0]=1;
    for(ll q=0;q<=n*n;q++)pr[0][q]=(dp[0][q]+pr[0][q-1])%mod;
    for(ll i=1;i<=n;i++)
    {
        for(ll q=0;q<=n*n;q++)pp[q]=0;
        for(ll j=1;j<=i;j++)
        {
            for(ll q=0;q<=n*n;q++)
            {
                pp[q+j-1]+=dp[i-1][q];
                pp[q+j-1]%=mod;
            }

        }
       for(ll q=0;q<=n*n;q++)dp[i][q]=pp[q];
    for(ll q=0;q<=n*n;q++)pr[i][q]=(dp[i][q]+pr[i][q-1])%mod;
    }

    ll ans=0;
    ll x=1;
    for(ll i=n;i>0;i--)
    {
        ll res=0;
        for(ll u=1;u<i;u++)
        {   ll g=0;
            for(ll q=u+1;q<=n*n;q++)
           {
            g+=(dp[i-1][q]*pr[i-1][q-u-1])%mod;
            g%=mod;}
        g*=(i-u);
        g%=mod;
        res=(res+g)%mod;
        }
       res*=x;
       res%=mod;
       ans=(ans+res)%mod;
       x*=i;
       x%=mod;
    }
    cout<<ans<<endl;
    return 0;
}