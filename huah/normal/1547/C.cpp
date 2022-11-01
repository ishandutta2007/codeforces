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
int k,n,m,a[N],b[N];
char s[N];
void sol(int cas)
{
  sc(k,n,m);
  rep(i,1,n) sc(a[i]);
  rep(i,1,m) sc(b[i]);
  int i=1,j=1;
  vector<int>v;
  while(i<=n||j<=m)
  {
    if(i<=n&&a[i]<=k)
    {
      v.push_back(a[i]);
      k+=a[i]==0;
      i++;
      continue;
    }
    if(j<=m&&b[j]<=k)
    {
      v.push_back(b[j]);
      k+=b[j]==0;
      j++;
      continue;
    }
    break;
  }
  if(v.size()!=n+m)
  {
    out(-1);return;
  }
  for(int i=0;i<v.size();i++) printf(i==v.size()-1?"%d\n":"%d ",v[i]);
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