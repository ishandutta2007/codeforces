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
const int N=5e5+5,mod=998244353;
int n,vis[30];
char s[N];
void del(int x)
{
  while(vis[x]>0) putchar(x+'a'),vis[x]--;
}
void dd(int x)
{
  assert(vis[x]>0);
  putchar(x+'a');
  vis[x]--;
}
void sol2()
{
  rep(i,0,25) if(vis[i]) assert(vis[i]>=2);
  for(int i=0;i<=25;i++)
  if(vis[i])
  {
    if(n-vis[i]>=vis[i]-2)
    {
      dd(i);dd(i);
      vector<char>vc;
      for(int j=25;j>i;j--)
      {
        while(vis[j]>0)
        {
          vc.push_back(char(j+'a'));
          vis[j]--;
        }
      }
      while(vis[i]>0)
      {
        putchar(vc.back());vc.pop_back();
        dd(i);
      }
      while(vc.size())
      {
        putchar(vc.back());vc.pop_back();
      }
    }
    else
    {
      int tot=0;
      vector<int>vc;
      for(int j=0;j<=25;j++) if(vis[j]) vc.push_back(j);
      if(vc.size()>=3)
      {
        dd(vc[0]);
        dd(vc[1]);
        del(vc[0]);
        dd(vc[2]);
        for(int x:vc) del(x);
      }
      else
      {
        assert(vc.size()==2);
        dd(vc[0]);
        del(vc[1]);
        del(vc[0]);
      }
    }
    break;
  }
  rep(i,0,25) assert(vis[i]==0);
}
void sol(int cas)
{
  memset(vis,0,sizeof(vis));
  scanf("%s",s+1);
  n=strlen(s+1);
  for(int i=1;i<=n;i++) vis[s[i]-'a']++;
  bool flag=false;
  for(int i=0;i<=25;i++)
  if(vis[i]==n||vis[i]==1)
  {
    del(i);
    for(int j=0;j<=25;j++) del(j);
  }
  if(!flag) sol2();
  putchar('\n');
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
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