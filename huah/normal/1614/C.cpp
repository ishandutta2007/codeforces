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
mt19937_64 gen(time(0));
ll rdint(ll l,ll r){return uniform_int_distribution<ll>(l,r)(gen);}
const int N=2e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,m,a[N],l[N],r[N],x[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
      sc(n,m);
      rep(i,1,m) sc(l[i],r[i],x[i]);
      ll ans=0,z=1;
      for(int i=1;i<n;i++) z=z*2%mod;
      for(int i=0;i<30;i++)
      {
        for(int j=1;j<=n;j++) a[j]=0;
        for(int j=1;j<=m;j++)
          if(!(x[j]>>i&1))
          a[l[j]]++,a[r[j]+1]--;
        for(int j=1;j<=n;j++) a[j]+=a[j-1];
        int x=0;
        for(int j=1;j<=n;j++)
          if(a[j]==0) x++;
        if(x==0) continue;
        ans=(ans+(1<<i)*z%mod)%mod;
      }
      out(ans);
    }
}