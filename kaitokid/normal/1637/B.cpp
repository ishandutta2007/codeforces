#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll ans=0;
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            ans+=(i+1)*(n-i);
            if(x==0)ans+=(i+1)*(n-i);

        }
       cout<<ans<<endl;
    }
    return 0;
}