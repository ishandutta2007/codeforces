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
const ll mod=998244353 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7


bool dd[maxn];

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
    ll t;
    cin>> t;
    while (t--)
    {
        ll n;
        cin>> n;
        n--;
        vector<ll> vt;
        for (int i=30;i>=0;i--)
        {
            if (n&(1ll<<i))
            {
                for (int j=0;j<=n;j++)
                {
                    if (j>=(1ll<<i)||(j+(1ll<<i)<=n))
                    {

                    }
                    else
                    {
                        vt.pb(j);
                    }
                }
                for (int j=(1ll<<i);j<=n;j++)
                {
                    if (j%2==1) vt.pb(j),vt.pb(j-(1ll<<i));
                    else vt.pb(j-(1ll<<i)),vt.pb(j);
                }
                break;
            }
        }
        for (auto to:vt) cout <<to<<" ";
        cout <<endl;
    }
}