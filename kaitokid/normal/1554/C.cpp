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
        ll n,m;
        cin>>n>>m;
        if(m<n){cout<<0<<endl;continue;}
        m-=n;
        ll ans=0;
        for(int i=30;i>=0;i--)
        {
            if(n&(1<<i))continue;
            if(m>= (1<<i)){m-=(1<<i);ans+=(1<<i);}
        }
        for(int i=0;i<=30;i++)
        {
            if(n&(1<<i)){ans|=(1<<i);continue;}
            if((ans&(1<<i))==0)break;
        }
        cout<<ans+1<<endl;
            }
    return 0;
}