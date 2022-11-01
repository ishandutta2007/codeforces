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
const int N=1e6+5,mod=998244353;
int n,e,a[N],f[N][2];
int tot,p[N];
bitset<N>vis;
vector<int>vc[200005];
bool ok(ll x)
{
  return x==1||x<=1000000&&!vis[x];
}
ll cal(vector<int>&vc)
{
  int s=1;
  ll ans=0;
  for(int i=0,j1=-1,j2=-1;i<vc.size();i++)
  {
    if(j1<i) j1=i-1;
    if(j2<i) j2=i-1,s=1;
    while(j1+1<vc.size()&&vc[j1+1]==1) j1++;
    while(j2+1<vc.size()&&ok(1ll*s*vc[j2+1])) j2++,s*=vc[j2];
    if(s!=1) ans+=j2-max(i,j1);
    if(j2>=i) s/=vc[i];
  }
  return ans;
}
int main()
{
  vis[1]=1;
  for(int i=2;i<=1000000;i++)
  {
    if(!vis[i]) p[++tot]=i;
    for(int j=1;j<=tot&&i*p[j]<=1000000;j++)
    {
      vis[i*p[j]]=true;
      if(i%p[j]==0) break;
    }
  }
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  int t=1;
  sc(t);
  while(t--)
  {
    sc(n,e);
    rep(i,0,e-1) vc[i].clear();
    rep(i,1,n) sc(a[i]),vc[i%e].push_back(a[i]);
    ll ans=0;
    for(int i=0;i<e;i++) ans+=cal(vc[i]);
    printf("%lld\n",ans);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/