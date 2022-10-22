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
const ll mod=998244353;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// you are fucking stupid
/// goal 0/8

ll p[maxn];
vector<pair<ll,pll>> adj[maxn];
ll cntnw=1;
ll val[maxn];
ll mx[maxn];
ll cnt[maxn];

ll mu(ll a,ll n)
{
    if (n==0) return 1;
    ll t=mu(a,n/2);
    if (n%2==0) return (t*t)%mod;
    else return ((t*t)%mod*a)%mod;
}
void add(ll u,ll diff)
{
    while (u!=1)
    {
        ll h=p[u];
        ll cnt1=0;
        while (u%h==0)
        {
            u/=h,cnt1++;
            cnt[h]+=diff;
            mx[h]=min(mx[h],cnt[h]);
        }
        cnt1=(cnt1*diff)+(mod-1);
        cnt1=(cnt1)%(mod-1);
        cntnw=(cntnw*mu(h,cnt1))%mod;
    }
}
void dfs(ll u,ll par)
{
    val[u]=cntnw;
    for (auto p:adj[u])
    {
        ll to=p.ff;
        ll a=p.ss.ff;
        ll b=p.ss.ss;
        if (to==par)
            continue;
       add(a,1);
       add(b,-1);
        dfs(to,u);
        add(b,1);
        add(a,-1);

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
    for (int i=2; i<maxn; i++)
    {
        if (p[i]) continue;
        for (int j=i; j<maxn; j+=i)
        {
            p[j]=i;
        }
    }
    ll t;
    cin>> t;
    while (t--)
    {
        ll n;
        cin>> n;
        for (int i=1; i<=n-1; i++)
        {
            ll x, y, a, b;
            cin>> x>> y>> a>> b;
            adj[x].pb(make_pair(y,make_pair(b,a)));
            adj[y].pb(make_pair(x,make_pair(a,b)));
        }
        dfs(1,0);
        for (int i=1;i<=n;i++)
        {
          //  cout <<val[i]<<" wtf"<<endl;
            adj[i].clear();
            val[1]=(val[1]*mu(i,-mx[i]))%mod;
            mx[i]=0;
            cnt[i]=0;
        }
       // cout <<val[1]<<endl;

        ll ans=0;
        for (int i=2;i<=n;i++) val[i]=(val[i]*val[1])%mod;
        for (int i=1;i<=n;i++) ans=(ans+val[i])%mod;
        cout <<ans<<endl;
        cntnw=1;
    }
}