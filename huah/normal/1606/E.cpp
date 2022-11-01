#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=505,mod=998244353,bs=320;
#define inf 0x3f3f3f3f
int n,x,dp[N][N];
bool vis[N][N];
int c[N][N];
ll C(int n,int m)
{
    if(m==0||m==n) return 1;
    if(m==1) return n;
    if(c[n][m]) return c[n][m];
    return c[n][m]=(C(n-1,m-1)+C(n-1,m))%mod;
}
ll qpow(ll a,ll n)
{
    ll ans=1;
    for(;n;n>>=1,a=a*a%mod)
    if(n&1) ans=ans*a%mod;
    return ans;
}
int use[N][N];
ll pp(int x,int y)
{
    if(use[x][y]) return use[x][y];
    return qpow(x,y);
}
ll Dp(int n,int x)
{
    if(n==0) return 1;
    if(vis[n][x]) return dp[n][x];
    vis[n][x]=true;
    if(x<=n-1) return dp[n][x]=qpow(x,n);
    for(int m=0;m<=n;m++)
        if(m!=1)
        dp[n][x]=(dp[n][x]+Dp(m,x-n+1)*pp(n-1,n-m)%mod*C(n,m)%mod)%mod;
    return dp[n][x];
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n,x);
    printf("%lld\n",Dp(n,x));
}