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
const int N=1e6+5,mod=1e9+7;
int a[N],dis[N];
bool vis[N];
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  int t=1;
  sc(t);
  while(t--)
  {
    int n,d;sc(n,d);
    for(int i=0;i<n;i++) sc(a[i]),vis[i]=false,dis[i]=0;
    if(d==n)
    {
      int z=0;
      for(int i=0;i<n;i++) z+=a[i];
      if(z) out(-1);
      else out(0);
      continue;
    }
    int ans=0;
    bool flag=true;
    for(int i=0;i<n;i++)
      if(a[i]&&!vis[i])
      {
        int u=i;
        vector<int>s;
        while(!vis[u])
        {
          s.push_back(u);
          vis[u]=true;
          u=(u+n-d)%n;
          if(a[u]==0) break;
        }
        if(u==s[0])
        {
          flag=false;break;
        }
        while(s.size()) dis[s.back()]=dis[u]+1,u=s.back(),s.pop_back();
        ans=max(ans,dis[u]);
      }
    if(flag) out(ans);
    else out(-1);
  }
}