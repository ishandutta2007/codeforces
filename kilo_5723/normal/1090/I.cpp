#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
//#define zerol
//#define terminal
#ifdef zerol
#define dbg(x...) do { cout << #x << " -> "; err(x); } while (0)
void err() {
    #ifdef terminal
    cout << "\033[39;0m";
    #endif
    cout << endl;
}
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

int T,n;
LL l,r,a[10000010];
unsigned x,y,z,b[10000010];

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>l>>r>>x>>y>>z>>b[1]>>b[2];
        for (int i=3;i<=n;i++)
            b[i]=b[i-2]*x+b[i-1]*y+z;
        for (int i=1;i<=n;i++)
            a[i]=((LL)b[i])%(r-l+1LL)+l;
        LL Min=a[1],inf=5e18;LL ans=inf;
        for (int i=2;i<=n;i++)
        {
            if (Min<a[i]) ans=min(ans,a[i]*Min);
            Min=min(Min,a[i]);
        }
        LL Max=a[n];
        for (int i=n-1;i>=1;i--)
        {
            if (Max>a[i]) ans=min(ans,a[i]*Max);
            Max=max(Max,a[i]);
        }
        if (ans==inf) puts("IMPOSSIBLE");
        else cout<<ans<<endl;
    }
    return 0;
}