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
const int N=25,mod=998244353;
int n,m,vis[N],inv[N];
int a[N][50005];
int c[N<<1][N<<1];
int C(int n,int m)
{
    if(m==0||m==n) return 1;
    if(m==1) return n;
    if(c[n][m]) return c[n][m];
    return c[n][m]=(C(n-1,m-1)+C(n-1,m))%mod;
}
int main()
{
    inv[1]=1;
    rep(i,2,N-1) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    sc(n,m);
    rep(i,1,n)
        rep(j,1,m) sc(a[i][j]);
    int ans=0;
    rep(i,1,m)
    {
        memset(vis,0,sizeof(vis));
        rep(j,1,n) vis[n+1-a[j][i]]++;
        nep(j,n-1,0) vis[j]+=vis[j+1];
        ll p=1;
        for(int j=1;j<=n;j++)
        {
            ans=(ans+1ll*p*vis[j]%mod*inv[n-j+1]%mod)%mod;
            p=1ll*p*(n-j+1-vis[j])%mod*inv[n-j+1]%mod;
        }
    }
    out(ans);
}