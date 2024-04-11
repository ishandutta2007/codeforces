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
    int t, a, b;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cin>>a>>b;
        if (a!=(b+1))
        {
            cout<<"NO\n";
        }
        else
        {
            int q=0;
            int l=a+b;
            for (int i=2; i*i<=l; i++)
                if (l%i==0)
            {
                q=1;
                break;
            }
            if (q==1)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
}