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
        string s;
        cin>> s;
        map<ll,ll> mp;
        bool chk=true;
        for (auto to:s)
        {
            if (to<='Z')
            {
                if (!mp[to-'A'+1])
                {
                    chk=false;
                }

            }
            else
            {
                 mp[to-'a'+1]=1;

            }
        }
        if (chk) cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }
}