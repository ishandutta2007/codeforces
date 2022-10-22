#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)

const ll maxn=1e5+10;
const ll base=400;
const ll mod=998244353;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// you are fucking stupid
/// goal 0/8

ll n;
ll a[maxn];
int cnt[maxn*(base+10)];
vector<pair<int,int>> adj[2*maxn];
int par[maxn];

int find_par(ll u)
{
    if (par[u]<0) return u;
    return par[u]=find_par(par[u]);
}
void dsu(ll x,ll y)
{
   x=find_par(x);
   y=find_par(y);
   if (x==y) return ;
   if (par[x]>par[y]) swap(x,y);
   par[x]+=par[y];
   par[y]=x;
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
    cin>> n;
    for (int i=1; i<=n; i++)
    {
        cin>> a[i];
    }
  //  n=1e5;
    int ans=0;
    for (ll p=-base; p<=base; p++)
    {
        bool chknw=(p==-1);
        ll h=1e9;
        for (ll i=1; i<=n; i++)
        {
            ll nw=a[i]-p*i;
            h=min(h,nw);
        }
        for (int i=1; i<=n; i++)
        {
            ll nw=(a[i]-p*i);
            cnt[nw-h]++;
            ans=max(ans,cnt[nw-h]);
        }
        for (int i=1; i<=n; i++)
        {
            ll nw=(a[i]-p*i);
            cnt[nw-h]=0;
            //  ans=max(ans,cnt[nw-h]);
        }
    }
    //cout <<ans<<endl;
    for (int i=1; i<=n; i++)
    {
        ll r=(i+base-1);
        r=min(r,n);
        for (int j=i+1; j<=r; j++)
        {
            ll nw=(a[j]-a[i]);
            ll kc=j-i;
            if (((ll)abs(nw))%(kc)==0)
            {
                ll h=(nw)/kc;
                if (h<-base||h>base)
                {
                    h+=maxn;
                    adj[h].pb(make_pair(i,j));
                  //  cout <<i<<" "<<j<<" "<<h-maxn<<endl;
                }
            }
        }
    }
    for (int i=0;i<2*maxn;i++)
    {
        if (adj[i].size())
        {
            for (auto p:adj[i])
            {
                par[p.ff]=-1;
                par[p.ss]=-1;
            }
            for (auto p:adj[i])
            {
                dsu(p.ff,p.ss);
                ans=max(ans,-par[find_par(p.ff)]);
            }
        }
    }
    cout <<n-ans<<endl;
}