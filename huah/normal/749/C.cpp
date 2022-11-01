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
const int N=3e5+5,mod=998244353;
int n;
char s[N];
void sol(int cas)
{ 
  sc(n);ast(n,1,200000);
  sc(s+1);
  rep(i,1,n) assert(s[i]=='D'||s[i]=='R');
  deque<int>q1,q2;
  for(int i=1;i<=n;i++)
    if(s[i]=='D') q1.push_back(i);
    else q2.push_back(i);
  while(q1.size()&&q2.size())
  {
    if(q1.front()<q2.front())
    {
      q2.pop_front();
      q1.push_back(q1.front()+n);
      q1.pop_front();
    }
    else
    {
      q1.pop_front();
      q2.push_back(q2.front()+n);
      q2.pop_front();
    }
  }
  if(q1.size()) putchar('D');
  else putchar('R');
  putchar('\n');
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  //scanf("%d",&t);
  ast(t,1,10);
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