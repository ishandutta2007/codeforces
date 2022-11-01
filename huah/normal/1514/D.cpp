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
const int N=3e5+5;
int n,q,a[N];
pair<int,int>t[N<<2];
pair<int,int>Merge(pair<int,int>x,pair<int,int>y)
{
  if(x.first==y.first) return {x.first,x.second+y.second};
  if(x.second>=y.second) return {x.first,x.second-y.second};
  return {y.first,y.second-x.second};
}
void build(int l,int r,int k)
{
  if(l==r)
  {
    t[k].first=a[l];
    t[k].second=1;
    return;
  }
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  t[k]=Merge(t[k<<1],t[k<<1|1]);
}
vector<int>vc[N];
pair<int,int>query(int l,int r,int k,int x,int y)
{
  if(l>=x&&r<=y) return t[k];
  int m=(l+r)>>1;
  if(x<=m&&y>m) return Merge(query(l,m,k<<1,x,y),query(m+1,r,k<<1|1,x,y));
  if(x<=m) return query(l,m,k<<1,x,y);
  return query(m+1,r,k<<1|1,x,y);
}
int cal(int x,int len)
{
  int l=1,r=x-1,ans=x;
  while(l<=r)
  {
    int m=(l+r)>>1;
    if(x-(m-1)<=(len-(m-1)+1)/2) ans=m,r=m-1;
    else l=m+1;
  }
  return ans;
}
void sol(int cas)
{
  sc(n,q);
  rep(i,1,n) sc(a[i]),vc[a[i]].push_back(i);
  build(1,n,1);
  while(q--)
  {
    int l,r;
    sc(l,r);
    int x=query(1,n,1,l,r).first;
    int sum=(upper_bound(vc[x].begin(),vc[x].end(),r)-vc[x].begin())-(lower_bound(vc[x].begin(),vc[x].end(),l)-vc[x].begin());
    printf("%d\n",cal(sum,r-l+1));
  }
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
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/