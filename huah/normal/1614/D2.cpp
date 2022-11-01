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
const int N=2e7+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,vis[N];
int tot,p[N];
bitset<N>use;
ll dp[N];
inline void update(ll &x,ll y){if(y>x) x=y;}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    for(int i=2;i<=20000000;i++)
    {
      if(!use[i]) p[++tot]=i;
      for(int j=1;j<=tot&&i*p[j]<=20000000;j++)
      {
        use[i*p[j]]=true;
        if(i%p[j]==0) break;
      }
    }
    sc(n);
    rep(i,1,n)
    {
      int x;sc(x);
      vis[x]++;
    }
    for(int i=1;i<=tot;i++)
      for(int j=20000000/p[i];j>=1;j--)
        vis[j]+=vis[p[i]*j];
    ll ans=0;
    dp[1]=vis[1];
    for(int j=1;j<=20000000;j++)
    {
      if(dp[j]>ans) ans=dp[j];
      for(int i=1;i<=tot&&p[i]*j<=20000000;i++)
        update(dp[p[i]*j],dp[j]+1ll*(p[i]*j-j)*vis[p[i]*j]);
    }
    out(ans);
}