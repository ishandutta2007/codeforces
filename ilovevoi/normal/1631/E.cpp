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
const ll mod=1000003 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7
ll a[maxn];
ll f[maxn];
ll l[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("test.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll n;
    cin>> n;
    for (int i=1; i<=n; i++)
    {
        cin>> a[i];
        if (!f[a[i]])
            f[a[i]]=i;
        l[a[i]]=i;
        //    par[i]=i;
    }
    vector<pll> vt;
    for (int i=1; i<=n; i++)
    {
        if (f[i]&&f[i]!=l[i])
            vt.pb(make_pair(f[i],l[i]));
    }
    sort(vt.begin(),vt.end());
    vector<pll> vt1;
    ll mx=0;
    for (int i=0; i<vt.size(); i++)
    {
        if (mx<vt[i].ss)
        {
            mx=vt[i].ss;
            vt1.pb(vt[i]);
     //       cout <<vt[i].ff<<" "<<vt[i].ss<<endl;
        }
    }
    swap(vt,vt1);
    ll ans=0;
    for (int i=0; i<vt.size(); i++)
    {
        ll j=i+1;
        while (j<vt.size()&&vt[j].ff<vt[j-1].ss)
            j++;
        j--;
        ll sl=0;
        ll pre=i;
        while (pre<j)
        {
            ll nw=pre+1;
            while (nw<=j&&vt[nw].ff<vt[pre].ss) nw++;
            nw--;
            pre=nw;
            sl++;
        }
        ans=(ans+vt[j].ss-vt[i].ff-1-sl);
        i=j;
    }
    cout<<ans<<endl;
}