#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
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
const int N=2e6+5,mod=998244353;
int n;
ll f[N],g[N];
int main()
{
    f[1]=g[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        f[i]=(f[i]+2*f[i-1]+2)%mod;
        g[i]=(g[i]+1)%mod;
        for(int j=i+i;j<=1000000;j+=i)
            f[j]=(f[j]+g[i])%mod;
    }
    sc(n);
    ll ans=f[n]-f[n-1];
    ans=(ans+mod)%mod;
    out(ans);
}