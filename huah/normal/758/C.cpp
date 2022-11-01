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
const int N=3e5+5,mod=998244353;
int n,m,x,y;
ll k,row[N];
void sol(int cas)
{
    sc(n,m);
    ast(n,1,100);
    ast(m,1,100);
    sc(k);
    ast(k,1,1000000000000000000ll);
    sc(x,y);
    ast(x,1,n);
    ast(y,1,m);
    ll g=k%m;
    k/=m;
    int lasrow=0,d=1;
    if(k)
    {
        if(n==1) row[1]=k;
        else
        {
            lasrow=1;
            if(k) k--,row[1]=1,d=1;
            ll t=k/(2*(n-1));
            k%=(2*(n-1));
            row[1]+=t;
            row[n]+=t;
            rep(i,2,n-1) row[i]+=t*2;
            for(int i=2;i<=n;i++)
                if(k) k--,row[i]++,lasrow=i,d=1;
            for(int i=n-1;i>=1;i--)
                if(k) k--,row[i]++,lasrow=i,d=-1;
        }
    }
    lasrow+=d;
    if(lasrow==n+1) lasrow-=2;
    else if(lasrow<1) lasrow+=2;
    assert(lasrow>=1&&lasrow<=n);
    ll mn,mx;
    mn=row[1];
    mx=row[1]+(1==lasrow&&g!=0);
    rep(i,2,n) mn=min(mn,row[i]),mx=max(mx,row[i]+(i==lasrow&&g!=0));
    ll xm=row[x]+(x==lasrow&&g>=y);
    out(mx,mn,xm);
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/