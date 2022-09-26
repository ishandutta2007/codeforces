#include <bits/stdc++.h>
#define int long long

using namespace std;

const int nmax=100100;


main()
{
    //freopen(" .in","r",stdin);
    //freopen(" .out","w",stdout);
    long long n,m,a,b,c;
    long long ans=0;
     cin>>n;
     for (int i=1; i<=n; i++)
     {
         cin>>m;
         ans+=abs(m);
     }
     cout<<ans<<"\n";
    return 0;
}