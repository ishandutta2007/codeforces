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
const int N=2e5+5,mod=998244353,bs=450;
#define inf 0x3f3f3f3f
int n,m,x[N],y[N],pre[N][bs],sum[N],tim[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n,m);
    rep(i,1,n) sc(x[i],y[i]);
    int ans=0;
    rep(i,1,m)
    {
        ans+=sum[i];
        for(int j=1;j<bs;j++)
        {
            if(i-j>=0) pre[i][j]+=pre[i-j][j];
            ans+=pre[i][j];
        }
        int op,id;sc(op,id);
        if(op==1)
        {
            if(x[id]+y[id]>=bs)
            {
                for(int j=i+x[id];j<=m;j+=x[id]+y[id]) sum[j]++;
                for(int j=i+x[id]+y[id];j<=m;j+=x[id]+y[id]) sum[j]--;
            }
            else
            {
                if(i+x[id]<=m) pre[i+x[id]][x[id]+y[id]]++;
                if(i+x[id]+y[id]<=m) pre[i+x[id]+y[id]][x[id]+y[id]]--;
            }
            tim[id]=i;
        }
        else
        {
            tim[id]=(i-tim[id])/(x[id]+y[id])*(x[id]+y[id])+tim[id];
            int len=i-tim[id];
            if(len>=x[id]) ans--;
            if(x[id]+y[id]>=bs)
            {
                for(int j=tim[id]+x[id];j<=m;j+=x[id]+y[id]) sum[j]--;
                for(int j=tim[id]+x[id]+y[id];j<=m;j+=x[id]+y[id]) sum[j]++;
            }
            else
            {
                if(tim[id]+x[id]<=m) pre[tim[id]+x[id]][x[id]+y[id]]--;
                if(tim[id]+x[id]+y[id]<=m) pre[tim[id]+x[id]+y[id]][x[id]+y[id]]++;
            }
        }
        out(ans);
    }
}