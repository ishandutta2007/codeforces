#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[299];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll g[2]={0,0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            g[(i%2)]=__gcd(g[(i%2)],a[i]);
        }
       bool bl=true;
       for(int i=1;i<n;i+=2)
           if(a[i]%g[0]==0){bl=false;break;}
      if(bl){cout<<g[0]<<endl;continue;}
      bl=true;
       for(int i=0;i<n;i+=2)
           if(a[i]%g[1]==0){bl=false;break;}
      if(bl){cout<<g[1]<<endl;continue;}
      cout<<0<<endl;


    }
    return 0;
}