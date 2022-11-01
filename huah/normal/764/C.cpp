#pragma GCC optimize(2)
#include<bits/stdc++.h>
typedef unsigned long long ull;
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
void iary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void iary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=2e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,a[N],f[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
vector<int>edge[N];
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("2.out","w",stdout);
//   int t;sc(t);ast(t,1,10);
  int t=1;
  while(t--)
  {
    sc(n);ast(n,2,100000);
    vector<pair<int,int>>e;
    rep(i,1,n) f[i]=i;
    rep(i,1,n-1)
    {
      int u,v;sc(u,v);
      ast(u,1,n);ast(v,1,n);
      e.push_back({u,v});
      assert(getf(u)!=getf(v));
      f[getf(u)]=getf(v);
    }
    rep(i,1,n) sc(a[i]),ast(a[i],1,100000);
    rep(i,1,n) f[i]=i;
    for(auto x:e)
      if(a[x.first]==a[x.second]) f[getf(x.first)]=getf(x.second);
    vector<int>d(n+1);
    rep(i,1,n) edge[i].clear();
    for(auto x:e)
    {
      if(getf(x.first)!=getf(x.second)) d[getf(x.first)]++,d[getf(x.second)]++;
      edge[x.first].push_back(x.second);
      edge[x.second].push_back(x.first);
    }
    int ans=-1;
    rep(i,1,n)
    {
      bool flag=true;
      int dd=0;
      for(int v:edge[i])
        if(getf(v)!=getf(i))
        {
          dd++;
          if(d[getf(v)]!=1)
          {
            flag=false;
          }
        }
      if(dd!=d[getf(i)]) flag=false;
      if(flag){ans=i;break;}
    }
    if(ans==-1) printf("NO\n");
    else printf("YES\n"),out(ans);
  }
}