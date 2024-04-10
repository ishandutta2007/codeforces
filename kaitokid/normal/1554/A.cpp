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
        ll n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=1;i<n;i++)ans=max(ans,a[i]*a[i-1]);
        cout<<ans<<endl;


    }
    return 0;
}