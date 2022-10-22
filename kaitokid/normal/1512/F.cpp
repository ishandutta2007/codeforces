#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,c,a[200009],b[200009];
int main()
{
ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>c;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)cin>>b[i];
    ll ans=LLONG_MAX,d=0,hv=0;
    for(int i=0;i<n;i++)
    {
        ll r=(c+a[i]-1-hv)/a[i];
        r=max(r,0LL);
        ans=min(ans,r+d);
      if(i!=n-1)
      {r=(b[i]+a[i]-1-hv)/a[i];
      r=max(r,0LL);
      hv+=r*a[i];
      hv-=b[i];
      d+=r+1;

      }

    }
cout<<ans<<endl;
    }
    return 0;
}