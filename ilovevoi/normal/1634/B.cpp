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

const ll maxn=5e3+10;
const ll mod=998244353;
const ll base=2e9+10000;

/// you will be the best but now you just are trash
/// goal 3/7

string s;


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
        ll n, x, y;
        cin>> n>> x>> y;
        ll h=(x%2);
        ll h1=1-h;
        for (int i=1;i<=n;i++)
        {
            ll x;
            cin>> x;
            if (x%2==1)
            {
                h=(h^1);
                h1=(h1^1);
            }
        }
        if (h==y%2)
        {
            cout <<"Alice"<<endl;
        }
        else
        {
            cout <<"Bob"<<endl;
        }
    }
}