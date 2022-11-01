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
const int N =5e2+5,mod=998244353;
int n,a[N<<1][N];
bool del[N<<1];
queue<int>q,dd;
vector<int>e[N][N];
vector<int>res;
void sol(int cas)
{
  scanf("%d",&n);
  res.clear();
  rep(i,1,n) rep(j,1,n) e[i][j].clear();
  rep(i,1,2*n) del[i]=false;
  rep(i,1,2*n)
    rep(j,1,n) sc(a[i][j]),e[j][a[i][j]].push_back(i);
  rep(i,1,2*n)
  if(!del[i])
    rep(j,1,n)
    if(e[j][a[i][j]].size()==1)
    {
      q.push(i);
      del[i]=true;
      break;
    }
  int ans=1,l=1;
  while(q.size()||l<=2*n)
  {
    while(q.size())
    {
      int u=q.front();q.pop();
      res.push_back(u);
      for(int j=1;j<=n;j++)
      {
        for(int v:e[j][a[u][j]])
        {
          if(!del[v])
          {
            del[v]=true;
            dd.push(v);
          }
        }
        e[j][a[u][j]].clear();
      }
      while(!dd.empty())
      {
        int u=dd.front();dd.pop();
        for(int j=1;j<=n;j++)
        {
          vector<int>&v=e[j][a[u][j]];
          int pos=lower_bound(v.begin(),v.end(),u)-v.begin();
          if(pos<v.size()&&v[pos]==u)
          {
            swap(v[pos],v[v.size()-1]);
            v.pop_back();
          }
          if(v.size()==1&&!del[v[0]])
          {
            del[v[0]]=true;
            q.push(v[0]);
          }
        }
      }
    }
    while(l<=2*n&&del[l]) l++;
    if(l<=2*n)
    {
      ans=ans*2%mod;
      q.push(l);
      del[l]=true;
      l++;
    }
  }
  out(ans);
  sort(res.begin(),res.end());
  for(int i=0;i<res.size();i++)
  printf(i==res.size()-1?"%d\n":"%d ",res[i]);
}
int main() {
  // freopen("1.in", "r",stdin);
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