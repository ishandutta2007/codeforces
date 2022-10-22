/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=3e5+30;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 3/7



ll a[maxn];
pll f[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll t;
    cin>> t;
    while (t--)
    {
        ll n, d;
        cin>> n>> d;
        a[n+1]=d+1;
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
        }
        f[n+1]=make_pair(0,base);
        for (int i=n;i>=1;i--)
        {
            f[i]=f[i+1];
            if (i!=n) f[i].ff=max(f[i].ff,a[i+1]-a[i]-1);
            else f[i].ff=max(f[i].ff,(a[i+1]-a[i]-2)*2+1);
            if (i!=n) f[i].ss=min(f[i].ss,a[i+1]-a[i]-1);
        }
        pll nw=make_pair(0,base);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            pll p=nw;
            p.ff=max(p.ff,f[i+1].ff);
            p.ss=min(p.ss,f[i+1].ss);
          if (i!=n)  p.ff=max(p.ff,a[i+1]-a[i-1]-1);
          else p.ff=max(p.ff,(a[i+1]-a[i-1]-2)*2+1);
          if (i!=n)  p.ss=min(p.ss,a[i+1]-a[i-1]-1);
      //    cout <<i<<" "<<p.ff<<" "<<p.ss<<endl;
            ans=max(ans,min(p.ss,(p.ff-1)/2));
            nw.ff=max(nw.ff,a[i]-a[i-1]-1);
            nw.ss=min(nw.ss,a[i]-a[i-1]-1);
        }
        cout <<ans<<endl;
    }
}