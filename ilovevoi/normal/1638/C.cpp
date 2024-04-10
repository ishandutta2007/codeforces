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

const ll maxn=1e5+30;
const ll mod=998244353;
const ll base=3e18 ;

/// you will be the best but now you just are trash
/// goal 3/7
ll a[maxn];
ll par[maxn];
ll find_par(ll u)
{
    if (u==par[u]) return u;
    return par[u]=find_par(par[u]);
}
void dsu(ll x,ll y)
{
    x=find_par(x);
    y=find_par(y);
    if (x==y) return ;
    par[x]=y;
}
set<ll,greater<ll>> st[4*maxn];
void update(ll id,ll left,ll right,ll x,ll y,ll diff)
{
   if (x>right||y<left) return ;

   if (x<=left&&y>=right)
   {
       st[id].insert(diff);
       return ;
   }
   ll mid=(left+right)/2;
   update(id*2,left,mid,x,y,diff);
   update(id*2+1,mid+1,right,x,y,diff);
}
void get(ll id,ll left,ll right,ll x)
{
    if (x>right||x<left) return ;

    if (st[id].size())
    {
        if (*(st[id].begin())>x)
        {
            ll h=(*st[id].begin());
            while (st[id].size()&&x<(*st[id].begin()))
            {
                ll k=(*st[id].begin());
                dsu(x,k);
              //  cout <<x<<" "<<k<<endl;
                st[id].erase(k);
            }
            st[id].insert(h);
        }
    }
    if (left==right) return ;
    ll mid=(left+right)/2;
    get(id*2,left,mid,x);
    get(id*2+1,mid+1,right,x);
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
    ll t;
    cin>> t;
    while (t--)
    {
        ll n;
        cin>> n;
        F(i,1,n) par[i]=i;
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
            get(1,1,n,a[i]);
            update(1,1,n,1,a[i]-1,a[i]);
        }
        ll ans=0;
        F(i,1,n) if (i==find_par(i)) ans++;
        cout <<ans<<endl;
        for (int i=0;i<=4*n;i++) st[i].clear();
    }
}