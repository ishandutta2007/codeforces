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
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 6/7


ll t[maxn];
ll x[maxn];
ll y[maxn];
bool dd[maxn];
vector<ll> adj[maxn];
vector<ll> adj1[maxn];

vector<ll> vt;
ll col[maxn];
void dfs1(ll u,ll col1)
{
    vt.pb(u);
    col[u]=col1;
    dd[u]=1;
    for (auto to:adj[u])
    {
        if (!dd[to]) dfs1(to,1-col1);
        if (col[u]==col[to])
        {
            cout <<"NO"<<endl;
            exit(0);
        }
    }
}
map<pll,ll> mp;
void add(ll x,ll y)
{
    adj1[y].pb(x);
}
ll colp[maxn];
bool chkall=true;
vector<ll> vt1;
void dfs2(ll u)
{
    colp[u]=1;
    for (auto to:adj1[u])
    {
        if (colp[to]==1)
        {
            chkall=false;
        }
        else if (colp[to]==2)
        {
            continue;
        }
        else
        {
            dfs2(to);
        }
    }
    vt1.pb(u);
    colp[u]=2;
}
ll pos[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("shortestpath.inp", "r"))
    {
        freopen("shortestpath.inp", "r", stdin);
        freopen("shortestpath.out", "w", stdout);
    }
    ll n, m;
    cin>> n>> m;
    for (int i=1;i<=m;i++)
    {
        cin>> t[i]>> x[i]>> y[i];
        adj[x[i]].pb(y[i]);
        adj[y[i]].pb(x[i]);
        mp[make_pair(x[i],y[i])]=t[i];
        mp[make_pair(y[i],x[i])]=t[i];
    }
    ll cntnw=0;
    F(i,1,n)
    {
       if (dd[i]) continue;
       dfs1(i,0);
       for (auto to:vt)
       {
           for (auto h:adj[to])
           {
               if (h<to)
               {
                   ll x=h;
                   ll y=to;
                  // cout <<col[x]<<" "<<col[y]<<x<<" "<<y<<endl;
                   if (col[h]==0)
                   {
                      if (mp[make_pair(h,to)]==1)
                      {
                          add(x,y);
                      }
                      else
                      {
                          add(y,x);
                      }
                   }
                   else
                   {
                       if (mp[make_pair(h,to)]==1)
                      {
                          add(y,x);
                      }
                      else
                      {
                          add(x,y);
                      }
                   }
               }
           }
       }
       chkall=true;
       for (auto to:vt)
       {
           if (!colp[to]) dfs2(to);
       }
       //cout <<"WTF"<<endl;
       if (chkall)
       {
           for (auto to:vt1)
           {
               cntnw++;
               pos[to]=cntnw;
           }
           vt1.clear();
           vt.clear();
           continue;
       }
       vt1.clear();
       for (auto to:vt)
       {
           dd[to]=false;
           colp[to]=0;
           adj1[to].clear();
       }
       vt.clear();
       dfs1(i,1);
       for (auto to:vt)
       {
           for (auto h:adj[to])
           {
               if (h<to)
               {
                   ll x=h;
                   ll y=to;
                   if (col[h]==0)
                   {
                      if (mp[make_pair(h,to)]==1)
                      {
                          add(x,y);
                      }
                      else
                      {
                          add(y,x);
                      }
                   }
                   else
                   {
                       if (mp[make_pair(h,to)]==1)
                      {
                          add(y,x);
                      }
                      else
                      {
                          add(x,y);
                      }
                   }
               }
           }
       }
       chkall=true;
       for (auto to:vt)
       {
           if (!colp[to]) dfs2(to);
       }
       vt.clear();
       if (chkall)
       {
           for (auto to:vt1)
           {
               cntnw++;
               pos[to]=cntnw;
           }
           vt1.clear();
       }
       else
       {
           cout <<"NO"<<endl;
           return 0;
       }
    }
    cout <<"YES"<<endl;
    F(i,1,n)
    {
        if (col[i]==0) cout <<"L "<<pos[i]<<endl;
        else cout <<"R "<<pos[i]<<endl;
    }
}