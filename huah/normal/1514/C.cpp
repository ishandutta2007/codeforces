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
const int N=2e5+5,mod=1e9+7;
int n,a[N];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
void sol(int cas)
{
  // for(int i=2;i<=20;i++)
  // {
  //   cout<<"Ans #"<<i<<": ";
  //   int len=0,p;
  //   for(int j=1;j<1<<(i-1);j++)
  //   {
  //     ll ans=1;
  //     for(int k=0;k<i-1;k++)
  //     if(j>>k&1)
  //     {
  //       ans=ans*(k+1)%i;
  //     }
  //     if(ans==1&&__builtin_popcount(j)>len)
  //     {
  //       len=__builtin_popcount(j);
  //       p=j;
  //     }
  //   }
  //   for(int k=0;k<i-1;k++)
  //       if(p>>k&1) cout<<k+1<<' ';
  //       cout<<endl;
  // }
  sc(n);
  vector<int>vc;
  rep(i,1,n-1) if(gcd(i,n)==1) vc.push_back(i);
  int ans=1,res=0;
  for(int x:vc) ans=1ll*ans*x%n;
  if(ans!=1)
  {
    for(int i=0;i<vc.size();i++)
      if(vc[i]==ans)
      {
        swap(vc[i],vc[vc.size()-1]);
        vc.pop_back();
        break;
      }
  }
  printf("%d\n",vc.size());
  for(int i=0;i<vc.size();i++) printf(i==vc.size()-1?"%d\n":"%d ",vc[i]);
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