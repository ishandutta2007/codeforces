#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define fi first
#define se second
#define dist d
#define add disadd
#define pb push_back

#define int long long
using namespace std;

int cnt=0;

bool ifmore(int q)
{
    cnt++;
    cout<<"> "<<q<<"\n";
    fflush(stdout);
    int t;
    cin>>t;
    return t;
}

int ans(int q)
{
    cout<<"? "<<q<<"\n";
    fflush(stdout);
    int t;
    cin>>t;
    return t;
}

main()
{
    srand(time(0));

    int n;
    cin>>n;
    int l, r;

    l=0;
    r=1e9+1;
    while (r-l>1)
    {
        int m=(r+l)/2;
        if (ifmore(m))
            l=m;
        else
            r=m;
    }
    int x=l+1;
    int g=0;
    for (int i=cnt+1; i<=60; i++)
        g=__gcd(g, x-ans( ((rand()<<16)+rand())%n +1 ));
    cout<<"! "<<x-g*(n-1)<<" "<<g<<"\n";
    fflush(stdout);
}