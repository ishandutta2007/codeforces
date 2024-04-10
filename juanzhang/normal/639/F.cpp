#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int>pii;
const int maxn=3e5+10;
int n,q,tpn,lastans;vector<int>E[maxn];

namespace Tarjan{
  int m,tot,ecnt=1,h[maxn],bl[maxn],par[maxn];
  int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
  struct edges{int nxt,to;}G[maxn<<1];bool cut[maxn<<1];
  void addline(int u,int v){G[++ecnt]={h[u],v},h[u]=ecnt;}
  int dfn[maxn],low[maxn];
  void tarjan(int u,int in){
    static int now;dfn[u]=low[u]=++now;
    for(int i=h[u];i;i=G[i].nxt){
      int v=G[i].to;
      if(!dfn[v]){
        tarjan(v,i),low[u]=min(low[u],low[v]);
        if(dfn[u]<low[v])cut[i^1]=cut[i]=1;
      }else if((i^1)!=in)low[u]=min(low[u],dfn[v]);
    }
  }
  void dfs(int u){
    bl[u]=tot;
    for(int i=h[u];i;i=G[i].nxt){
      int v=G[i].to;if(!bl[v]&&!cut[i])dfs(v);
    }
  }
  void build(){
    cin>>n>>m>>q;tpn=n;
    rep(i,1,m){
      int u,v;scanf("%d%d",&u,&v),addline(u,v),addline(v,u);
    }
    rep(i,1,n)if(!dfn[i])tarjan(i,0);
    rep(i,1,n)if(!bl[i])tot++,dfs(i),par[tot]=tot;
    for(int i=2;i<=ecnt;i+=2)if(cut[i]){
      int u=bl[G[i].to],v=bl[G[i^1].to];
      E[u].push_back(v),E[v].push_back(u),par[find(u)]=find(v);
    }
    n=tot;
  }
}

namespace HPD{
  int now,rt[maxn],fa[maxn],sz[maxn],dfn[maxn],dep[maxn],son[maxn],top[maxn];
  void dfs1(int u,int f){
    sz[u]=1,fa[u]=f,dep[u]=dep[f]+1,son[u]=0;
    for(int v:E[u])if(v!=f){
      rt[v]=rt[u],dfs1(v,u),sz[u]+=sz[v];
      if(sz[son[u]]<sz[v])son[u]=v;
    }
  }
  void dfs2(int u,int tp){
    dfn[u]=++now,top[u]=tp;
    if(son[u])dfs2(son[u],tp);
    for(int v:E[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
  }
  int qlca(int u,int v){
    for(;top[u]!=top[v];u=fa[top[u]])if(dep[top[u]]<dep[top[v]])swap(u,v);
    return dep[u]<dep[v]?u:v;
  }
}

namespace Tarjan_Q{
  int tot,ecnt,h[maxn],bl[maxn];
  struct edges{int nxt,to;}G[maxn<<1];bool cut[maxn<<1];
  void addline(int u,int v){G[++ecnt]={h[u],v},h[u]=ecnt;}
  int dfn[maxn],low[maxn];
  void tarjan(int u,int in){
    static int now;dfn[u]=low[u]=++now;
    for(int i=h[u];i;i=G[i].nxt){
      int v=G[i].to;
      if(!dfn[v]){
        tarjan(v,i),low[u]=min(low[u],low[v]);
        if(dfn[u]<low[v])cut[i^1]=cut[i]=1;
      }else if((i^1)!=in)low[u]=min(low[u],dfn[v]);
    }
  }
  void dfs(int u){
    bl[u]=tot;
    for(int i=h[u];i;i=G[i].nxt){
      int v=G[i].to;if(!bl[v]&&!cut[i])dfs(v);
    }
  }
}

void add(int u,int v){Tarjan_Q::addline(u,v),Tarjan_Q::addline(v,u);}

int get(int x){x=(x+lastans)%tpn;return x?x:tpn;}
int main(){
  Tarjan::build();
  rep(i,1,n)if(!HPD::rt[i])HPD::rt[i]=i,HPD::dfs1(i,0),HPD::dfs2(i,i);
  rep(_,1,q){
    Tarjan_Q::ecnt=1,Tarjan_Q::tot=0;
    int k1,k2;
    vector<pii>edg;
    vector<int>vec,nod,ano;
    scanf("%d%d",&k1,&k2);
    rep(i,1,k1){
      int u;scanf("%d",&u),u=Tarjan::bl[get(u)];
      nod.push_back(u),vec.push_back(u);
    }
    rep(i,1,k2){
      int u,v;scanf("%d%d",&u,&v),u=Tarjan::bl[get(u)],v=Tarjan::bl[get(v)];
      vec.push_back(u);if(u!=v)vec.push_back(v),edg.push_back({u,v});
    }
    sort(vec.begin(),vec.end(),[](int x,int y){
      return HPD::dfn[x]<HPD::dfn[y];
    });
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    static int st[maxn];int top=0,lst_o=-1,anc;ano=vec;
    for(int u:ano){
      if(lst_o!=Tarjan::find(u)){
        rep(i,1,top-1)add(st[i],st[i+1]);top=0;
      }
      if(top&&(anc=HPD::qlca(st[top],u))!=st[top]){
        for(;top>1&&HPD::dep[anc]<HPD::dep[st[top-1]];top--){
          add(st[top-1],st[top]);
        }
        if(top==1||anc!=st[top-1]){
          Tarjan_Q::h[anc]=0,add(anc,st[top]),st[top]=anc,vec.push_back(anc);
        }else add(anc,st[top--]);
      }
      st[++top]=u,lst_o=Tarjan::find(u);
    }
    rep(i,1,top-1)add(st[i],st[i+1]);
    for(pii p:edg)add(p.first,p.second);
    for(int u:vec)if(!Tarjan_Q::dfn[u])Tarjan_Q::tarjan(u,0);
    for(int u:vec)if(!Tarjan_Q::bl[u])Tarjan_Q::tot++,Tarjan_Q::dfs(u);
    int all=-1,asf=1;
    for(int u:nod){
      int x=Tarjan_Q::bl[u];
      if(all==-1)all=x;
      else if(all!=x){
        asf=0;break;
      }
    }
    for(int u:vec)Tarjan_Q::dfn[u]=Tarjan_Q::low[u]=Tarjan_Q::h[u]=Tarjan_Q::bl[u]=0;
    rep(i,1,Tarjan_Q::ecnt)Tarjan_Q::G[i].nxt=Tarjan_Q::G[i].to=Tarjan_Q::cut[i]=0;
    puts(asf?(lastans+=_)%=tpn,"YES":"NO");
  }
  return 0;
}