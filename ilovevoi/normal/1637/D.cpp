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

const ll maxn=1e2+30;
const ll mod=1e9+7;
const ll base=1e18;

/// you will be the best but now you just are trash
/// goal 3/7

bitset<maxn*maxn> bs[maxn];
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
        ll cnt=0;
        ll ans=0;
        ll s=0;
        F(i,1,n)
        {
            cin>> a[i];
            ans+=(a[i]*a[i]*(n-2));
            s+=a[i];
        }
         F(i,1,n)
        {
            cin>> b[i];
            ans+=(b[i]*b[i]*(n-2));
            s+=b[i];
        }
        if (n==1)
        {
            cout <<0<<endl;
            continue;
        }
        bs[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            bs[i]|=(bs[i-1]<<a[i]);
            bs[i]|=(bs[i-1]<<b[i]);
        }
        ll mx=base;
        for (ll i=0;i<=n*100;i++)
        {
            if (bs[n][i])
            {
                mx=min(mx,i*i+(s-i)*(s-i));
            }
        }
        cout <<ans+mx<<endl;
        F(i,0,n) bs[i].reset();
    }
}