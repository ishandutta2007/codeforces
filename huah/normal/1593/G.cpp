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
const int N=1e6+5;
struct node
{
  bool s,t;
  int len;
  node operator+(const node&o)const
  {
    if(len==0) return o;
    if(o.len==0) return *this;
    node ans;
    ans.s=s;
    ans.t=o.t;
    if((t^1)==o.s)
      ans.len=len+o.len;
    else
    {
      ans.len=abs(len-o.len);
      if(len<o.len) ans.s=ans.t^(ans.len&1)^1;
      else ans.t=ans.s^(ans.len&1)^1;
    }
    return ans;
  }
};
node t[N<<2];
int n;
char s[N];
void build(int l,int r,int k)
{
  if(l==r)
  {
    t[k].len=1;
    if(s[l]=='('||s[l]==')')
      t[k].s=t[k].t=0;
    else t[k].s=t[k].t=1;
    return;
  }
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  t[k]=t[k<<1]+t[k<<1|1];
}
node query(int l,int r,int k,int x,int y)
{
  if(l>=x&&r<=y) return t[k];
  int m=(l+r)>>1;
  if(x<=m&&y>m) return query(l,m,k<<1,x,y)+query(m+1,r,k<<1|1,x,y);
  if(x<=m) return query(l,m,k<<1,x,y);
  return query(m+1,r,k<<1|1,x,y);
}
void sol(int cas)
{
  sc(s+1);
  n=strlen(s+1);
  build(1,n,1);
  int q;scanf("%d",&q);
  while(q--)
  {
    int l,r;sc(l,r);
    node ans=query(1,n,1,l,r);
    if(ans.len==0) {out(0);continue;}
    if(ans.s) printf("%d\n",1+(ans.len-1)/2);
    else printf("%d\n",ans.len/2);
  }
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
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