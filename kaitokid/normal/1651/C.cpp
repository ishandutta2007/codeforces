
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009],b[200009],mn[2][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {

      int n;
      cin>>n;
      for(int i=1;i<=n;i++)cin>>a[i];
      for(int i=1;i<=n;i++)cin>>b[i];
    mn[0][0]=mn[0][1]=mn[1][0]=mn[1][1]=1e9;
    for(int i=1;i<=n;i++)
        {mn[0][0]=min(mn[0][0],abs(a[1]-b[i]));
        mn[0][1]=min(mn[0][1],abs(a[n]-b[i]));
        mn[1][0]=min(mn[1][0],abs(b[1]-a[i]));
        mn[1][1]=min(mn[1][1],abs(b[n]-a[i]));
      //  cout<<mn[0][0]<<" "<<mn[0][1]<<" "<<mn[1][0]<<" "<<mn[1][1]<<endl;

        }
     ll ans=mn[0][0]+mn[0][1]+mn[1][0]+mn[1][1];
    // cout<<mn[0][0]<<" "<<mn[0][1]<<" "<<mn[1][0]<<" "<<mn[1][1]<<" "<<ans<<endl;
     ans=min(ans,abs(a[1]-b[1])+abs(a[n]-b[n]));
     ans=min(ans,abs(a[1]-b[n])+abs(a[n]-b[1]));
     ans=min(ans,abs(a[1]-b[1])+mn[0][1]+mn[1][1]);
     ans=min(ans,abs(a[1]-b[n])+mn[0][1]+mn[1][0]);
     ans=min(ans,abs(a[n]-b[1])+mn[0][0]+mn[1][1]);
     ans=min(ans,abs(a[n]-b[n])+mn[0][0]+mn[1][0]);
     cout<<ans<<endl;

    }
    return 0;
}