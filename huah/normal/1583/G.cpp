#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=4e5+5,mod=1e9+7;
int n,f[N],bit[N];
void add(int x,int v)
{
  while(x<=2*n) bit[x]=(bit[x]+v)%mod,x+=x&-x;
}
int query(int x)
{
  int ans=0;
  while(x) ans=(ans+bit[x])%mod,x-=x&-x;
  return ans;
}
struct node
{
  int l,r,id;
  bool operator<(const node&o)const
  {
    return r<o.r;
  }
}a[N];
bool vis[N];
int main()
{
  	// freopen("1.in","r",stdin);
    sc(n);
    rep(i,1,n) sc(a[i].l,a[i].r),a[i].id=i;
    sort(a+1,a+1+n);
    int t;sc(t);
    while(t--){int x;sc(x);vis[x]=true;}
    int ans=0,mx=0;
    rep(i,1,n)
    {
      f[i]=(query(a[i].r-1)-query(a[i].l-1)+mod+1)%mod;
      add(a[i].l,f[i]);
    }
    nep(i,n,1)
    {
      if(a[i].l<=mx||vis[a[i].id])
        ans=(ans+f[i])%mod,mx=max(mx,a[i].l);
    }
    out(ans);
}