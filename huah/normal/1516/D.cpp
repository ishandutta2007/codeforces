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
const int N=1e5+5;
int n,q,a[N],laspos[N],dep[N],lg[N],fa[N][20];
vector<int>fac[N];
void sol(int cas)
{
  for(int i=1;i<N;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
  for(int i=2;i<=100000;i++)
    if(!fac[i].size())
      for(int j=i;j<=100000;j+=i) fac[j].push_back(i);
  sc(n,q);
  rep(i,1,n) sc(a[i]);
  rep(i,1,100000) laspos[i]=n+1;
  fa[n+1][0]=n+1;
  nep(i,n,1)
  {
    int cur=n+1;
    for(int x:fac[a[i]]) cur=min(cur,laspos[x]),laspos[x]=i;
    cur=min(cur,fa[i+1][0]);
    // cout<<"FA: "<<i<<' '<<cur<<endl;
    dep[i]=dep[cur]+1;
    fa[i][0]=cur;
    for(int j=1;1<<j<=dep[cur];j++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
  }
  while(q--)
  {
    int l,r;sc(l,r);
    int ans=0;
    for(int i=lg[r-l];i>=0;i--)
      if(fa[l][i]&&fa[l][i]<=r) ans|=1<<i,l=fa[l][i];
    out(ans+1);
  }
}
int main() {
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
re Alaysis new problem
*/