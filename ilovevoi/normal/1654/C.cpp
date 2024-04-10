#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)
const ll maxn=3e5+10;
const ll base=3e18;
const ll mod=1e9+7;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// you are fucking stupid
/// goal 0/8

ll a[maxn];
ll dem;
map<ll,ll> mp;
void dosth(ll w)
{
    if (mp.count(w)&&mp[w])
    {
        mp[w]--;
    }
    else
    {
        if (!dem) return ;
        dem--;
        dosth(w/2);
        dosth(w-(w/2));
    }
}
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
        ll n;
        cin>> n;
        dem=n-1;
        ll nw=0;
        for (int i=1;i<=n;i++)
        {
           ll x;
           cin>> x;
           nw+=x;
           mp[x]++;
        }
        dosth(nw);
        bool chk=true;
        for (auto to:mp)
        {
            if (to.ss!=0) chk=false;
        }
        if (chk) cout <<"YES"<<endl;
        else cout<<"NO"<<endl;
        mp.clear();
    }
}