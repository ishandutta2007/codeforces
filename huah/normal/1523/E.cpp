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
const int N=2e5+5,mod=1e9+7;
int n,k;
ll f[N],invf[N];
ll C(int n,int m)
{
    return f[n]*invf[m]%mod*invf[n-m]%mod;
}
int main()
{
    f[0]=f[1]=invf[0]=invf[1]=1;
    rep(i,2,N-1) f[i]=f[i-1]*i%mod,invf[i]=(mod-mod/i)*invf[mod%i]%mod;
    rep(i,2,N-1) invf[i]=invf[i-1]*invf[i]%mod;
    int t;sc(t);
    while(t--)
    {
        sc(n,k);
        ll ans=0;
        rep(i,1,n)
        {
            int s=n-i-(i-1)*(k-1);
            if(s>=0)
                ans=(ans+1ll*f[i]%mod*invf[n]%mod*f[n-i]%mod*C(s+i,i)%mod)%mod;
            else break;
        }
        ans=(ans+1+mod)%mod;
        out(ans);
    }
}