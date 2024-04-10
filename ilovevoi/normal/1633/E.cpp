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

const ll maxn=63;
const ll mod=1e9+7 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7
struct tk
{
    ll par[maxn];
    tk()
    {
        for (int i=1; i<maxn; i++)
            par[i]=-1;
    }
    ll find_par(ll u)
    {
        if (par[u]<0)
            return u;
        return par[u]=find_par(par[u]);
    }
    bool dsu(ll x,ll y)
    {
        x=find_par(x);
        y=find_par(y);
        if (x==y)
            return false;
        if (par[x]>par[y])
            swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }
    ll q(ll x,ll y)
    {
        if (find_par(x)!=find_par(y))
            return true;
        return false;
    }
    bool chk(ll n)
    {
        if ((-par[find_par(1)])==n)
            return true;
        return false;
    }
};
tk gr[320][320];
ll dp[53][53][53];
ll dp1[320][53];
vector<ll> vt1;
ll n, m;
ll get(ll val)
{
   auto p=upper_bound(vt1.begin(),vt1.end(),val)-vt1.begin()-1;
   ll ans=base;
   for (ll t=0;t<=n-1;t++)
   {
       ll slnw=(2*t-(n-1));
       ans=min(ans,slnw*val+dp1[p][t]);
   }
   return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    cin>> n>> m;
    vector<pair<ll,pll>> vt;
    for (int i=1; i<=m; i++)
    {
        ll x, y, w;
        cin>> x>> y>> w;
        vt.pb(make_pair(w,make_pair(x,y)));
    }
    vt.pb(make_pair(base,make_pair(1,1)));
    sort(vt.begin(),vt.end());
    for (int i=0; i<vt.size(); i++)
    {
        for (int j=i; j<vt.size(); j++)
        {
            for (int t=i; t<=j; t++)
            {
                gr[i][j].dsu(vt[t].ss.ff,vt[t].ss.ss);
            }
        }
    }
    for (int i=0;i<320;i++)
    {
        for (int j=0;j<=n;j++)
        {
            dp1[i][j]=base;
        }
    }
    vt1.pb(0);
    for (ll i=0; i<vt.size(); i++)
    {
        if (i==0||(vt[i].ff!=vt[i-1].ff))
        {
            vt1.pb(vt[i].ff);
            vector<ll> lf;
            vector<ll> rt;
            tk nw;
            for (ll j=i-1; j>=0; j--)
            {
                if (nw.dsu(vt[j].ss.ff,vt[j].ss.ss))
                    lf.pb(j);
            }
            tk nw1;
            for (ll j=i; j<vt.size(); j++)
            {
                if (nw1.dsu(vt[j].ss.ff,vt[j].ss.ss))
                    rt.pb(j);
            }
            for (int t=0; t<=lf.size(); t++)
            {
                for (int t1=0; t1<=rt.size(); t1++)
                {
                    for (int p=0; p<=lf.size(); p++)
                    {
                        dp[t][t1][p]=base;
                    }
                }
            }
            dp[0][0][0]=0;
            for (int t=0; t<=lf.size(); t++)
            {
                for (int t1=0; t1<=rt.size(); t1++)
                {
                    for (int p=0; p<=lf.size(); p++)
                    {
                        if (dp[t][t1][p]==base)
                            continue;
                        ll l=i;
                        if (t)
                            l=lf[t-1];
                        ll r=i-1;
                        if (t1)
                            r=rt[t1-1];
                        if (l<=r&&gr[l][r].chk(n))
                        {
                            dp1[vt1.size()-2][p]=min(dp1[vt1.size()-2][p],dp[t][t1][p]);
                        }
                        if (t+1<=lf.size())
                        {
                            ll h=0;
                            ll idnxt=lf[t];
                            if (l>r||gr[l][r].q(vt[idnxt].ss.ff,vt[idnxt].ss.ss))
                                h=1;
                            dp[t+1][t1][p+h]=min(dp[t+1][t1][p+h],dp[t][t1][p]-h*vt[idnxt].ff);
                        }
                        if (t1+1<=rt.size())
                        {
                            ll h=0;
                            ll idnxt=rt[t1];
                            if (l>r||gr[l][r].q(vt[idnxt].ss.ff,vt[idnxt].ss.ss))
                                h=1;
                            dp[t][t1+1][p]=min(dp[t][t1+1][p],dp[t][t1][p]+h*vt[idnxt].ff);
                        }
                    }
                }
            }
        }
    }
    ll p, k, a, b, c;
    cin>> p>> k>> a>> b>> c;
    ll pre;
    ll ans=0;
    for (int i=1; i<=p; i++)
    {
        ll x;
        cin>> x;
        pre=x;
        ans=(ans^get(x));
    }
    for (int i=p+1;i<=k;i++)
    {
        pre=(pre*a+b)%c;
        ans=(ans^get(pre));
    }
    cout <<ans;
}