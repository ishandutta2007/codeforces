#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)

const ll maxn=7e5+100;
const ll base=3e18;
const ll mod= 1e9+7 ;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// have medal in APIO
/// goal 2/8

ll a[maxn];

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
        ll n;
        cin>> n;
        ll ans=base;
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
        }
        for (int i=1;i<=n;i++)
        {
            ll pre=0;
            ll res=0;
            for (int j=i+1;j<=n;j++)
            {
                ll h=(pre)/a[j];
                ll nw=(a[j]*(h+1));
                pre=nw;
                res+=(h+1);
            }
            pre=0;
            for (int j=i-1;j>=1;j--)
            {
                ll h=(pre)/a[j];
                ll nw=(a[j]*(h+1));
                pre=nw;
                res+=(h+1);
            }
            ans=min(ans,res);
        }
        cout <<ans<<endl;
}