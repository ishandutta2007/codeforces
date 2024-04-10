#pragma GCC optimize(2)
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
void iary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void iary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=405,mod=998244353;
#define inf 0x3f3f3f3f
char s[N][N],a[N][N];
int n,m,x[N],y[N],pre[N],bk[N];
int process()
{
    pre[1]=y[1];
    bk[m]=y[m];
    rep(i,2,m) pre[i]=min(pre[i-1]+x[i],y[i]);
    nep(i,m-1,1) bk[i]=min(bk[i+1]+x[i],y[i]);
    int ans=20;
    rep(i,2,m-2)
        ans=min(ans,x[i]+x[i+1]+pre[i-1]+bk[i+2]);
    return ans;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,m);
        rep(i,1,n) sc(s[i]+1);
        rep(i,1,n)
            rep(j,1,m)
            a[i][j]=s[i][j]-'0';
        int ans=20;
        rep(i,2,n-3)
        {
            rep(j,1,m)
            {
                x[j]=(a[i-1][j]^1)+a[i][j]+a[i+1][j]+a[i+2][j]+(a[i+3][j]^1);
                y[j]=(a[i][j]^1)+(a[i+1][j]^1)+(a[i+2][j]^1);
            }
            ans=min(ans,process());
            rep(j,i+3,n-1)
            {
                rep(k,1,m)
                {
                    x[k]=x[k]-(a[j][k]^1)+a[j][k]+(a[j+1][k]^1);
                    y[k]=y[k]+(a[j][k]^1);
                }
                ans=min(ans,process());
            }
        }
        out(ans);
    }
}