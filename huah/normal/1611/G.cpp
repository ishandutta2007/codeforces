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
const int N=1e6+5,mod=998244353;
int n,m;
vector<char>a[N];
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  int t;sc(t);
  while(t--)
  {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) a[i].resize(m+2);
    for(int i=1;i<=n;i++)
      scanf("%s",a[i].begin()+1);
    multiset<int>s[2];
    int ad[2];
    function<void(int,int)>sol=[&](int x,int y)
    {
      int p=x,op=(x+y)&1;
      while(x>=1&&x<=n&&y>=1&&y<=m)
      {
        if(a[x][y]=='1')
        {
          if(s[op].size())
          {
            auto it=s[op].upper_bound(p-ad[op]);
            if(it!=s[op].begin())
            {
              it--;s[op].erase(it);
            }
          }
          s[op].insert(p-ad[op]);
        }
        x++;y--;p++;
      }
      ad[op]++;
    };
    for(int i=1;i<=m;i++) sol(1,i);
    for(int i=2;i<=n;i++) sol(i,m);
    printf("%d\n",int(s[0].size())+int(s[1].size()));
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/