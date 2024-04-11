#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int check(int k)
{
    int q=n;
    int s=0;
    while (q>0)
    {
        int t=min(k,q);
        q-=t;
        s+=t;
        q-=(q/10);
    }
    if (2*s>=n)
        return 1;
    else
        return 0;
}

main()
{
    cin>>n;
    int l=0;
    int r=n;
    while (r-l>1)
    {
        int m=(r+l)/2;
        if (check(m)==1)
            r=m;
        else
            l=m;
    }
    cout<<r<<"\n";
    return 0;
}