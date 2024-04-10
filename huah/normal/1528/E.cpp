#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
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
const int N=1e6+5,mod=998244353;
int n;
ll f[N],sum[N],g[N],inv[25];
int main()
{
    inv[1]=1;
    rep(i,2,20) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    sc(n);
    f[0]=1;
    f[1]=2;
    sum[0]=1;
    sum[1]=3;
    rep(i,2,n)
    {
        f[i]=(f[i-1]+f[i-1]+f[i-1]*(f[i-1]-1)%mod*inv[2]%mod+f[i-1]*sum[i-2]%mod)%mod;
        sum[i]=(sum[i-1]+f[i])%mod;
    }
    ll ans=f[n];
    ans=(ans+f[n-1]*sum[n-2]%mod*2+f[n-1]*(f[n-1]-1)%mod)%mod;
    ans=(ans+f[n-1])%mod;
    ans=(ans+f[n-1]*(f[n-1]-1)%mod*(f[n-1]-2)%mod*inv[6]%mod);
    ans=(ans+f[n-1]*(f[n-1]-1)%mod*sum[n-2]%mod*inv[2]%mod)%mod;
    ans=(ans+f[n-1]*sum[n-2]%mod*(sum[n-2]-1)%mod*inv[2]%mod)%mod;
    ans=(ans*2-1)%mod;
    nep(i,n,1) f[i]=(f[i]+mod-f[i-1])%mod;
    rep(i,1,n) g[i]=(g[i-1]+f[i])%mod;
    rep(i,1,n-1)
        ans=(ans+f[i]*g[n-i-1])%mod;
    ans=(ans+mod)%mod;
    out(ans);
}