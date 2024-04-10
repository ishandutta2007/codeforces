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
const int N=1e6+5,mod=1e9+7;
int n,k,rt=1,tot=1,t[N*10][2],mn[N*10],mx[N*10];
vector<int>vc[25];
int ans[25];
void ins(int x)
{
  int now=rt;
  for(int j=k-1;j>=0;j--)
  {
    int p=x>>j&1;
    if(p) x^=(1<<j);
    if(!t[now][p])
    {
      t[now][p]=++tot;
      mn[tot]=mx[tot]=x;
    }
    now=t[now][p];
    mn[now]=min(mn[now],x);
    mx[now]=max(mx[now],x);
  }
}
void dfs(int u,int bit)
{
  if(!u) return;
  vc[bit].push_back(u);
  if(t[u][0]&&t[u][1])
    ans[bit]=min(ans[bit],mn[t[u][1]]+(1<<bit)-mx[t[u][0]]);
  if(bit)
  {
    dfs(t[u][0],bit-1);
    dfs(t[u][1],bit-1);
  }
}
int answer[N],rev[N];
void update(int u,int bit)
{
  if(!u) return;
  if(t[u][0]) mn[u]=mn[t[u][0]];
  else mn[u]=(1<<bit)+mn[t[u][1]];
  if(t[u][1]) mx[u]=(1<<bit)+mx[t[u][1]];
  else mx[u]=mx[t[u][0]];
}
int code[N];
void GrayCode(int k)
{
  code[0]=0;code[1]=1;
  int len=2;
  for(int j=2;j<=k;j++)
  {
    for(int l=len-1,r=len;l>=0;l--,r++)
      code[r]=code[l]|(1<<(j-1));
    len*=2;
  }
}
void Rev(int bit)
{
  ans[bit]=998244353;
  for(int u:vc[bit])
  {
    swap(t[u][0],t[u][1]);
    if(t[u][0]&&t[u][1])
      ans[bit]=min(ans[bit],mn[t[u][1]]+(1<<bit)-mx[t[u][0]]);
    
  }
  for(int i=bit+1;i<k;i++)
  {
    ans[i]=998244353;
    for(int u:vc[i])
    {
      update(t[u][0],i-1);update(t[u][1],i-1);
      if(t[u][0]&&t[u][1])
        ans[i]=min(ans[i],mn[t[u][1]]+(1<<i)-mx[t[u][0]]);
    }
  }
}
void sol(int cas)
{
  sc(n,k);
  rep(i,1,n)
  {
    int x;sc(x);
    ins(x);
  }
  rep(i,0,k-1) ans[i]=998244353;
  dfs(rt,k-1);
  GrayCode(k);
  int up=1<<k;
  for(int i=1;i<up;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
  for(int i=0;i<up;i++)
  {
    int res=998244353;
    rep(j,0,k-1) res=min(res,ans[j]);
    answer[rev[code[i]]]=res;
    if(i+1<up)
    {
      int x=rev[code[i]]^rev[code[i+1]];
      for(int j=0;j<k;j++)
      if(x>>j&1) Rev(j);
    }
  }
  rep(i,0,up-1) printf(i==up-1?"%d\n":"%d ",answer[i]);
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
/*
befor submit code check:
freopen
size of N
mod
debug output
*/