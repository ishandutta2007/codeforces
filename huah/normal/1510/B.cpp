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
using namespace std;
#define inf 0x3f3f3f3f
const int N=2200;
int d,n,s,t,m,tot=1,head[N],nex[N*N*4],to[N*N*4],flow[N*N*4],wi[N*N*4];
bool vis[N];
void add(int u,int v,int f,int w)
{
  to[++tot]=v;nex[tot]=head[u];head[u]=tot;flow[tot]=f;wi[tot]=w;
  to[++tot]=u;nex[tot]=head[v];head[v]=tot;flow[tot]=0;wi[tot]=-w;
}
int dis[N],pre[N];
queue<int>q;
bool spfa()
{
  memset(dis,inf,sizeof(dis));
  bool vis[N];
  memset(vis,false,sizeof(vis));
  dis[s]=0;
  q.push(s);
  vis[s]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    vis[u]=false;
    for(int i=head[u];i;i=nex[i])
    {
      int v=to[i];
      if(flow[i]&&dis[v]>dis[u]+wi[i])
      {
        dis[v]=dis[u]+wi[i];
        pre[v]=i;
        if(!vis[v])
        {
          q.push(v);vis[v]=true;
        }
      }
    }
  }
  return dis[t]!=inf;
}
int mxflow,mncost;
void Dinic()
{
  while(spfa())
  {
    if(dis[t]>=0) break;
    mxflow++;
    for(int i=t;i!=s;i=to[pre[i]^1])
    {
      flow[pre[i]]--;
      flow[pre[i]^1]++;
      mncost+=wi[pre[i]];
    }
  }
}
int p[N];
bool del[N];
int main()
{
  sc(d,n);
  rep(i,1,n)
  {
    string s;
    cin>>s;
    int x=0;
    for(int i=0;i<s.size();i++)
      x=(x<<1)+s[i]-'0';
    vis[x]=true;
  }
  m=1<<d;
  s=2*m;t=s+1;
  int res=0;
  vector<int>lg(m);
  for(int i=1;i<m;i++)
    lg[i]=lg[i-1]+(1<<lg[i-1]==i);
  for(int i=0;i<m;i++)
  if(vis[i])
  {
    res+=__builtin_popcount(i)+1;
    add(s,i,1,0),add(i+m,t,inf,0);
    add(i,i+m,1,0);
    int s=(m-1)^i;
    for(int j=s;j;j=(j-1)&s)
      if(vis[i^j]) add(i+m,i^j,1,-__builtin_popcount(i)-1);
  }
  Dinic();
  out(res+mncost-1);
  for(int i=2;i<=tot;i+=2)
  {
    int u=to[i^1],v=to[i];
    if(u>=m&&u<s&&v<m&&flow[i]==0)
      p[v]=u-m;
  }
  vector<int>ans;
  for(int i=m-1;i>=0;i--)
  if(vis[i]&&!del[i])
  {
    vector<int>vc;
    for(int j=i;j;j=p[j])
      vc.push_back(j),del[j]=true;
    reverse(vc.begin(),vc.end());
    int pre=0;
    for(int x:vc)
    {
      int s=pre^x;
      while(s) ans.push_back(lg[s&-s]-1),s^=s&-s;
      pre=x;
    }
    ans.push_back(-1);
  }
  ans.pop_back();
  // assert(ans.size()==res+mncost-1);
  for(int i=0;i<ans.size();i++)
  {
    if(ans[i]==-1) putchar('R');
    else putchar(d-1-ans[i]+'0');
    if(i==ans.size()-1) putchar('\n');
    else putchar(' ');
  }
}