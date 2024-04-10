#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[109];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     int t;
     cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
       ll mn=1e9;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
           mn=min(mn,a[i]);
       }
       ll ans=0;
       for(int i=0;i<n;i++)
       {
           if((a[i]%(2*mn-1))==0){ans+=a[i]/(2*mn-1)-1;continue;}
           if(a[i]<=(2*mn-1))continue;
           ll d=(a[i])/(2*mn-1);
     
           ans+=d;

       }
       cout<<ans<<endl;
    }

    return 0;
}