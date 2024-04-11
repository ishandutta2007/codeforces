#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define int long long


main()
{
    int t;
    cin>>t;
    int l, r, d;
    for (int i=0; i<t; i++)
    {
        cin>>l>>r>>d;
        if (l>d)
            cout<<d<<"\n";
        else
            cout<<((r+d)/d)*d<<"\n";
    }



}