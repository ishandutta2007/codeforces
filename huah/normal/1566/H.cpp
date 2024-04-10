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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e6+5;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
int n,c;
int tot,p[N],f[N],ans[N],g[N];
vector<int>group[N];
void init()
{
  f[1]=1;
  group[1].emplace_back(1);
  rep(i,2,c)
  {
    if(!f[i]) p[++tot]=i,f[i]=i;
    group[f[i]].emplace_back(i);
    for(int j=1;j<=tot&&i*p[j]<=c;j++)
    {
      if(i%p[j]==0)
      {
        f[i*p[j]]=f[i];
        break;
      }
      f[i*p[j]]=f[i]*p[j];
    }
  }
}
void getans()
{
  vector<int>vc;
  rep(i,1,c) if(f[i]==i) vc.emplace_back(i);
  printf("%d",vc.size());
  for(int x:vc) printf(" %d",x);
  printf("\n");
  fflush(stdout);
  for(int x:vc)
  {
    int y;sc(y);
    ans[x]=y;
  }
}
vector<int>answer;
vector<vector<int>>si;
vector<vector<vector<int>>>ways;
void guass(int need,vector<int>&x)
{
  int n=x.size();
  vector<bitset<20>>a(n);
  for(int i=0;i<n;i++) a[i]=x[i];
  bitset<20>b=need;
  bitset<260>l[n];
  for(int i=0;i<n;i++) l[i][i]=1;
  vector<int>col(20,-1);
  int r=0;
  for(int i=0,j=0;i<20&&j<n;i++)
  {
    int k=j;
    while(k<n&&a[k][i]==0) k++;
    if(k==n) continue;
    swap(a[k],a[j]);
    swap(l[k],l[j]);
    col[i]=j;
    for(int k=j+1;k<n;k++)
      if(a[k][i])
      {
        a[k]^=a[j];
        l[k]^=l[j];
      }
    j++;r++;
  }
  bitset<20>res;
  bitset<260>way;
  for(int i=0;i<20;i++)
  {
    if(res[i]!=b[i]&&col[i]==-1) assert(0);
    if(res[i]==b[i]) continue;
    res^=a[col[i]];
    way^=l[col[i]];
  }
  if(a.back().count()!=0)
  {
    for(int i=0;i<n;i++)
      if(way[i]) answer.emplace_back(x[i]);
    return;
  }
  vector<int>vis(261);
  si.emplace_back();
  ways.emplace_back();
  for(int t=0;t<100;t++)
  {
    bitset<260>now=way;
    for(int i=0;i<n-r;i++)
      if(gen()&1) now^=l[i+r];
    int ns=now.count();
    if(vis[ns]) continue;
    vis[ns]=true;
    si.back().emplace_back(ns);
    ways.back().emplace_back();
    for(int i=0;i<n;i++)
      if(now[i]) ways.back().back().emplace_back(x[i]);
  }
}
void sol(int cas)
{
  sc(c,n);
  init();
  // int res=0;
  // rep(i,1,c) res=max(res,int(group[i].size()));
  // out(res); res=260 when c=1000000
  // return; 
  getans();
  rep(i,2,c)
    if(f[i]==i) g[i]=ans[i]^ans[1];
  g[1]=ans[1];
  nep(i,c,2)
    if(f[i]==i)
    for(int j=i+i;j<=c;j+=i)
    if(f[j]==j) g[j]^=g[i];
  nep(i,c,1)
    if(f[i]==i)
    for(int j=i+i;j<=c;j+=i)
    if(f[j]==j) g[i]^=g[j];
  rep(i,1,c)
    if(f[i]==i)
  {
    // cout<<i<<' '<<g[i]<<' '<<group[i].size()<<endl;
      guass(g[i],group[i]);
  }
  vector<bitset<40000>>dp(int(si.size())+1);
  dp[0][0]=1;
  rep(i,1,si.size())
    for(int x:si[i-1])
    dp[i]|=dp[i-1]<<x;
  int rn=n-answer.size();
  nep(i,si.size(),1)
  {
    for(int j=0;j<si[i-1].size();j++)
    {
      int x=si[i-1][j];
      if(rn-x>=0&&dp[i-1][rn-x])
      {
        rn-=x;
        for(int y:ways[i-1][j])
          answer.emplace_back(y);
        break;
      }
    }
  }
  sort(answer.begin(),answer.end());
  for(int i=0;i<answer.size();i++)
    printf(i==answer.size()-1?"%d\n":"%d ",answer[i]);
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/