#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=1e5+10,P=1e9+7;
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}
int n,q,ans[maxn];

bitset<10000010>ntp;
int ptt,pri[666000];
void sieve(){
  int N=1e7;
  rep(i,2,N){
    if(!ntp[i])pri[++ptt]=i;
    rep(j,1,ptt){
      int x=i*pri[j];
      if(x>N)break;
      ntp[x]=1;
      if(i%pri[j]==0)break;
    }
  }
}

vi E[maxn];
int fa[maxn],sz[maxn],son[maxn],top[maxn],dep[maxn],dfn[maxn];
void dfs1(int u,int f){
  sz[u]=1,fa[u]=f,dep[u]=dep[f]+1;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),sz[u]+=sz[v];if(sz[son[u]]<sz[v])son[u]=v;
  }
}
void dfs2(int u,int tp){
  static int now;
  dfn[u]=++now,top[u]=tp;
  if(son[u])dfs2(son[u],tp);
  for(int v:E[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
}
int qlca(int u,int v){
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
  }
  return dep[u]<dep[v]?u:v;
}
int tot;
struct node{
  int x,p,u;
}dat[maxn*16];
struct Querys{
  int u,v,anc;
}Q[maxn];
int zzh[maxn];
struct BIT{
  int c[maxn];
  void add(int pos,int x){
    for(;pos<=n;pos+=pos&-pos)c[pos]+=x;
  }
  int query(int pos){
    int res=0;
    for(;pos;pos&=pos-1)res+=c[pos];
    return res;
  }
}bit;
void add_sub(int u,int x){
  bit.add(dfn[u],x),bit.add(dfn[u]+sz[u],-x),zzh[u]+=x;
}
int query_l(int id){
  return bit.query(dfn[Q[id].u])+bit.query(dfn[Q[id].v])-bit.query(dfn[Q[id].anc])*2+zzh[Q[id].anc];
}

void solve(){
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read();
    E[u].push_back(v),E[v].push_back(u);
  }
  dfs1(1,0),dfs2(1,1);
  rep(u,1,n){
    int x=read();
    rep(i,1,452){
      int y=pri[i];
      if(x%y==0){
        int c=0;
        do{x/=y,++c;}while(x%y==0);
        dat[++tot]={y,c,u};
      }
    }
    if(x>1)dat[++tot]={x,1,u};
  }
  cin>>q;
  rep(j,1,q){
    Q[j].u=read(),Q[j].v=read(),Q[j].anc=qlca(Q[j].u,Q[j].v),ans[j]=1;
    int x=read();
    rep(i,1,452){
      int y=pri[i];
      if(x%y==0){
        int c=0;
        do{x/=y,++c;}while(x%y==0);
        dat[++tot]={y,c,-j};
      }
    }
    if(x>1)dat[++tot]={x,1,-j};
  }
  sort(dat+1,dat+tot+1,[](node P,node Q){
    return P.x<Q.x||(P.x==Q.x&&(P.p<Q.p||(P.p==Q.p&&P.u<Q.u)));
  });
  rep(lef,1,tot){
    int rig=lef;
    while(dat[rig+1].x==dat[lef].x)rig++;
//    printf("(%d %d)\n",lef,rig);
    rep(i,lef,rig){
      auto tmp=dat[i];
      if(tmp.u>0){
        add_sub(tmp.u,tmp.p);
      }else{
        int id=-tmp.u;
        ans[id]=1ll*ans[id]*qp(tmp.x,query_l(id))%P;
      }
    }
    rep(i,lef,rig){
      auto tmp=dat[i];
      if(tmp.u>0){
        add_sub(tmp.u,-tmp.p);
      }
    }
    per(i,rig,lef){
      auto tmp=dat[i];
      if(tmp.u>0){
        add_sub(tmp.u,1);
      }else{
        int id=-tmp.u;
        ans[id]=1ll*ans[id]*qp(tmp.x,tmp.p*query_l(id))%P;
      }
    }
    per(i,rig,lef){
      auto tmp=dat[i];
      if(tmp.u>0){
        add_sub(tmp.u,-1);
      }
    }
    lef=rig;
  }
  rep(i,1,q)printf("%d\n",ans[i]);
}

signed main(){
  sieve();
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}