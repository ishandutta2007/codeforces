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
const int N=5e5+5,mod=1e9+7;
int n;
ll a[N],b[N];
vector<int>vc[20001];
struct node
{
  ll x;
  int id;
  bool operator<(const node&o)const
  {
    return x<o.x;
  }
}c[N];
int main()
{
  int t;sc(t);
  while(t--)
  {
    sc(n);
    rep(i,1,n) sc(a[i]),b[i]=0;
    // n=rand()%10000+1;
    // rep(i,1,n) b[i]=0;
    // rep(i,1,n)
    // { 
    //   a[i]=10000;
    //   // a[i]=rand()%20001-10000;
    //   // while(a[i]==0)
    //   //   a[i]=rand()%20001-10000;
    // }
    if(n%2==0)
    {
      for(int i=1;i<=n;i+=2)
        b[i]=a[i+1],b[i+1]=-a[i];
    }
    else
    {
      rep(i,1,n) c[i].x=a[i],c[i].id=i;
      sort(c+1,c+1+n);
      int m=0;
      rep(i,1,n)
      {
        c[++m]=c[i];
        while(m>=4&&c[m].x==c[m-1].x)
        {
          b[c[m].id]=1;
          b[c[m-1].id]=-1;
          m-=2;
        }
      }
      assert(m>=3);
      assert(m&1);
      if(c[1].x+c[2].x!=0) swap(c[1],c[3]);
      else if(c[1].x+c[3].x!=0) swap(c[1],c[2]);
      b[c[1].id]=c[2].x+c[3].x;
      b[c[2].id]=b[c[3].id]=-c[1].x;
      for(int i=4;i<=m;i+=2)
        b[c[i].id]=c[i+1].x,b[c[i+1].id]=-c[i].x;
    }
    ll sum=0,ss=0;
    rep(i,1,n) sum+=b[i]*a[i],ss+=abs(b[i]),assert(b[i]!=0);
    assert(sum==0);
    assert(ss<=1000000000);
    rep(i,1,n)printf(i==n?"%d\n":"%d ",b[i]);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/