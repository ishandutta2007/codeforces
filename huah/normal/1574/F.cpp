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
const int N=3e5+5,mod=998244353;
int n,m,k,in[N],ot[N];
vector<int>e[N];
map<pair<int,int>,bool>vis;
bool visit[N];
bool flag;
int s,t,len;
void dfs(int u)
{
  len++;
  visit[u]=true;
  if(in[u]>1||ot[u]>1) flag=false;
  if(in[u]==0) t++;
  if(ot[u]==0) s++;
  for(int v:e[u])
    if(!visit[v]) dfs(v);
}
void sol(int cas)
{
  sc(n,m,k);
  rep(i,1,n)
  {
    int c;sc(c);
    vector<int>vc;
    while(c--)
    {
      int x;sc(x);
      vc.push_back(x);
    }
    for(int j=0;j+1<vc.size();j++)
      if(!vis.count({vc[j],vc[j+1]}))
      {
        ot[vc[j]]++;
        in[vc[j+1]]++;
        e[vc[j]].push_back(vc[j+1]);
        e[vc[j+1]].push_back(vc[j]);
        vis[{vc[j],vc[j+1]}]=true;
      }
  }
  vector<int>a(k+1);
  rep(i,1,k)
    if(!visit[i])
    {
      s=t=0;
      flag=true;
      len=0;
      dfs(i);
      if(s==1&&t==1&&flag)
        a[len]++;
    }
  vector<pair<int,int>>trans;
  rep(i,1,k)
    if(a[i]) trans.push_back({i,a[i]});
  vector<int>dp(m+1);
  dp[0]=1;
  for(int i=0;i<m;i++)
    for(pair<int,int>&x:trans)
    if(i+x.first<=m)
      dp[i+x.first]=(dp[i+x.first]+1ll*dp[i]*x.second%mod)%mod;
  out(dp[m]);
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