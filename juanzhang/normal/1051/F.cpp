#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,popcnt,abm,mmx,avx")
//#pragma comment(linker,"/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(ll x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=1e5+10;
int n,m,q;

int par[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

struct edge{
  int u,v,w;
};

struct edges{
  int nxt,to;ll w;
};

namespace Tree{

int ecnt=1,h[maxn];
edges E[maxn<<1];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
int fa[maxn],sz[maxn],dep[maxn],top[maxn],son[maxn],dfn[maxn];ll dis[maxn];
void dfs1(int u,int f){
  fa[u]=f,sz[u]=1,dep[u]=dep[f]+1;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f){
      dis[v]=dis[u]+E[i].w;
      dfs1(v,u);
      sz[u]+=sz[v];
      if(sz[son[u]]<sz[v])son[u]=v;
    }
  }
}
void dfs2(int u,int tp){
  static int now;
  top[u]=tp,dfn[u]=++now;
  if(son[u])dfs2(son[u],tp);
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=fa[u]&&v!=son[u])dfs2(v,v);
  }
}
int qlca(int u,int v){
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
  }
  return dep[u]<dep[v]?u:v;
}
ll qdis(int u,int v){
  return dis[u]+dis[v]-2*dis[qlca(u,v)];
}

}

bool ont[maxn];

vector<int>vir,nod;
int mp[maxn],arr[maxn];

ll val[100][100];

namespace PlanarG{

int fa[maxn];
vector<int>son[maxn];

int ecnt=1,h[maxn];
edges E[maxn<<1];
void addline(int u,int v,ll w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
void add(int u,int v,ll w,bool flg=1){
//  printf("(%d %d %d)\n",u,v,w);
  ont[u]=ont[v]=1;
  if(flg)son[u].push_back(v),fa[v]=u;
  addline(u,v,w),addline(v,u,w);
}

ll dis[maxn];

// orzkw

int SZ;
int id[maxn*4];

void upd(int x,ll v){
  int k=x+SZ-1;
  id[k]=x,dis[x]=v;
  while((k>>=1)&&dis[id[k]]>v)id[k]=x;
}
void del(int x){
  int k=x+SZ-1,cur=0;
  id[k]=0;
  while(id[k>>1]==x)cur=id[k>>1]=dis[id[k^1]]<dis[cur]?id[k^1]:cur,k>>=1;
}

void dijkstra(int S){
  SZ=1;
  while(SZ<=n)SZ<<=1;
  dis[0]=1e18;
  for(int u:vir)dis[u]=1e18;
  upd(S,0);
  while(1){
    int u=id[1];
    if(!u)break;
//    printf("(%d %lld)\n",u,dis[u]);
    del(u);
    for(int i=h[u];i;i=E[i].nxt){
      int v=E[i].to;
      ll d=dis[u]+E[i].w;
      if(dis[v]>d)upd(v,d);
    }
  }
}

}

bool mark[maxn];
vector<pair<int,ll>>zzh[maxn];

void bfs(int S){
  static int Q[maxn],vis[maxn];
  static ll dis[maxn];
  int l=1,r=1;Q[1]=S,vis[S]=S,dis[S]=0;
  while(l<=r){
    int u=Q[l++];
    zzh[u].push_back({mp[S],dis[u]});
    for(int i=Tree::h[u];i;i=Tree::E[i].nxt){
      int v=Tree::E[i].to;
      if(!mark[v]&&vis[v]!=S){
        vis[v]=S;
        Q[++r]=v;
        dis[v]=dis[u]+Tree::E[i].w;
      }
    }
  }
}

void solve(){
  n=read(),m=read();
  rep(i,1,n)par[i]=i;
  vector<edge>orzjk;
  rep(i,1,m){
    int u=read(),v=read(),w=read();
    if(find(u)!=find(v)){
      par[find(u)]=find(v);
      Tree::addline(u,v,w);
      Tree::addline(v,u,w);
    }else{
      nod.push_back(u);
      nod.push_back(v);
      orzjk.push_back({u,v,w});
    }
  }
  Tree::dfs1(1,0);
  Tree::dfs2(1,1);
  sort(nod.begin(),nod.end(),[](int x,int y){
    return Tree::dfn[x]<Tree::dfn[y];
  });
  nod.erase(unique(nod.begin(),nod.end()),nod.end());
  static int st[maxn];
  int top=1;st[1]=1;vir.push_back(1);
  for(int u:nod){
    if(u==1){
      continue;
    }
    vir.push_back(u);
    int tp=Tree::qlca(st[top],u);
    if(tp!=st[top]){
      while(top>1&&Tree::dfn[tp]<Tree::dfn[st[top-1]]){
        PlanarG::add(st[top],st[top-1],Tree::dis[st[top]]-Tree::dis[st[top-1]]);
        top--;
      }
      if(tp==st[top-1]){
        PlanarG::add(st[top],st[top-1],Tree::dis[st[top]]-Tree::dis[st[top-1]]);
        top--;
      }else{
        PlanarG::add(st[top],tp,Tree::dis[st[top]]-Tree::dis[tp]);
        st[top]=tp;
        vir.push_back(tp);
      }
    }
    st[++top]=u;
  }
  while(top>1)PlanarG::add(st[top],st[top-1],Tree::dis[st[top]]-Tree::dis[st[top-1]]),top--;
  for(edge e:orzjk)PlanarG::add(e.u,e.v,e.w,0);
  int now=0;
  for(int u:vir)mp[u]=++now,arr[now]=u,mark[u]=1;
  for(int S:vir){
    PlanarG::dijkstra(S);
    for(int u:vir)val[mp[S]][mp[u]]=PlanarG::dis[u];
    bfs(S);
  }
  q=read();
  while(q--){
    int u=read(),v=read();
    ll ans=Tree::qdis(u,v);
    for(auto p:zzh[u])for(auto q:zzh[v])chkmin(ans,val[p.first][q.first]+p.second+q.second);
    write(ans),pc(10);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}