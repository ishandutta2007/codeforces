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

const ll maxn=3e5+30;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 3/7



pair<ll,ll> a[maxn];

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
        ll n, m;
        cin>> n>> m;
        set<pll> st;
        for (int i=1;i<=m;i++)
        {
            cin>> a[i].ff>> a[i].ss;
            st.insert(make_pair(a[i].ss,i));
        }
        vector<pll> vt;
        n*=2;
        ll ans=0;
        while (n--)
        {
            auto it=(*st.begin());
            ll id=it.ss;
            st.erase(it);
            vt.pb(make_pair(a[id].ff,id));
            ans+=(a[id].ss);
        }
        sort(vt.begin(),vt.end());
        cout<<ans<<endl;
        for (int i=0;i<vt.size()/2;i++)
        {
            cout <<vt[i].ss<<" "<<vt[(ll)vt.size()-i-1].ss<<endl;
        }
    }
}