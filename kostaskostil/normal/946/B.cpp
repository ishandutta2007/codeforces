#include <bits/stdc++.h>
#define int long long

using namespace std;

const int nmax=100100;


main()
{
    //freopen(" .in","r",stdin);
    //freopen(" .out","w",stdout);
    long long n,m,a,b,c;
    cin>>a>>b;
    while ((a!=0) and (b!=0))
    {
        if (a>=2*b)
        {
            a=a%(2*b);
        }
        else if (b>=2*a)
        {
            b=b%(2*a);
        }
        else
        {
            cout<<a<<" "<<b<<"\n";
            exit(0);
        }
    }
    cout<<a<<" "<<b<<"\n";
            exit(0);
    return 0;
}