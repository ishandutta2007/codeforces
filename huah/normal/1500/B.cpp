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
const int N=2e6+5,mod=1e9+7;
int n,m;
ll k;
int a[N],b[N],p1[N],p2[N];
vector<pair<int,int>>vc;
int f1[N],f2[N];
bool vis1[N],vis2[N];
ll cal(ll mid)
{
  ll ans=0;
  for(pair<int,int>pr:vc)
  {
    int a=pr.first,b=pr.second;
    //find the number x so that x<mid and x\modn=a and x\mod m=b
    //a a+n a+2n ... a+tn
    //(a+x*n)%m=b
    //x*n%m=(b-a)%m
    int c=((b-a)%m+m)%m;
    if(vis1[c])
    {
      int x=f1[c],z=f2[c]-f1[c];
      ll t=((mid-1)-a)/n;
      if(x<=t) ans+=(t-x)/z+1;
    }
    //x*n%m=c x=c*inv(n)
  }
  return ans;
}
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n,m);sc(k);
  for(int x=0;x<=3*(n+m);x++)
  {
    int t=1ll*x*n%m;
    if(!vis1[t]) vis1[t]=true,f1[t]=x;
    else if(!vis2[t]) vis2[t]=true,f2[t]=x;
  }
  rep(i,1,n) sc(a[i]),p1[a[i]]=i;
  rep(i,1,m) sc(b[i]),p2[b[i]]=i;
  rep(i,1,2000000)
    if(p1[i]&&p2[i]) vc.push_back({p1[i]-1,p2[i]-1});
  ll l=1,r=1e18;
  while(l<r)
  {
    ll m=(l+r)>>1;
    if(m-cal(m)>=k) r=m;
    else l=m+1;
  }
  out(r);
}