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
const int N=1e7+5,mod=998244353;
#define inf 0x3f3f3f3f
int n,k;
bitset<N>vis;
int tot,p[N];
int main()
{
  for(int i=2;i<=10000000;i++)
  {
    if(!vis[i]) p[++tot]=i;
    for(int j=1;j<=tot&&i*p[j]<=10000000;j++)
    {
      vis[i*p[j]]=true;
      if(i%p[j]==0) break;
    }
  }
  // freopen("1.in","r",stdin);
  int t;sc(t);
  while(t--)
  {
    sc(n,k);
    map<int,bool>vis;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
      int x,z=1;sc(x);
      for(int j=1;j<=tot&&1ll*p[j]*p[j]<=x;j++)
        if(x%p[j]==0)
        {
          int y=0;
          while(x%p[j]==0) x/=p[j],y^=1;
          if(y) z*=p[j];
        }
      if(x>1) z*=x;
      if(vis[z])
      {
        ans++;
        vis.clear();
      }
      vis[z]=true;
    }
    out(ans);
  }
}