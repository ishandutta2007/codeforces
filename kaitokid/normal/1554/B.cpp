#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        ll ans=LLONG_MIN;
        for(ll i=max(1LL,n-110);i<=n;i++)
            for(ll j=i+1;j<=n;j++)
                ans=max(ans,i*j-k*(a[i]|a[j]));

    cout<<ans<<endl;

    }
    return 0;
}