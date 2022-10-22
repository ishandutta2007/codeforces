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
//#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=5e3+10;
const ll mod=998244353;
const ll base=2e9+10000;

/// you will be the best but now you just are trash
/// goal 3/7

ll ask(ll x,ll y,ll z)
{
    cout <<"? "<<x<<" "<<y<<" "<<z<<endl;
    ll ans;
    cin>> ans;
    return ans;
}
ll ask(vector<ll> vt)
{
    return ask(vt[0],vt[1],vt[2]);
}
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
    //4 4 4 0 7 1
    ll t;
    cin>> t;
    while (t--)
    {
        vector<ll> cnt(10,0);
        ll n;
        cin>> n;
        pll mx;
        ll mid;
        for(int i=1;i<=4;i++)
        {
            vector<ll> vt;
            for (int j=1;j<=4;j++)
            {
                if (i==j) continue;
                vt.pb(j);
            }
            ll nw=ask(vt);
           for (int j=1;j<=4;j++)
            {
                if (i==j) continue;
                cnt[j]+=nw;
            }
        }
        vector<pll> vt;
        for (int j=1;j<=4;j++)
        {
            vt.pb(make_pair(cnt[j],j));
        }
        sort(vt.begin(),vt.end());
        mx.ff=vt[3].ss;
        mx.ss=vt[2].ss;
        mid=vt[1].ss;
        ll valnw=ask(mid,mx.ff,mx.ss);
        for (int i=5;i<=n;i++)
        {
            ll val=ask(mx.ff,mid,i);
            ll val1=ask(mx.ss,mid,i);
            if (max(val,val1)>valnw)
            {
                valnw=max(val,val1);
                if (val>val1)
                {
                    mx.ss=i;
                }
                else
                {
                    mx.ff=i;
                }
            }
        }
        cout <<"! "<<mx.ff<<" "<<mx.ss<<endl;
    }
}