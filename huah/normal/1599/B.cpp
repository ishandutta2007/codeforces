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
const int N=1e5+5;
string rev(string s)
{
  return s=="left"?"right":"left";
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  int t;sc(t);
  while(t--)
  {
    ll n,a,b;sc(n,a,b);
    int opa=1,opb=0;
    string s1,s2;
    cin>>s1>>s2;
    if(a>b) swap(s1,s2),swap(a,b),swap(opa,opb);
    if(s1=="left"&&s2=="right")
    {
      int t=min(a,n-1-b);
      a-=t;b+=t;
      if(a==0) s1=rev(s1);
      if(b==n-1) s2=rev(s2);
    }
    if(s1==s2)
    {
      if(s1=="left")
      {
        b-=a;
        a=0;
        s1="right";
      }
      else
      {
        a+=n-1-b;
        b=n-1;
        s2="left";
      }
    }
    int t=b-a-1;
    if((t&1))
    { 
      if(opa) printf("%lld\n",n-1);
      else printf("0\n");
    }
    else
    { 
      if(opa) printf("0\n");
      else printf("%lld\n",n-1);
    }
  }
}