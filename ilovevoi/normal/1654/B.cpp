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
      string s;
      cin>> s;
      map<ll,ll> mp;
      string res;
      for (auto to:s)
      {
        mp[to]++;
      }
      bool chk=false;
      for (auto to:s)
      {
          if (chk)
          {
              res.pb(to);
              continue;
          }
          if (mp[to]>=2)
          {
            mp[to]--;
          }
          else
          {
              res.pb(to);
              chk=true;
          }
      }
   //   reverse(res.begin(),res.end());
      cout <<res<<endl;
    }
}