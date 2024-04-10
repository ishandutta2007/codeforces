#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>n>>l>>r;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll x=l-a[i],y=r-a[i];
            ans+=upper_bound(a,a+n,y)-lower_bound(a,a+n,x);
           if(a[i]>=x && a[i]<=y)ans--;
        }
        cout<<(ans/2)<<endl;

    }
    return 0;
}