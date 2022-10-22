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

const ll maxn=3e5+100;
const ll mod=1e9+7;
const ll base=1e18;

/// you will be the best but now you just are trash
/// goal 3/7


ll a[maxn];
map<ll,ll> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("DELCHAR.inp", "r"))
    {
        freopen("DELCHAR.inp", "r", stdin);
        freopen("DELCHAR.out", "w", stdout);
    }
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
        sort(a+1,a+n+1);
        ll dem=0;
        F(i,1,n)
        {
            if (a[i]%x==0&&(mp.count(a[i]/x))&&mp[a[i]/x])
            {
                mp[a[i]/x]--;
                dem--;
            }
            else
            {
                mp[a[i]]++;
                dem++;
            }
        }
        cout <<dem<<endl;
        mp.clear();
    }
}