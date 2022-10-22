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
const ll mod= 998244353;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 4/7

ll n;
ll x[maxn];
ll y[maxn];


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
        ll ans=1;
        ll n, m, k, q;
        cin>>n>> m>> k>> q;
        set<ll> st;
        set<ll> st1;
     //   set<pll> st2;
        for (int i=1;i<=q;i++)
        {
            cin>> x[i]>> y[i];
        }
        for (int i=q;i>=1;i--)
        {
            if (st.size()==n||st1.size()==m||(st.count(x[i])&&st1.count(y[i])))
            {

            }
            else
            {
                st.insert(x[i]);
                st1.insert(y[i]);
           //     st2.insert(make_pair(x[i],y[i]));
                ans=(ans*k)%mod;
            }
        }
        cout <<ans<<endl;
    }
}