#include <bits/stdc++.h>
#define int long long
using namespace std;

long long gcd(long long a, long long b)
{
    while ((a>0) and (b>0))
    {
        if (a>b)
            a%=b;
        else
            b%=a;
    }
    return max(a,b);
}

main()
{
    int ax, ay, bx, by, n, cx, cy;
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    if ((bx<ax) and (ax<cx))
    {
        cout<<"NO\n";
        exit(0);
    }
    if ((bx>ax) and (ax>cx))
        {
        cout<<"NO\n";
        exit(0);
    }
    if ((by>ay) and (ay>cy))
    {
        cout<<"NO\n";
        exit(0);
    }
    if ((by<ay) and (ay<cy))
        {
        cout<<"NO\n";
        exit(0);
    }
    cout<<"YES\n";
    exit(0);

}