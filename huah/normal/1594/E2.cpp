#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=505,mod=1e9+7;
ll qpow(ll a,ll n)
{
    ll ans=1;
    for(;n;n>>=1,a=a*a%mod)
        if(n&1) ans=ans*a%mod;
    return ans;
}
vector<pair<ll,ll>>vc;
map<ll,bool>vis;
map<ll,int>color;
int k,n;
vector<ll> dfs(ll u)
{
    vector<ll>dp(3);
    if(color.count(u)) dp[color[u]]=1;
    else dp[0]=dp[1]=dp[2]=1;
    if(vis.count(u*2))
    {
        vector<ll>gp=dfs(u*2);
        dp[0]=dp[0]*(gp[1]+gp[2])%mod;
        dp[1]=dp[1]*(gp[0]+gp[2])%mod;
        dp[2]=dp[2]*(gp[0]+gp[1])%mod;
    }
    if(vis.count(u*2+1))
    {
        vector<ll>gp=dfs(u*2+1);
        dp[0]=dp[0]*(gp[1]+gp[2])%mod;
        dp[1]=dp[1]*(gp[0]+gp[2])%mod;
        dp[2]=dp[2]*(gp[0]+gp[1])%mod;
    }
    return dp;
}
ll cal()
{
    for(auto x:vc)
    {
        ll u=x.first;
        color[u]=x.second;
        while(u&&!vis[u])
        {
            vis[u]=true;
            u/=2;
        }
    }
    ll ans=1;
    rep(i,1,k) ans=ans*2%(mod-1);
    ans=(ans-vis.size()-1+mod-1)%(mod-1);
    ll res=qpow(2,ans);
    vector<ll>dp=dfs(1);
    return res*(dp[0]+dp[1]+dp[2])%mod;
}
void sol(int cas)
{
    sc(k);
    ll ans=1;
    rep(i,1,k) ans=ans*2%(mod-1);
    ans=(ans-1+mod-1)%(mod-1);
    sc(n);
    ans=(ans-n+mod-1)%(mod-1);
    ll res=qpow(2,ans);
    rep(i,1,n)
    {
        ll x,y;string c;
        cin>>x>>c;
        if(c=="white"||c=="yellow") y=0;
        else if(c=="green"||c=="blue") y=1;
        else y=2;
        vc.push_back({x,y});
    }
    res=res*cal()%mod;
    out(res);
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  while(t--)
  {    
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/