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
const ll mod=1000003 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7
ll a[maxn];
ll b[maxn];
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
    while(t--)
    {
        ll n;
        cin>> n;
        vector<ll> vt;
        for (int i=1;i<=n;i++)
        {
           cin>> a[i];
        }
        for (int i=1;i<=n;i++) cin>> b[i];
        ll mx=0;
        ll mx1=0;
        for (int i=1;i<=n;i++)
        {
           if (a[i]>b[i]) swap(a[i],b[i]);
           mx=max(mx,a[i]);
           mx1=max(mx1,b[i]);
        }

        cout <<mx*mx1<<endl;

    }
}