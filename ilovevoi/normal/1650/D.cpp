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
ll b[maxn];

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
        ll n;
        cin>> n;
        for (int i=1; i<=n; i++)
        {
            cin>> a[i];
        }
        vector<ll> vt;
        for (int i=n; i>=1; i--)
        {
            if (a[i]==i)
            {
                vt.pb(0);
                continue;
            }
            for (int t=1; t<=n; t++)
            {
                if (a[t]==i)
                {
                    for (int j=1; j<=n; j++)
                    {
                        b[j]=a[j];
                    }
                    vt.pb(t);
                    for (int h=1; h<=i; h++)
                    {
                        ll nxt=h-t;
                        if (nxt<=0)
                            nxt+=i;
                        b[nxt]=a[h];
                    }
                    for (int h=1; h<=i; h++)
                    {
                        a[h]=b[h];
                    }
                    break;
                }
            }
        }
        reverse(vt.begin(),vt.end());
        for (auto to:vt) cout <<to<<" ";
        cout <<endl;
    }
}