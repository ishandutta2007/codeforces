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

const ll maxn=3e5+100;
const ll mod=1e9+7;
const ll base=1e18;

/// you will be the best but now you just are trash
/// goal 3/7


ll a[maxn];
ll b[maxn];
map<ll,ll> mp;
bool dd[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("DELCHAR.inp", "r"))
    {
        freopen("DELCHAR.inp", "r", stdin);
        freopen("DELCHAR.out", "w", stdout);
    }
    ll t;
    cin>> t;
    while (t--)
    {
        ll n;
        cin>> n;
        for (int i=1; i<=n; i++)
        {
            cin>> a[i];
            dd[i]=false;
            mp[a[i]]++;
        }
        bool chk=true;
        for (auto to:mp)
        {
            if (to.ss%2==1)
                chk=false;
        }
        mp.clear();
        if (chk)
        {
            vector<pll> res;
            vector<ll> vt;
            ll cnt=0;
            ll lenpre=n;
          //  cout <<n<<endl;
            for (int i=1; i<=n/2; i++)
            {
               // cout <<i<<" wtf"<<endl;
                ll j=2;
                while (a[j]!=a[1])
                    j++;
                ll len=j-2;
                for (int t=2; t<j; t++)
                {
                    res.pb(make_pair(j+cnt+t-2,a[t]));
                }
                vt.pb(len*2+2);
                cnt+=(len*2+2);
                len=0;
                for (int i=j-1; i>=2; i--)
                {
                    len++;
                    b[len]=a[i];
                }
                for (int h=j+1; h<=lenpre; h++)
                    len++,b[len]=a[h];
             //   cout <<len<<" wtf"<<endl;
                swap(lenpre,len);
                for (int t=1; t<=lenpre; t++)
                    swap(a[t],b[t]);
              //  cout <<lenpre<<endl;
               // F(i,1,lenpre) cout <<a[i]<<" ";
               // cout <<endl;

            }
            cout <<res.size()<<endl;
            for (auto p:res)
            {
                cout <<p.ff<<" "<<p.ss<<endl;
            }
            cout <<vt.size()<<endl;
            for (auto to:vt)
                cout <<to<<" ";
            cout <<endl;
        }
        else
        {
            cout <<-1<<endl;
        }
    }
}