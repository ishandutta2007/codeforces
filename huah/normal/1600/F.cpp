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
const int N=3e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,m;
vector<int>e[N];
bool vis[N];
map<pair<int,int>,bool>use;
vector<int>rdnode()
{
  vector<int>ans;
  for(int i=1;i<=5;i++)
  {
    int x=rdint(1,n);
    while(vis[x]) x=rdint(1,n);
    vis[x]=true;ans.push_back(x);
  }
  for(int x:ans) vis[x]=false;
  return ans;
}
bool judge(vector<int>&vc)
{
  int s=0;
  for(int i=0;i<vc.size();i++)
    for(int j=i+1;j<vc.size();j++)
    s+=use.count({vc[i],vc[j]});
  return s==0||s==10;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n,m);
    rep(i,1,m)
    {
      int u,v;sc(u,v);e[u].push_back(v);e[v].push_back(u);
    }
    n=min(n,50);
    {
      bool ok[55][55];memset(ok,false,sizeof(ok));
      rep(i,1,n)
        for(int j:e[i])
        if(j<=n) ok[i][j]=true;
      bool flag=true;
      for(int i=1;flag&&i<=n;i++)
        for(int j=i+1;flag&&j<=n;j++)
        if(ok[i][j])
        for(int k=j+1;flag&&k<=n;k++)
        if(ok[i][k]&&ok[j][k])
          for(int h=k+1;flag&&h<=n;h++)
          if(ok[i][h]&&ok[j][h]&&ok[k][h])
            for(int f=h+1;flag&&f<=n;f++)
            if(ok[i][f]&&ok[j][f]&&ok[k][f]&&ok[h][f])
            {
              flag=false;
              printf("%d %d %d %d %d\n",i,j,k,h,f);
            }
      rep(i,1,n)rep(j,1,n) ok[i][j]=!ok[i][j];
      for(int i=1;flag&&i<=n;i++)
        for(int j=i+1;flag&&j<=n;j++)
        if(ok[i][j])
        for(int k=j+1;flag&&k<=n;k++)
        if(ok[i][k]&&ok[j][k])
          for(int h=k+1;flag&&h<=n;h++)
          if(ok[i][h]&&ok[j][h]&&ok[k][h])
            for(int f=h+1;flag&&f<=n;f++)
            if(ok[i][f]&&ok[j][f]&&ok[k][f]&&ok[h][f])
            {
              flag=false;
              printf("%d %d %d %d %d\n",i,j,k,h,f);
            }
          if(flag) out(-1);
    }
}