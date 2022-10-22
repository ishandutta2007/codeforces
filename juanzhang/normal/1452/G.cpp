#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=4e5+10;
void chkmin(int&x,int y){if(x>y)x=y;}
void chkmax(int&x,int y){if(x<y)x=y;}
int n,k;bool can[maxn];vector<int>E[maxn];

int sss,rt,sumsz,maxd,sz[maxn],dis[maxn],dep[maxn],ans[maxn],val[maxn];bool vis[maxn];
void dfs1(int u,int f){
  dis[u]=can[u]?0:n+1;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),chkmin(dis[u],dis[v]+1);
  }
}
void dfs2(int u,int f){
  for(int v:E[u])if(v!=f)chkmin(dis[v],dis[u]+1),dfs2(v,u);
}
void dfs3(int u,int f){
  int res=0;sz[u]=1;for(int v:E[u])if(v!=f&&!vis[v])dfs3(v,u),sz[u]+=sz[v],chkmax(res,sz[v]);
  chkmax(res,sumsz-sz[u]);
  if(sss>res)sss=res,rt=u;
}
void dfs6(int u,int f){
  sz[u]=1,chkmax(maxd,dep[u]);
  for(int v:E[u])if(v!=f&&!vis[v])dep[v]=dep[u]+1,dfs6(v,u),sz[u]+=sz[v];
}
void dfs4(int u,int f){
  if(dis[u]>dep[u])chkmax(val[dis[u]-dep[u]-1],dis[u]);
  for(int v:E[u])if(v!=f&&!vis[v])dfs4(v,u);
}
void dfs5(int u,int f){
  chkmax(ans[u],val[dep[u]]);
  for(int v:E[u])if(v!=f&&!vis[v])dfs5(v,u);
}
void divide(int u){
  sss=1e9,dfs3(u,0),u=rt,maxd=dep[u]=0,dfs6(u,0),maxd=maxd*4+5;
  memset(val,0,(maxd+1)<<2),dfs4(u,0);
  per(i,maxd,1)val[i-1]=max(val[i-1],val[i]);dfs5(u,0);
  vis[u]=1;
  for(int v:E[u])if(!vis[v])sumsz=sz[v],divide(v);
}

int main(){
  cin>>n;rep(i,2,n){
    int u,v;scanf("%d%d",&u,&v),E[u].push_back(v),E[v].push_back(u);
  }cin>>k;rep(i,1,k){
    int x;scanf("%d",&x),can[x]=1;
  }dfs1(1,0),dfs2(1,0);
  sumsz=n,divide(1);
  rep(i,1,n)printf("%d ",ans[i]);
  return 0;
}