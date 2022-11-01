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
const int N=5e5+5,mod=998244353;
int n,q;
char s[N];
void up(int &x,int y){if(y>x)x=y;}
struct node
{
  int a,b,c,ab,bc,abc;
  node(){a=b=c=ab=bc=abc=0;}
}t[N<<2];
void Merge(node &ans,node l,node r)
{
  ans.a=l.a+r.a;
  ans.b=l.b+r.b;
  ans.c=l.c+r.c;
  ans.ab=min(l.a+r.ab,l.ab+r.b);
  ans.bc=min(l.b+r.bc,l.bc+r.c);
  ans.abc=min(min(l.abc+r.c,l.a+r.abc),l.ab+r.bc);
}
void build(int l,int r,int k)
{
  if(l==r)
  {
    t[k]=node();
    if(s[l]=='a') t[k].a=1;
    else if(s[l]=='b') t[k].b=1;
    else t[k].c=1;
    return;
  }
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  Merge(t[k],t[k<<1],t[k<<1|1]);
}
void fix(int l,int r,int k,int x)
{
  if(l==r)
  {
    t[k]=node();
    if(s[l]=='a') t[k].a=1;
    else if(s[l]=='b') t[k].b=1;
    else t[k].c=1;
    return;
  }
  int m=(l+r)>>1;
  if(x<=m) fix(l,m,k<<1,x);
  else fix(m+1,r,k<<1|1,x);
  Merge(t[k],t[k<<1],t[k<<1|1]);
}
bool judge(string s,string t)
{
  int j=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]==t[j]) j++;
    if(j==int(t.size())) return true;
  }
  return false;
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n,q);
  sc(s+1);
  build(1,n,1);
  while(q--)
  {
    int x;char c;
    cin>>x>>c;
    s[x]=c;
    fix(1,n,1,x);
    out(t[1].abc);
  }
}