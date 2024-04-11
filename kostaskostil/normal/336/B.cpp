#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define fi first
#define se second

using namespace std;

main()
{
    int m;
    long double s, r, r2;
    s=0.0;
    cin>>m>>r;
    r2=r*sqrt(2);
    for (int i=2; i<m; i++)
        s+=2*(m-i)*(2*r*(i-1)+2*r2);
    cout<<fixed<<setprecision(10)<<(s+2*m*r+2*(m-1)*(2*r+r2))/m/m<<"\n";
}