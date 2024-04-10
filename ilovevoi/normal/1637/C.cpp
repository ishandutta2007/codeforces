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
const ll mod=1e9+7;
const ll base=1e18;

/// you will be the best but now you just are trash
/// goal 3/7

ll a[maxn];
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
        ll n;
        cin>> n;
        ll dem=0;
        priority_queue<ll> q;
        ll sl=0;
        ll all=0;
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
            if (i==1||i==n) continue;
            all+=(a[i]);
            if (a[i]>=2) dem=-1;
            sl+=(a[i]%2);
        }
        if ((dem==0&&sl)||(n==3&&a[2]%2==1))
        {
            cout <<-1<<endl;
            continue;
        }
        ll ans=(sl+all)/2;

        cout <<ans<<endl;
    }
}