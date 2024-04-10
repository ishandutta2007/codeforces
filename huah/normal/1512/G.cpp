#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
#define inf 0x3f3f3f3f
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e7+5,mod=998244353;
ll ans[N];
int res[N];
vector<int>prim;
bitset<N>vis;
void sol(int cas)
{
  ans[1]=1;
  for(int i=2;i<=10000000;i++)
  {
    if(!vis[i]) prim.push_back(i),ans[i]=i+1;
    for(int x:prim)
    {
      if(i*x>10000000) break;
      vis[i*x]=true;
      if(i%x==0)
      {
        int y=i,z=x;
        while(y%x==0) y/=x,z*=x;
        for(ll t=1;t<=z;t*=x)
          ans[i*x]+=ans[y]*t;
        break;
      }
      ans[i*x]=ans[i]*(x+1);
    }
  }
  nep(i,10000000,1)
    if(ans[i]<=10000000) res[ans[i]]=i;
  int t;sc(t);
  while(t--)
  {
    int c;sc(c);
    if(!res[c]) out(-1);
    else out(res[c]);
  }
}
int main()
{
  // freopen("1.in", "r",stdin);
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