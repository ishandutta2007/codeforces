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

const ll maxn=5e2+10;
const ll mod=998244353;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 6/7

ll dp[maxn][maxn][12];
ll dp1[maxn][12];
ll nxt[maxn][12];

ll n, k;
ll siz[maxn];
ll dep[maxn];

ll cntnw=0;
void add(string s,ll val)
{
    ll nw=0;
    for (auto to:s)
    {
        if (!nxt[nw][to-'0'])
        {
            cntnw++;
            nxt[nw][to-'0']=cntnw;
        }
        nw=nxt[nw][to-'0'];
    }
    siz[nw]+=val;
}
void dfs1(ll u)
{
    for (int i=0; i<=9; i++)
    {
        if (nxt[u][i])
        {
            dep[nxt[u][i]]=dep[u]+1;
            dfs1(nxt[u][i]);
            siz[u]+=siz[nxt[u][i]];
        }
    }
}
void dfs(ll u)
{
    for (int i=0; i<=9; i++)
    {
        if (nxt[u][i])
        {
            ll to=nxt[u][i];
      //      cout <<u<<" "<<i<<" "<<nxt[u][i]<<" chk"<<endl;
            dfs(to);
            for (int p=0; p<=dep[u]; p++)
            {
                for (int t=0; t<=k; t++)
                {
                    dp1[p][t]=dp[u][p][t];
                    dp[u][p][t]=0;
                }
            }
            for (int p=0; p<=dep[u]; p++)
            {
                for (int t=0; t<=k; t++)
                {
                    for (int t1=0; t1<=t; t1++)
                    {
                        dp[u][p][t]=max(dp[u][p][t],dp1[p][t-t1]+max(dp[to][p][t1],(t1?dp[to][dep[to]][t1-1]+siz[to]*(dep[to]-p):0)));
                    }
                }
            }
        }
    }
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
    ll n;
    cin>> n>> k ;
    ll sl=0;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>> s;
        ll val;
        cin>> val;
        add(s,val);
        sl+=((ll)(s.length())*val);
    }
    dfs1(0);
    dfs(0);
    ll ans=0;
  //  cout <<siz[0]<<" chk"<<endl;
   // cout <<sl<<endl;
    for (int t=0;t<=k;t++)
    {
        ans=max(ans,dp[0][0][t]);
        //cout <<dp[0][0][t]<<" "<<t<<endl;
    }
    cout <<sl-ans<<endl;
}