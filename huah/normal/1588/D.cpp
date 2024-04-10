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
const int N=3e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int n,m;
int len[11],a[11][105],f[11][105][2];
char b[105];
void input()
{
  int vis[288];
  memset(vis,0,sizeof(vis));
  m=0;
  for(int i=1;i<=n;i++)
  {
    string s;
    cin>>s;
    len[i]=s.size();
    for(int j=0;j<s.size();j++)
    {
      if(!vis[s[j]]) vis[s[j]]=++m;
      a[i][j+1]=vis[s[j]]-1;
      if(i==1) b[j+1]=s[j];
    }
  }
  memset(f,inf,sizeof(f));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=len[i];j++)
      if(f[i][a[i][j]][0]==inf) f[i][a[i][j]][0]=j;
      else f[i][a[i][j]][1]=j;
  }
}
int dp[105][1<<10];
pair<int,int>pre[105][1<<10];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;
    sc(t);
    while(t--)
    {
      sc(n);
      input();
      memset(dp,0,sizeof(dp));
      int up=1<<n,ans=0;
      int x=-1,y=-1;
      memset(pre,-1,sizeof(pre));
      for(int i=1;i<=len[1];i++)
      {
        for(int j=0;j<up;j++)
        {
          int pos[11];
          for(int k=0;k<n;k++)
            pos[k+1]=f[k+1][a[1][i]][j>>k&1];
          bool flag=true;
          for(int k=1;k<=n;k++)
            if(pos[k]==inf) flag=false;
          if(!flag) continue;
          dp[i][j]++;
          if(dp[i][j]>ans) ans=dp[i][j],x=i,y=j;
          for(int k=0;k<m;k++)
          {
            int st=0,nx;
            bool flag=true;
            for(int h=1;h<=n;h++)
            {
              if(f[h][k][1]<=pos[h]){flag=false;break;}
              if(f[h][k][0]<=pos[h]) st|=1<<(h-1);
              if(h==1) 
              {
                if(f[h][k][0]<=pos[h]) nx=f[h][k][1];
                else nx=f[h][k][0];
              }
            }
            if(!flag||nx==inf) continue;
            if(dp[i][j]>dp[nx][st])
            {
              dp[nx][st]=dp[i][j];
              pre[nx][st]={i,j};
            }
          }
        }
      }
      out(ans);
      string res="";
      while(!(x==-1&&y==-1))
      {
        res=b[x]+res;
        pair<int,int>nex=pre[x][y];
        x=nex.first;y=nex.second;
      }
      cout<<res<<'\n';
    }
}