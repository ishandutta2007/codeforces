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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e6+5;
int n,a[N];
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]);
  sort(a+1,a+1+n);
  int s=n/2-1,ans=1;
  for(int i=1;i+n/2-1<=n;i++)
  {
    vector<int>vc;
    for(int j=i+1;j<=n;j++) vc.push_back(a[j]-a[i]);
    int j=0;
    while(j<vc.size()&&vc[j]==0) j++;
    if(j>=s)
    {
      out(-1);
      return;
    }
    int t=s-j;
    for(int h=j;h<vc.size();h++)
    {
      for(int xx=1;xx*xx<=vc[h];xx++)
      if(vc[h]%xx==0)
      {
        {
          int x=xx;
          int sum=0;
          for(int g=h;g<vc.size();g++)
            if(vc[g]%x==0) sum++;
          if(sum>=t) ans=max(ans,x);
        }
        {
          int x=vc[h]/xx;
          int sum=0;
          for(int g=h;g<vc.size();g++)
            if(vc[g]%x==0) sum++;
          if(sum>=t) ans=max(ans,x);
        }
      }
    }
  }
  out(ans);
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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