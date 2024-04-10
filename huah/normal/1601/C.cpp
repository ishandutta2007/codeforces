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
const int N=4e6+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,m,a[N],b[N],c[N],hs[N];
int pre[N],bk[N],p[N];
int bit[N];
void add(int x,int v)
{
    while(x<=n+m) bit[x]+=v,x+=x&-x;
}
int query(int x)
{
    int ans=0;
    while(x) ans+=bit[x],x-=x&-x;
    return ans;
}
void sol(int l1,int r1,int l2,int r2)
{
    if(l1>r1) return;
    int m=(l1+r1)/2;
    pre[l2-1]=0;
    for(int i=l2;i<=r2;i++)
    {
        pre[i]=pre[i-1];
        if(i>1&&a[i-1]>b[m]) pre[i]++;
    }
    bk[r2+1]=0;
    for(int i=r2;i>=l2;i--)
    {
        bk[i]=bk[i+1];
        if(i<=n&&a[i]<b[m]) bk[i]++;
    }
    p[m]=l2;
    for(int i=l2+1;i<=r2;i++)
        if(pre[i]+bk[i]<pre[p[m]]+bk[p[m]]) p[m]=i;
    sol(l1,m-1,l2,p[m]);
    sol(m+1,r1,p[m],r2);
}
int main()
{
    // freopen("1.in","r",stdin);
    int t;sc(t);
    while(t--)
    {
        sc(n,m);
        rep(i,1,n) sc(a[i]),hs[i]=a[i];
        rep(i,1,m) sc(b[i]),hs[i+n]=b[i];
        sort(hs+1,hs+1+n+m);
        rep(i,1,n) a[i]=lower_bound(hs+1,hs+1+n+m,a[i])-hs;
        rep(i,1,m) b[i]=lower_bound(hs+1,hs+1+n+m,b[i])-hs;
        sort(b+1,b+1+m);
        sol(1,m,1,n+1);
        int tot=0,j=1;
        for(int i=1;i<=n;i++)
        {
            while(j<=m&&p[j]<=i) c[++tot]=b[j++];
            c[++tot]=a[i];
        }
        while(j<=m) c[++tot]=b[j++];
        ll ans=0;
        for(int i=tot;i>=1;i--)
        {
            ans+=query(c[i]-1);
            add(c[i],1);
        }
        rep(i,1,tot) add(c[i],-1);
        out(ans);
    }
}