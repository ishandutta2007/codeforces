/*
so hard to write
*/
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
void ary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void ary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=5e5+5,mod=998244353;
int hs,n1,n2,m,f[N],h[N][2],p[N],d[N],c[N];
vector<int>e[N];
pair<int,int>g[N][2];
bool vis[N];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void del(int x,int sx)
{
  g[x][sx]={0,0};
}
void rev(int &y,int &ey,int &sy,int &yy,int &eyy,int &syy)
{
  int u=getf(ey);
  add(hs,mod-h[u][1]);
  swap(h[u][1],h[u][0]);
  // if(syy!=c[eyy]) cout<<"?: "<<yy<<' '<<syy<<' '<<c[eyy]<<'\n';
  sy^=1;syy^=1;
  c[ey]=sy;c[eyy]=syy;
  add(hs,h[u][1]);
}
void link(int u,int v)
{
  int fu=getf(u),fv=getf(v);
  if(fu!=fv)
  {
    e[u].push_back(v);
    e[v].push_back(u);
    d[u]++;d[v]++;
    f[fv]=fu;
    add(h[fu][0],h[fv][0]);
    add(h[fu][1],h[fv][1]);
  }
}
void link(int x,int ex,int sx,int xx,int exx,int sxx,int y,int ey,int sy,int yy,int eyy,int syy,int id,bool op,int sid)
{
  c[id]=sid;
  del(x,sx);
  del(xx,sxx);
  del(y,sy);
  del(yy,syy);
  if(op) rev(y,ey,sy,yy,eyy,syy);
  if(sid) add(h[id][1],p[id]),add(hs,p[id]);
  else add(h[id][0],p[id]);
  bool flag=getf(ex)!=getf(ey);
  // cout<<"F: "<<flag<<'\n';
  link(ex,id);
  link(id,ey);
  if(flag)
  {
    assert(g[xx][sxx].first==0);
    assert(g[yy][syy].first==0);
    g[xx][sxx]={yy,exx};
    g[yy][syy]={xx,eyy};
  }
}
void link(int x,int ex,int sx,int xx,int exx,int sxx,int y,int id,int sid)
{
  c[id]=sid;
  del(x,sx);
  del(xx,sxx);
  if(sid) add(h[id][1],p[id]),add(hs,p[id]);
  else add(h[id][0],p[id]);
  link(ex,id);
  assert(g[y][sid].first==0);
  assert(g[xx][sxx].first==0);
  g[y][sid]={xx,id};
  g[xx][sxx]={y,exx};
}
void add(int x,int y,int id)
{
  assert(!(g[x][0].first&&g[x][1].first||g[y][0].first&&g[y][1].first));
  for(int i=0;i<=1;i++)
    if(g[x][i].first&&g[y][i].first)
    {
      // cout<<"OK1"<<' '<<x<<' '<<y<<' '<<i<<endl;
      int xx=g[x][i].first,ex=g[x][i].second;
      int yy=g[y][i].first,ey=g[y][i].second;
      int sx=i,sy=i;
      int sxx=g[xx][1].first==x;
      int syy=g[yy][1].first==y;
      assert(g[yy][syy].first==y);
      int exx=g[xx][sxx].second;
      int eyy=g[yy][syy].second;
      link(x,ex,sx,xx,exx,sxx,y,ey,sy,yy,eyy,syy,id,0,i^1);
      return;
    }
  for(int i=0;i<=1;i++)
    if(g[x][i].first&&g[y][i^1].first)
    {
      // cout<<"OK2"<<endl;
      int xx=g[x][i].first,ex=g[x][i].second;
      int yy=g[y][i^1].first,ey=g[y][i^1].second;
      int sx=i,sy=i^1;
      int sxx=g[xx][1].first==x;
      int syy=g[yy][1].first==y;
      assert(g[yy][syy].first==y);
      int exx=g[xx][sxx].second;
      int eyy=g[yy][syy].second;
      link(x,ex,sx,xx,exx,sxx,y,ey,sy,yy,eyy,syy,id,1,i^1);
      return;
    }
  for(int i=0;i<=1;i++)
    if(g[x][i].first||g[y][i].first)
    {
      // cout<<"OK3"<<endl;
      if(g[x][i].first)
      {
        int xx=g[x][i].first,ex=g[x][i].second;
        int sx=i;
        int sxx=g[xx][1].first==x;
        int exx=g[xx][sxx].second;
        link(x,ex,sx,xx,exx,sxx,y,id,i^1);
      }
      else
      {
        int yy=g[y][i].first,ey=g[y][i].second;
        int sy=i;
        int syy=g[yy][1].first==y;
        int eyy=g[yy][syy].second;
        link(y,ey,sy,yy,eyy,syy,x,id,i^1);
      }
      return;
    }
  // cout<<"OK4"<<endl;
  h[id][0]=p[id];
  g[x][0]={y,id};
  g[y][0]={x,id};
  c[id]=0;
}
vector<int>ans;
void dfs(int u,int c)
{
  vis[u]=true;
  if(c) ans.push_back(u);
  for(int v:e[u])
    if(!vis[v])
    dfs(v,c^1);
}
int u[N],v[N];
int main()
{
  // freopen("1.in","r",stdin);
  p[0]=1;
  rep(i,1,N-1) p[i]=1ll*p[i-1]*2%mod;
  sc(n1,n2,m);
  rep(i,1,400000) f[i]=i;
  rep(i,1,m)
  {
    int x,y;sc(x,y);y+=n1;
    u[i]=x;v[i]=y;
    add(x,y,i);
  }
  int q;sc(q);
  while(q--)
  {
    int op,x,y;
    sc(op);
    if(op==1)
    {
      sc(x,y);y+=n1;
      add(x,y,++m);
      u[m]=x;v[m]=y;
      out(hs);
    }
    else
    {
      memset(vis,false,sizeof(vis));
      ans.clear();
      rep(i,1,m)
        if(d[i]<=1&&!vis[i])
        dfs(i,c[i]);
      // int res=0;
      // for(int x:ans) add(res,p[x]);
      // cout<<hs<<' '<<res<<'\n';
      printf("%d",ans.size());
      for(int x:ans) printf(" %d",x);
      putchar('\n');
      // vector<bool>vs(m);
      // vector<int>ds(n1+n2+1),gs(n1+n2+1);
      // for(int x:ans) vs[x]=true;
      // rep(i,1,m)
      // {
      //   if(vs[i]) ds[u[i]]--,ds[v[i]]--;
      //   else ds[u[i]]++,ds[v[i]]++;
      //   gs[u[i]]^=1;gs[v[i]]^=1;
      // }
      // rep(i,1,n1+n2)
      //   assert(abs(ds[i])==gs[i]);
      //   if(abs(ds[i])!=gs[i])
      // cout<<abs(ds[i])<<' '<<gs[i]<<'\n';
    }
    fflush(stdout);
  }
}