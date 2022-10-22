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

const ll maxn=1e6+100;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 4/7

ll n;
ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("shortestpath.inp", "r"))
    {
        freopen("shortestpath.inp", "r", stdin);
        freopen("shortestpath.out", "w", stdout);
    }
    ll t;
    cin>> t;
    while (t--)
    {
        ll n;
        cin>> n;
        vector<ll> vt;
        F(i,1,n) if (i!=3) vt.pb(i);
        for (int i=1;i<=n;i++)
        {
            if (i==3) continue;
            for (int j=0;j<i-1;j++) cout <<vt[j]<<" ";
            cout <<3<<" ";
            for (int j=i-1;j<vt.size();j++) cout <<vt[j]<<" ";
            cout <<endl;
        }
        cout <<3<<" ";
        for (int i=n;i>=1;i--) if (i!=3) cout <<i<<" ";
        cout <<endl;
    }
}