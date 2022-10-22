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
ll mx[maxn];
ll h[maxn];

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
    for (int t=0;t<maxn;t++) mx[t]=-base;
    ll t;
    cin>> t;
    while (t--)
    {
        ll n, x;
        cin>> n>> x;
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
        }
        F(i,1,n)
        {
            ll cnt=0;
            F(j,i,n)
            {
                cnt+=a[j];
                mx[j-i+1]=max(mx[j-i+1],cnt);

            }
        }
        F(i,0,n) h[i]=mx[i];
        for (int i=n-1;i>=0;i--)
        {
            mx[i]=max(mx[i],mx[i+1]);
        }
        ll pre=0;
        for (int i=0;i<=n;i++)
        {
            cout <<max(pre,mx[i]+i*x)<<" ";
            pre=max(pre,h[i]+i*x);
            h[i]=-base;
            mx[i]=-base;
        }
        cout <<endl;
    }
}