#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
#define pi 3.141592653589793238

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    double R;
    cin>>n>>R;
    double t=sin(pi/n);
    cout<<fixed<<setprecision(10)<<t*R/(1-t)<<"\n";

    /// r/(r+R)==tan(a)
    /// r=t*(r+R)
    /// r=t*R/(1-t)
    return 0;
}