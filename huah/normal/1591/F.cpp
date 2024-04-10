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
const int N=5e5+5,mod=998244353;
int n,a[N];
int top,s[N],l[N],r[N];
int f[2][2][N],g[2][2][N];
void add(int l,int r,int x,int p1,int p2)
{
    if(p1%2==0&&l%2) l++;
    if(p1%2&&r%2==0) r--;
    if(l>r) return;
    l>>=1;r>>=1;
    f[p1][p2][l]=(f[p1][p2][l]+x)%mod;
    f[p1][p2][r+1]=(mod-x+f[p1][p2][r+1])%mod;
}
ll getsum(int l,int r,int p1,int p2)
{
    if(p1%2==0&&l%2) l++;
    if(p1%2&&r%2==0) r--;
    if(l>r) return 0;
    l>>=1;r>>=1;
    return (g[p1][p2][r]+mod-(l?g[p1][p2][l-1]:0))%mod;
}
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n);
    rep(i,1,n) sc(a[i]);
    rep(i,1,n)
    {
        while(top&&a[s[top]]>a[i]) top--;
        l[i]=s[top]+1;
        s[++top]=i;
    }
    top=0;s[top]=n+1;
    nep(i,n,1)
    {
        while(top&&a[s[top]]>=a[i]) top--;
        r[i]=s[top]-1;
        s[++top]=i;
    }
    add(0,0,1,0,0);
    g[0][0][0]=f[0][0][0];
    rep(i,1,n)
    {
        for(int x=0;x<=1;x++)
            for(int y=0;y<=1;y++)
            for(int z=0;z<=1;z++)
            add(i,r[i],getsum(l[i]-1,i-1,x,y)*a[i]%mod,z,y^x^z^1);
        if(i>>1)
        {
            f[i&1][0][i>>1]=(f[i&1][0][i>>1]+f[i&1][0][(i>>1)-1])%mod;
            f[i&1][1][i>>1]=(f[i&1][1][i>>1]+f[i&1][1][(i>>1)-1])%mod;
            g[i&1][0][i>>1]=(f[i&1][0][i>>1]+g[i&1][0][(i>>1)-1])%mod;
            g[i&1][1][i>>1]=(f[i&1][1][i>>1]+g[i&1][1][(i>>1)-1])%mod;
        }
        else
        {
            g[i&1][0][i>>1]=f[i&1][0][i>>1];
            g[i&1][1][i>>1]=f[i&1][1][i>>1];
        }
    }
    int ans=f[n&1][0][n>>1]-f[n&1][1][n>>1];
    ans=(ans%mod+mod)%mod;
    out(ans);
}