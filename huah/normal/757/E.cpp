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
const int N=1000005,mod=1e9+7;
int n,g[N];
bool vis[N];
int tot,p[N];
int dp[N][21],f[N][21];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
ll fac[N],invfac[N];
ll C(int n,int m)
{
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main()
{
    fac[0]=fac[1]=invfac[0]=invfac[1]=1;
    rep(i,2,N-1) fac[i]=fac[i-1]*i%mod,invfac[i]=1ll*(mod-mod/i)*invfac[mod%i]%mod;
    rep(i,2,N-1) invfac[i]=invfac[i-1]*invfac[i]%mod;
    g[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(!vis[i]) p[++tot]=i,g[i]=2;
        for(int j=1;j<=tot&&i*p[j]<=1000000;j++)
        {
            vis[i*p[j]]=true;
            if(i%p[j]==0)
            {
                g[i*p[j]]=g[i];
                break;
            }
            g[i*p[j]]=g[i]*2;
        }
    }
    dp[1][0]=1;
    for(int i=1;i<=1000000;i++)
    {
        for(int k=0;k<20;k++)
        if(dp[i][k])
        {   
            for(int j=i+i;j<=1000000;j+=i)
                add(dp[j][k+1],dp[i][k]);
            for(int j=i;j<=1000000;j+=i)
                add(f[j][k],1ll*g[j/i]*dp[i][k]%mod);
        }
    }
    int q;scanf("%d",&q);
    while(q--)
    {
        int r,n;sc(r,n);
        if(n==1){out(1);continue;}
        ll ans=0;
        for(int j=0;j<=20;j++)
            {
                if(r<j) break;
                ans=(ans+1ll*f[n][j]*C(r,j)%mod)%mod;
            }
        out(ans%mod);
    }
}