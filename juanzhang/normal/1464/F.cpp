#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int read(){
  int x=0;char c=getchar();
  while(c<48)c=getchar();
  while(c>47)x=x*10+(c^48),c=getchar();
  return x;
}

typedef pair<int,int>pr;
const int maxn=2e5+10;
int n,q;

vector<int>E[maxn];
int fa[maxn],sz[maxn],dep[maxn],top[maxn],son[maxn],dnow,dfn[maxn];

vector<int>pat[maxn];

void dfs1(int u,int f){
  fa[u]=f,sz[u]=1,dep[u]=dep[f]+1,son[u]=0;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),sz[u]+=sz[v];
    if(sz[son[u]]<sz[v])son[u]=v;
  }
}
void dfs2(int u,int tp){
  top[u]=tp,pat[tp].push_back(u),dfn[u]=++dnow;
  if(son[u])dfs2(son[u],tp);
  for(int v:E[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
}

int qlca(int u,int v){
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
  }
  return dep[u]<dep[v]?u:v;
}
int jump(int u,int k){
  for(;u;u=fa[top[u]]){
    int le=dep[u]-dep[top[u]];
    if(k<=le)return pat[top[u]][le-k];
    k-=le+1;
  }
  return 1;
}

struct path{
  int u,v,lca;
  bool operator<(const path&o)const{
    return dep[lca]<dep[o.lca]||(dep[lca]==dep[o.lca]&&(u<o.u||(u==o.u&&v<o.v)));
  }
};

int val[maxn],dis[maxn];
multiset<path>S;
multiset<int,greater<int>>poi[maxn],sub[maxn];

int c[maxn];
void add(int pos,int v){
  for(;pos<=n;pos+=pos&-pos)c[pos]+=v;
}
int query(int pos){
  int res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;
}

int dt;

struct SGT{
  int tr[maxn<<2];
  void upd(int k,int v){
    for(tr[k+=dt-1]=v;k>>=1;tr[k]=max(tr[k<<1],tr[k<<1|1]));
  }
  int query(int l,int r){
    l+=dt-1,r+=dt-1;
    int res=max(tr[l],tr[r]);
    while(l/2!=r/2){
      if(~l&1){
        res=max(res,tr[l^1]);
      }
      if(r&1){
        res=max(res,tr[r^1]);
      }
      l>>=1,r>>=1;
    }
    return res;
  }
}tree,orz;

int main(){
  memset(orz.tr,-0x3f,sizeof orz.tr);
  memset(tree.tr,-0x3f,sizeof tree.tr);
  memset(val,-0x3f,sizeof val);
  n=read(),q=read(),dt=1<<18;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  dfs1(1,0),dfs2(1,1);
  while(q--){
    int op=read();
    if(op==3){
      int k=read();bool asf=1;
      path dw=*S.rbegin();
      int cur=jump(dw.lca,k),gt=jump(cur,k);
      if(query(dfn[gt]+sz[gt]-1)-query(dfn[gt]-1)!=(int)S.size()){
        asf=0;
      }
//      printf("#%d\n",cur);
      for(;cur&&asf&&k>=0;cur=fa[cur]){
        int le=dep[cur]-dep[top[cur]];
        if(cur!=top[cur]&&tree.query(dfn[top[cur]],dfn[fa[cur]])>k-dep[cur]){
          asf=0;break;
        }
//        rep(i,1,le){
//          int u=pat[top[cur]][le-i];
//          if(val[u]-dep[u]*2>k-dep[cur]){
////            printf("!%d\n",u);
//            asf=0;break;
//          }
//        }
        k-=le+1;
        cur=top[cur];
        if(cur==1)break;
        int ano=son[fa[cur]];
        if(orz.query(dfn[ano],dfn[ano]+sz[ano]-1)-dep[fa[cur]]>k){
          asf=0;break;
        }
        if(val[fa[cur]]-dep[fa[cur]]>k){
          auto it=sub[fa[cur]].begin();
          if(!poi[cur].empty()&&*poi[cur].begin()==*it){
            if(++it!=sub[fa[cur]].end()){
              if(*it-dep[fa[cur]]>k){
                asf=0;break;
              }
            }
          }else{
            asf=0;break;
          }
        }
      }
      puts(asf?"Yes":"No");
    }else{
      static int cnt[maxn];
      int u=read(),v=read(),lca=qlca(u,v),w=op==1?1:-1;
      if(u>v)swap(u,v);
      path p={u,v,lca};
      add(dfn[u],w),add(dfn[v],w),add(dfn[lca],-w);
      if(op==1){
        if(!cnt[lca]++)orz.upd(dfn[lca],dep[lca]);
        S.insert(p);
        int cur=lca;
        while(1){
          cur=top[cur];
          if(cur==1)break;
          int lst=poi[cur].empty()?-1:*poi[cur].begin();
          poi[cur].insert(dep[lca]);
          cur=fa[cur];
          if(lst<dep[lca]){
            auto&se=sub[cur];
            if(lst!=-1)se.erase(se.find(lst));
            se.insert(dep[lca]);
            if(val[cur]<dep[lca])val[cur]=dep[lca],tree.upd(dfn[cur],val[cur]-2*dep[cur]);
          }
        }
      }else{
        if(!--cnt[lca])orz.upd(dfn[lca],-1e9);
        S.erase(S.find(p));
        int cur=lca;
        while(1){
          cur=top[cur];
          if(cur==1)break;
          auto&kk=poi[cur];
          int lst=*kk.begin();
          kk.erase(kk.find(dep[lca]));
          cur=fa[cur];
          if(kk.empty()||lst>*kk.begin()){
            sub[cur].erase(sub[cur].find(lst));
            if(!kk.empty())sub[cur].insert(*kk.begin());
            int goal=sub[cur].empty()?-1e9:*sub[cur].begin();
            if(val[cur]!=goal)val[cur]=goal,tree.upd(dfn[cur],val[cur]-2*dep[cur]);
          }
        }
      }
    }
//    rep(i,1,n)printf("(%d : %d)\n",i,val[i]);
  }
  return 0;
}