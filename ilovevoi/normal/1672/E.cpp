#include<bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define ff first
#define ss second
//#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)

const ll maxn=4e6+3000;
const ll base=3e18;
const ll mod= 1e9+7 ;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll n;
ll cnt=0;
ll ask(ll x)
{
    cnt++;
    if (cnt>n+30)
    {
        assert(0);
    }
    cout <<"? "<<x<<endl;
    ll res;
    cin>> res;
    return res;
}
vector<ll> adj[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp","r"))
    {
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    cin>> n;
    ll l=1,h=5e6;
    while (l<=h)
    {
        ll mid=(l+h)/2;
        if (ask(mid)==1)
            h=mid-1;
        else
            l=mid+1;
    }
    ll ans=l;
    for (ll t=2;t<=n;t++)
    {
        ll p=(l/t);
        ll h=ask(p);
       if (h) ans=min(ans,h*p);
    }
    cout <<"! "<<ans<<endl;
}