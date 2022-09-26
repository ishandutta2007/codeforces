#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define fi first
#define se second
#define dist d
#define add disadd
using namespace std;

int n;

main()
{
    int a, b, c, x, y, z;
    cin>>x>>y>>z>>a>>b>>c;
    a-=x;
    if (a<0)
        cout<<"NO\n";
    else
    {
        y-=a;
        b-=y;
        if (b<0)
            cout<<"NO\n";
        else
        {
            z-=b;
            c-=z;
            if (c<0)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
}