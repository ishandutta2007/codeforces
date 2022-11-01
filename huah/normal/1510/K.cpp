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
int n,a[N],b[N],c[N],d[N];
bool judge(int x,int y)
{
  rep(i,1,2*n) b[i]=a[i];
  if(x) rep(i,1,n) swap(b[i],b[i+n]);
  if(y) for(int i=1;i<=2*n;i+=2) swap(b[i],b[i+1]);
  rep(i,1,2*n) if(b[i]!=i) return false;
  return true;
}
vector<int>e[N];
int tot;
bool vis[N];
void dfs(int u)
{
  b[++tot]=u;
  vis[u]=true;
  for(int v:e[u])
  if(!vis[v]) dfs(v);
}
int sol1()
{
  int ans,t=0;
  for(int i=1;i<=tot;i++)
    if(c[i]==b[1])
    {
      ans=i-1;
      rep(i,1,tot) d[i]=c[i];
      int j=i;
      while(j!=1)
      {
        for(int k=j;k<=tot;k+=2)
          swap(d[k],d[k-1]);
        for(int k=j-2;k>=1;k-=2)
        {
          int nk=k==1?tot:k-1;
          swap(d[k],d[nk]);
        }
        j--;
      }
    }
  // rep(i,1,tot) printf(i==tot?"%d\n":"%d ",d[i]);
  for(int i=1;i<=tot;i++)
    if(d[i]!=b[i]) return 998244353;
  return ans;
}
int sol2()
{
  int ans,t=0;
  for(int i=1;i<=tot;i++)
    if(c[i]==b[1])
    {
      ans=tot-i+1;
      rep(i,1,tot) d[i]=c[i];
      int j=i;
      while(j!=1)
      {
        for(int k=j;k<=tot;k+=2)
        {
          int nk=k==tot?1:k+1;
          swap(d[k],d[nk]);
        }
        for(int k=j-2;k>=1;k-=2)
          swap(d[k],d[k+1]);
        j++;
        if(j==tot+1) j=1;
      }
      break;
    }
  // rep(i,1,tot) printf(i==tot?"%d\n":"%d ",d[i]);
  for(int i=1;i<=tot;i++)
    if(d[i]!=b[i]) return 998244353;
  return ans;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,2*n) sc(a[i]);
  if(n&1)
  {
    rep(i,1,n) e[i].push_back(i+n),e[i+n].push_back(i);
    for(int i=1;i<=2*n;i+=2) e[i].push_back(i+1),e[i+1].push_back(i);
    dfs(1);
    assert(tot==2*n);
    rep(i,1,tot) c[i]=a[b[i]];
    // rep(i,1,tot) printf(i==tot?"%d\n":"%d ",b[i]);
    // rep(i,1,tot) printf(i==tot?"%d\n":"%d ",c[i]);
    int ans1=sol1(),ans2=sol2();
    if(ans1!=998244353||ans2!=998244353) out(min(ans1,ans2));
    else out(-1);
  }
  else
  {
    if(judge(0,0)) out(0);
    else if(judge(0,1)||judge(1,0)) out(1);
    else if(judge(1,1)) out(2);
    else out(-1);
  }
}
/*
1-2 3-4 5-6 7-8 9-10
3
6-3 2-5 4-1
Make operation 1: 3,6,5,2,1,4.
Make operation 2: 2,1,4,3,6,5.
Make operation 1: 1,2,3,4,5,6.
*/
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
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/