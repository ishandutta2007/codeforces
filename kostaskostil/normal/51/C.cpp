#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define fi first
#define se second
#define EPS 0.0000000000000001
using namespace std;

set<double> a;
int b[202000];
double l1, l2, l3;

int check(double d)
{
    double r1, r2, r3;
    r1=*a.begin();
    r1+=d+EPS;
    if (a.upper_bound(r1+d)==a.end())
    {
        l1=r1;
        l2=0;
        l3=0;
        return 1;
    }
    r2=*a.upper_bound(r1+d);
    r2+=d+EPS;
    if (a.upper_bound(r2+d)==a.end())
    {
        l1=r1;
        l2=r2;
        l3=0;
        return 1;
    }
    r3=*a.upper_bound(r2+d);
    r3+=d+EPS;
    if (a.upper_bound(r3+d)==a.end())
    {
        l1=r1;
        l2=r2;
        l3=r3;
        return 1;
    }
    else
        return 0;
}

main()
{
    int n;
    int x;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>x, b[i]=x, a.insert(x);
    if (n<=3)
    {
        cout<<0<<"\n";
        for (int i=1; i<=3; i++)
            cout<<fixed<<setprecision(6)<<1.0*b[i]<<" ";
        exit(0);
    }
    double l, r;
    l=0.0;
    r=1000000000.0;
    for (int i=1; i<=10000; i++)
    {
        double m=(l+r)/2;
        if (check(m))
            r=m;
        else
            l=m;
    }
    cout<<fixed<<setprecision(6)<<l<<"\n"<<l1<<" "<<l2<<" "<<l3<<"\n";

}