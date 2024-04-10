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

const ll maxn=1e5+100;
//const ll mod=1e9+7;
const ll base=1e6+317;

/// you will be the best but now you just are trash
/// goal 3/7



vector<pll> vt;
ll mod[2];
ll val[maxn*50];
ll cntnw=0;
ll n, m;
ll a[maxn][5];
ll w[maxn];
ll id[maxn];
vector<ll> adj[maxn];
void add(ll x,ll diff)
{
    for (auto to:adj[x])
        val[to]+=diff;
}

bool lf(ll a,ll b)
{
    return w[a]<w[b];
}
ll dosth()
{
    while (1)
    {
        ll h=5e8;
        ll x=abs((ll)rnd())%h+h;
        for (ll i=2; i*i<=x; i++)
        {
            if (x%i==0)
            {
                x=-1;
                break;
            }
        }
        if (x!=-1)
            return x;
    }
}
map<ll,ll> mp;
ll get(ll x)
{
    ll h=mp.size();
    if (mp.count(x))
        return mp[x];
    else
        return mp[x]=h+1;
}
ll get2(ll x)
{
    return x*(x-1)/2;
}
ll getsl(ll x)
{
    ll cntnw=0;
    for (int i=0; i<adj[x].size(); i++)
    {
        ll nw=i+1;
        ll h=__builtin_popcount(nw);
        if (h%2==1)
            cntnw+=val[adj[x][i]];
        else
            cntnw-=val[adj[x][i]];
    }
    return  cntnw;
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
    mod[0]=dosth();
    mod[1]=dosth();
    //cout <<mod<<endl;
    cin>> n>> m;
    for (int i=1; i<=n; i++)
    {
        id[i]=i;
        for (int j=0; j<m; j++)
        {
            cin>> a[i][j];
        }
        sort(a[i],a[i]+m);
        for (int j=0; j<m; j++)
        {
            a[i][j]=get(a[i][j]);
        }

        for (int t=1; t<(1ll<<m); t++)
        {
            pll p;
            for (int k=0; k<=1; k++)
            {

                ll nw=0;
                for (int h=0; h<m; h++)
                {
                    if (t&(1ll<<h))
                    {
                        nw=(nw*base+a[i][h])%mod[k];
                    }
                }
                if (k==0)
                    p.ff=nw;
                else
                    p.ss=nw;
            }
            vt.pb(p);
        }

        cin>> w[i];
    }
    sort(vt.begin(),vt.end());
    vt.resize(unique(vt.begin(),vt.end())-vt.begin());
     for (int i=1; i<=n; i++)
    {
        for (int t=1; t<(1ll<<m); t++)
        {
            pll p;
            for (int k=0; k<=1; k++)
            {

                ll nw=0;
                for (int h=0; h<m; h++)
                {
                    if (t&(1ll<<h))
                    {
                        nw=(nw*base+a[i][h])%mod[k];
                    }
                }
                if (k==0)
                    p.ff=nw;
                else
                    p.ss=nw;
            }
            ll h=lower_bound(vt.begin(),vt.end(),p)-vt.begin();
            adj[i].pb(h);
        }
    }
    //  cout <<mod<<endl;
    sort(id+1,id+n+1,lf);
    ll j=n;
    ll ans=3e18;
    for (int i=1; i<=n; i++)
        add(id[i],1);
    for (int i=1; i<=n; i++)
    {
        ll idnw=id[i];
        if (i>=2)
            add(id[i-1],-1);
        if (i>=j)
            break;
        while (j>i&&((j-i+1)-getsl(id[i]))>0)
        {
            /*  if (j==i)
              {
                  cout <<"WTF"<<" "<<i<<" "<<j<<endl;
                  return 0;
              }
              else
              {
                  cout<<
              }*/
            ans=min(ans,w[id[i]]+w[id[j]]);
            add(id[j],-1);
            j--;
        }
    }
    if (ans==3e18)
        ans=-1;
    cout <<ans;
}