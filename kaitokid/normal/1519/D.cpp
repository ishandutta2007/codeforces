#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5009],b[5009],dp[5009][5009];
ll go(ll x,ll y)
{
    if(x==y)return 0;
    ll &u=dp[x][y];
    if(u!=-1)return u;
    u=a[x]*b[y]+a[y]*b[x]-a[x]*b[x]-a[y]*b[y];
    if(y==(x+1))
    {
        return u;
    }
    u+=go(x+1,y-1);
    return u;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
ll n;
cin>>n;
ll sum=0;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++){cin>>b[i];sum+=a[i]*b[i];}
ll ans=sum;
memset(dp,-1,sizeof dp);
for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
    ans=max(ans,sum+go(i,j));
    cout<<ans;
    return 0;
}