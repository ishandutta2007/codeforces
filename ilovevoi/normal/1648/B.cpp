/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll  int
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e6+30;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 3/7

ll f[maxn];


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
        ll n, c;
        cin>> n>> c;
        for (int i=1; i<=n; i++)
        {
            ll x;
            cin>> x;
            f[x]++;
        }
        bool chk=true;
        for (int i=1; i<=c; i++)
        {
            f[i]+=f[i-1];
        }
        for (ll i=1; i<=c; i++)
        {
            if (f[i]==f[i-1])
            {
                for (ll t=1; t<=c/i; t++)
                {
                    if (f[t]!=f[t-1])
                    {
                        ll l=t*i;
                        ll r=min(c,(t)*(i+1)-1);
                        if (f[r]-f[l-1])
                        {
                          //  cout <<i<<" "<<t<<" "<<l<<" "<<r<<endl;
                            chk=false;
                        }
                    }
                }
            }
        }
        if (chk)
            cout <<"YES"<<endl;
        else
            cout <<"NO"<<endl;
        for (int t=1; t<=c; t++)
            f[t]=0;
    }
}