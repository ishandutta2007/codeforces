#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
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
const int N=2e5+5,mod=998244353;
int n,k,a[N],rk[N];
ll f[N],invf[N];
ll C(int n,int m)
{
    return f[n]*invf[m]%mod*invf[n-m]%mod;
}
ll cal(int x)
{
    ll ans=0;
    for(int i=x;i<=k&&i<=n;i++)
        ans=(ans+C(k,i)*C(n-x,i-x)%mod)%mod;
    return ans;
}
int main()
{
    f[0]=f[1]=invf[0]=invf[1]=1;
    rep(i,2,N-1) f[i]=f[i-1]*i%mod,invf[i]=(mod-mod/i)*invf[mod%i]%mod;
    rep(i,2,N-1) invf[i]=invf[i-1]*invf[i]%mod;
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n,k);
    rep(i,1,n)
    {
        sc(a[i]);
        rk[a[i]]=i;
    }
    int sum=1;
    for(int i=1;i<n;i++)
        if(rk[a[i]+1]>rk[a[i+1]+1])
            sum++;
    out(cal(sum));
}