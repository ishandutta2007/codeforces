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
const int N=5e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int n;
ll query(int l,int r)
{
  printf("? %d %d\n",l,r);
  fflush(stdout);
  ll ans;scanf("%lld",&ans);
  return ans;
}
ll query(int x)
{
  return query(1,x);
}
int getlen(ll x)
{
  x*=2;
  ll l=1,r=sqrt(x)+100;
  ll ans=0;
  while(l<=r)
  {
    ll m=(l+r)>>1;
    if(m*(m-1)<=x) ans=m,l=m+1;
    else r=m-1;
  }
  return ans;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;
    sc(t);
    while(t--)
    {
        sc(n);
        int i=1,t=1;
        while(i+t*2<=n) t*=2;
        ll all=query(n);
        while(t)
        {
          if(i+t<=n&&query(i+t)==0) i+=t;
          t>>=1;
        }
        int j=i+query(i,n)-query(i+1,n)+1;
        int k=j-1+getlen(query(n)-query(j-1));
        printf("! %d %d %d\n",i,j,k);
        fflush(stdout);
    }
}