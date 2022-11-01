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
using namespace std;
const int N =105;
int n,a[N][N];
map<int,int>vis;
void sol(int cas)
{
  sc(n);
  if(n==1) out(1);
  else if(n==2) out(-1);
  else if(n==3)
  {
    out(2,9,7);
    out(4,6,3);
    out(1,8,5);
  }
  else
  {
    vector<int>v1,v2;
    for(int i=1;i<=n*n;i++) if(i&1) v1.push_back(i);
    else v2.push_back(i);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      {
        int x;
        if(v1.size()) x=v1.back(),v1.pop_back();
        else x=v2.back(),v2.pop_back();
        a[i][j]=x;
        printf(j==n?"%d\n":"%d ",x);
      }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      {
        if(i+1<=n) assert(abs(a[i][j]-a[i+1][j])!=1);
        if(j+1<=n) assert(abs(a[i][j]-a[i][j+1])!=1);
      }
  }
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t,cas=0;scanf("%d",&t);
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