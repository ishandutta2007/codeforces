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
int ans;
bool Judge(int l,int r)
{
  if(l>=1&&r<=n&&s[l]=='a'&&s[l+1]=='b'&&s[l+2]=='c') return true;
  return false;
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n,q);
  sc(s+1);
  for(int i=1;i+2<=n;i++)
    if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c') ans++;
  while(q--)
  {
    int x;char c;
    cin>>x>>c;
    for(int i=x-2;i<=x;i++)
      if(Judge(i,x)) ans--;
    s[x]=c;
    for(int i=x-2;i<=x;i++)
      if(Judge(i,x)) ans++;
    out(ans);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/