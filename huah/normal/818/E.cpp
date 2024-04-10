#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=1e5+5,mod=998244353;
int n,p,a[N],t[N<<2];
void build(int l,int r,int k)
{
    if(l==r){t[k]=a[l];return;}
    int m=(l+r)>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
    t[k]=1ll*t[k<<1]*t[k<<1|1]%p;
}
int query(int l,int r,int k,int x,int y)
{
    if(r<x||l>y) return 1;
    if(l>=x&&r<=y) return t[k];
    int m=(l+r)>>1;
    return 1ll*query(l,m,k<<1,x,y)*query(m+1,r,k<<1|1,x,y)%p;
}
void sol(int cas)
{
    sc(n,p);ast(n,1,100000);ast(p,1,1000000000);
    rep(i,1,n) sc(a[i]),ast(a[i],1,1000000000),a[i]%=p;
    build(1,n,1);
    ll ans=0;
    rep(i,1,n)
    {
        if(a[i]==0)
        {
            ans+=n-i+1;
            continue;
        }
        int j=i;
        for(int t=1<<16;t;t>>=1)
            if(j+t<=n&&query(1,n,1,i,j+t)!=0) j+=t;
        ans+=n-j;
    }
    out(ans);
}
int main() 
{
    // freopen("1.in", "r",stdin);
    // freopen("2.out", "w", stdout);
    srand(time(0));
    int t=1,cas=0;
    // scanf("%d",&t);
    while(t--)
    {
        sol(++cas);
    }
}