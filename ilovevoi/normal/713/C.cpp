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

const ll maxn=7e5+30;
const ll mod=1e9+7;
const ll base=2e9;

/// you will be the best but now you just are trash
/// goal 3/7

ll n;
ll a[maxn];

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
    ll n;
    cin>> n;
    priority_queue<ll> q;
    ll ans=0;
    ll t=0;
    while (n--)
    {
        t++;
        ll x;
        cin>> x;
        x-=t;
        q.push(x);
        if (q.top()>x)
        {
            ans+=(q.top()-x);
            q.pop();
            q.push(x);
        }
    }
    cout <<ans;
}