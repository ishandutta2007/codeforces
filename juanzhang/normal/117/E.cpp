#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e5+10;
int n,m,U,V,echk,par[maxn];vector<int>E[maxn];

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

int fa[maxn],sz[maxn],dep[maxn],top[maxn],son[maxn],dfn[maxn],seq[maxn];

void dfs1(int u,int f){
  fa[u]=f,sz[u]=1,dep[u]=dep[f]+1;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),sz[u]+=sz[v];
    if(sz[son[u]]<sz[v])son[u]=v;
  }
}
void dfs2(int u,int tp){
  static int now;
  top[u]=tp,dfn[u]=++now,seq[now]=u;
  if(son[u])dfs2(son[u],tp);
  for(int v:E[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
}
int qlca(int u,int v){
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
  }
  return dep[u]<dep[v]?u:v;
}
int qdis(int u,int v){
  return dep[u]+dep[v]-2*dep[qlca(u,v)];
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int sum[maxn<<2],tag[maxn<<2];
void maintain(int k){
  sum[k]=sum[k<<1]+sum[k<<1|1];
}
void pushtag(int k,int l){
  tag[k]^=1,sum[k]=l-sum[k];
}
void pushdown(int k,int l){
  if(tag[k])pushtag(k<<1,(l+1)>>1),pushtag(k<<1|1,l>>1),tag[k]=0;
}
void upd(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return pushtag(k,r-l+1),void();
  pushdown(k,r-l+1);
  if(ql<=mid)upd(lson,ql,qr);
  if(qr>mid)upd(rson,ql,qr);
  maintain(k);
}
int query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return sum[k];
  pushdown(k,r-l+1);int res=0;
  if(ql<=mid)res=query(lson,ql,qr);
  if(qr>mid)res+=query(rson,ql,qr);
  return res;
}

#undef mid
#undef lson
#undef rson

void upd(int u,int v){
  int anc=qlca(u,v);
  upd(1,1,n,dfn[anc],dfn[anc]);
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
    upd(1,1,n,dfn[top[u]],dfn[u]);
  }
  if(dep[u]<dep[v])swap(u,v);
  upd(1,1,n,dfn[v],dfn[u]);
}
int query(int u,int v){
  int anc=qlca(u,v);
  int res=-query(1,1,n,dfn[anc],dfn[anc]);
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
    res+=query(1,1,n,dfn[top[u]],dfn[u]);
  }
  if(dep[u]<dep[v])swap(u,v);
  res+=query(1,1,n,dfn[v],dfn[u]);
  return res;
}
int cho[maxn],cho2=-1;
void getcir(int U,int V){
  if(dep[U]<dep[V])swap(U,V);
  while(dep[U]>dep[V]){
    int x=fa[U];cho[x]=U,U=x;
  }
  while(fa[U]!=fa[V]){
    cho[fa[U]]=U,U=fa[U];
    cho[fa[V]]=V,V=fa[V];
  }
  if(U!=V)cho[fa[U]]=U,cho2=V;
}

int main(){
  cin>>n>>m;rep(i,1,n)par[i]=i;
  rep(i,1,n){
    int u,v;scanf("%d%d",&u,&v);
    if(find(u)==find(v)){
      U=u,V=v;
    }else{
      E[u].push_back(v),E[v].push_back(u),par[find(u)]=find(v);
    }
  }
  dfs1(1,0),dfs2(1,1);
  upd(1,1,n,1,n);
  int clen=query(U,V);getcir(U,V);
  upd(1,1,n,1,n);
  while(m--){
    int S,T;scanf("%d%d",&S,&T);if(S!=T){
    if(qdis(S,U)+qdis(V,T)>qdis(S,V)+qdis(U,T))swap(U,V);
    int val=qdis(S,T),ano=qdis(S,U)+qdis(V,T)+1;
    bool flg=val>ano;
    if(val==ano){
      int nx,tp,anc=qlca(U,V),st;
      st=qlca(U,S);
      if(dep[st]<dep[qlca(S,V)])st=qlca(S,V);
      if(dep[st]<dep[anc])st=anc;
      if(st==anc){
        int zzh=cho[anc];
        if(dfn[T]>=dfn[zzh]&&dfn[T]<dfn[zzh]+sz[zzh]){
          nx=zzh,tp=cho2;
        }else{
          nx=cho2,tp=zzh;
        }
      }else{
        if(dfn[T]<dfn[st]||dfn[T]>=dfn[st]+sz[st]){
          nx=fa[st],tp=cho[st];
        }else{
          nx=cho[st],tp=fa[st];
        }
      }
      if(st==U)tp=V;
      if(st==U&&U!=anc)nx=fa[U];
      if(nx>tp)flg=1;
    }
    if(flg){
      upd(S,U),upd(V,T),echk^=1;
    }else{
      upd(S,T);
    }}
    int res=n-sum[1]-echk+(echk&&clen==query(U,V));
    printf("%d\n",res);
  }
  return 0;
}