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
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,m,f[N],si[N],c[N];
vector<int>e[N];
vector<pair<int,int>>edge;
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int A,B;
bool flag;
void dfs(int u)
{
  if(c[u]==1) A+=si[u];
  else B+=si[u];
  for(int v:e[u])
  {
    if(!c[v]) c[v]=c[u]==1?2:1,dfs(v);
    else if(c[v]==c[u]) flag=false;
  }
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
      sc(n,m);
      edge.clear();
      rep(i,1,n) si[i]=0,e[i].clear(),f[i]=i,c[i]=0;
      rep(i,1,m)
      {
        int u,v;string op;
        cin>>u>>v>>op;
        if(op=="crewmate") f[getf(u)]=getf(v);
        else edge.push_back({u,v});
      }
      rep(i,1,n) si[getf(i)]++;
      bool fflag=true;
      for(pair<int,int>x:edge)
      {
        int u=getf(x.first),v=getf(x.second);
        if(u==v)
        {
          fflag=false;break;
        }
        e[u].push_back(v);
        e[v].push_back(u);
      }
      if(!fflag){out(-1);continue;}
      bool ff=true;
      int ans=0;
      rep(i,1,n)
        if(f[i]==i&&!c[i])
        {
          A=B=0;
          flag=true;
          c[i]=1;
          dfs(i);
          ans+=max(A,B);
          if(!flag)
          {
            ff=false;break;
          }
        }
      if(!ff){out(-1);continue;}
      else out(ans);
    }
}