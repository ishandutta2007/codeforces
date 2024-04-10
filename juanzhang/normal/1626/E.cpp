#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=3e5+10;
int n,c[maxn],ans[maxn];

int ecnt=1,h[maxn];
struct edges{
  int nxt,to;
}E[maxn<<1];
void addline(int u,int v){
  E[++ecnt]={h[u],v},h[u]=ecnt;
}

int all,sum[maxn];
int fa[maxn],dfn[maxn],sz[maxn],seq[maxn];

vector<int>tag[maxn];

void dfs1(int u,int f){
  static int now;
  fa[u]=f,dfn[u]=++now,seq[now]=u,sz[u]=1,sum[u]=c[u];
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f)dfs1(v,u),sz[u]+=sz[v],sum[u]+=sum[v];
  }
}
void dfs2(int u){
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=fa[u]){
      dfs2(v);
      if(c[u]&&sum[v])tag[u].push_back(v);
    }else{
      if(c[u]&&all-sum[u]>0)tag[u].push_back(v);
    }
  }
  if(c[u])return;
  int chk1=-1,chk2=-1;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(c[v]){
      if(chk1==-1)chk1=v;
      else chk2=v;
    }
  }
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    int s=v==fa[u]?all-sum[u]:sum[v];
    if(s){
      bool flg=0;
      if(chk1!=-1&&chk1!=v)flg=1;
      if(chk2!=-1&&chk2!=v)flg=1;
      if(flg)tag[u].push_back(v);
    }
  }
}

int main(){
  scanf("%d",&n);
  rep(i,1,n)scanf("%d",c+i);
  rep(i,2,n){
    int u,v;
    scanf("%d%d",&u,&v);
    addline(u,v);
    addline(v,u);
    if(c[u]||c[v])ans[u]=ans[v]=1;
  }
  dfs1(1,0),all=sum[1];
  dfs2(1);
  static int dat[maxn];
  rep(u,1,n){
    for(int v:tag[u]){
      if(fa[v]==u){
        dat[1]++;
        dat[dfn[v]]--;
        dat[dfn[v]+sz[v]]++;
      }else{
        dat[dfn[u]]++,dat[dfn[u]+sz[u]]--;
      }
    }
  }
  rep(i,1,n)dat[i]+=dat[i-1];
  rep(i,1,n)ans[seq[i]]|=(bool)dat[i];
  rep(i,1,n)printf("%d ",ans[i]);
  return 0;
}