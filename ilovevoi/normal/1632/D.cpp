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

const ll maxn=2e5+100;
const ll mod=1e9+7 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7

ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll n;
    cin>> n;
    for (int i=1;i<=n;i++)
    {
        cin>> a[i];
    }
    vector<pll> vt;
    ll ans=0;
    ll pre=-1;
    for (int i=1;i<=n;i++)
    {
        vector<pll> vt1;
        pll nw=make_pair(a[i],i);
        for (int i=0;i<vt.size();i++)
        {
            if (vt[i].ff%nw.ff==0)
            {
                nw.ss=vt[i].ss;
            }
            else
            {
                vt1.pb(nw);
                nw.ff=__gcd(vt[i].ff,nw.ff);
                nw.ss=vt[i].ss;
            }
        }
        vt1.pb(nw);
        swap(vt,vt1);
        ll pos=i;
        for (int i=0;i<vt.size();i++)
        {
            ll l=vt[i].ss;
            ll r=pos;
            if (i) r=vt[i-1].ss-1;
            ll posnw=pos-vt[i].ff+1;
            if (posnw>=l&&posnw<=r)
            {
                if (posnw>pre)
                {
                    pre=pos;
                    ans++;
                    break;
                }
            }
        }
        cout <<ans<<" ";
    }
}