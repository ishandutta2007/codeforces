#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009];
int main()
{
    ios::sync_with_stdio(0);
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll d=0,w=0,ans=0;
        for(int i=0;i<n;i++)
        {
            d++;
            w=max(w,a[i]);
          if(d>=w){ans++;d=0;w=0;}

        }
        cout<<ans<<endl;
    }
    return 0;
}