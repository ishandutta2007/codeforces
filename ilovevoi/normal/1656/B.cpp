#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)

const ll maxn=5e5+100;
const ll base=3e18;
const ll mod=998244353 ;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// you are fucking stupid
/// goal 1/8

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
    ll t;
    cin>> t;
    while (t--)
    {
        map<ll,ll> mp;
        ll n, k ;
        cin>> n>> k;
        bool chk=false;
        for (int i=1;i<=n;i++)
        {
            ll x;
            cin>> x;
            if (mp.count(x-k)||mp.count(k+x))
            {chk=true;
            }
            mp[x]=true;
        }
        if (chk) cout <<"YES"<<endl;
        else cout <<"NO"<<endl;

    }
}