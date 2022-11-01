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
const int N=4e4+5;
int n,k,a[N];
ll dp[2][N],t[N<<2],lz[N<<2];
void build(int l,int r,int k,int u)
{
    lz[k]=0;
    if(l==r)
    {
        t[k]=dp[u][l];
        return;
    }
    int m=l+r>>1;
    build(l,m,k<<1,u);build(m+1,r,k<<1|1,u);
    t[k]=min(t[k<<1],t[k<<1|1]);
}
void update(int l,int r,int k)
{
    t[k]+=lz[k];
    if(l!=r) lz[k<<1]+=lz[k],lz[k<<1|1]+=lz[k];
    lz[k]=0;
}
void fix(int l,int r,int k,int x,int y,ll v)
{
    if(lz[k]) update(l,r,k);
    if(r<x||l>y) return;
    if(l>=x&&r<=y)
    {
        lz[k]=v;update(l,r,k);
        return;
    }
    int m=l+r>>1;
    fix(l,m,k<<1,x,y,v);fix(m+1,r,k<<1|1,x,y,v);
    t[k]=min(t[k<<1],t[k<<1|1]);
}
ll query(int l,int r,int k,int x,int y)
{
    if(lz[k]) update(l,r,k);
    if(r<x||l>y) return inf;
    if(l>=x&&r<=y) return t[k];
    int m=l+r>>1;
    return min(query(l,m,k<<1,x,y),query(m+1,r,k<<1|1,x,y));
}
int pre[N];
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n,k);rep(i,1,n) sc(a[i]);
    memset(dp,inf,sizeof(dp));
    int u=0;
    dp[u][0]=0;
    while(k--)
    {
        memset(pre,0,sizeof(pre));
        build(0,n,1,u);
        for(int i=1;i<=n;i++)
        {
            if(pre[a[i]])
                fix(0,n,1,0,pre[a[i]]-1,-pre[a[i]]+i);
            pre[a[i]]=i;
            dp[u^1][i]=min(dp[u^1][i],query(0,n,1,0,i-1));
        }
        memset(dp[u],inf,sizeof(dp[u]));
        u^=1;
    }
    out(dp[u][n]);

}