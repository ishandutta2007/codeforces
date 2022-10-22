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
vector<ll> adj[maxn];
void dfs(ll u,ll par,ll pre)
{
    a[u]=adj[u].size();
    a[u]*=(-pre);
    for (auto to:adj[u])
    {
        if (to==par) continue;
        dfs(to,u,-pre);
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
       for (int i=1;i<=n-1;i++)
       {
           ll x, y;
           cin>>x>> y;
           adj[x].pb(y);
           adj[y].pb(x);
       }
       for (int i=1;i<=n;i++)
       {
           if (adj[i].size()==1)
           {
               a[i]=1;
               dfs(adj[i][0],i,1);
               break;
           }
       }
       for (int i=1;i<=n;i++)
       {
           cout <<a[i]<<" ";
           adj[i].clear();
       }
       cout <<endl;
    }
}