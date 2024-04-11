#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
//#define double long double

#define y0 y___0
#define y1 y___1

#define fi first
#define se second
#define pb push_back

#define timer (clock()*1.0/CLOCKS_PER_SEC)
#define e 0.000000000000000001

using namespace std;

int a[1005000];

int bpow(int a, int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    int x=bpow(a, b/2);
    int y=bpow(a, b%2);
    x*=x;
    x%=998244353;
    x*=y;
    x%=998244353;
    return x;
}
main()
{

        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);
    int w, h;
    cin>>w>>h;
    cout<<bpow(2, w+h)<<"\n";
}