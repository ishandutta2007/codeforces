#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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
void write(int x){
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=6e5+10;
int n,q;

int pre[maxn],bl[maxn];

namespace ST{
  int lg[maxn];
  pii st[20][maxn/2];
  void build(){
    rep(i,1,n)st[0][i]=pii(pre[i],i);
    rep(i,2,n)lg[i]=lg[i>>1]+1;
    rep(i,1,19)rep(j,1,(n-(1<<i))+1){
      st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
  }
  int query(int l,int r){
    int k=lg[r-l+1];
    return min(st[k][l],st[k][r-(1<<k)+1]).first;
  }
}

char S[maxn],T[maxn];

struct Querys{
  int op,l,r;
}Q[maxn];

int tot;
vi E[maxn];int deg[maxn];
void build(int l,int r,int fa){
  if(l>r)return;
  int lef=l,rig=r,pos=-1;
  while(lef<=rig){
    int mid=(lef+rig)/2;
//    printf("(%d %d) %d\n",lef,rig,mid);
    if(ST::query(l,mid)<=pre[l-1]){
      rig=(pos=mid)-1;
    }else{
      lef=mid+1;
    }
  }
//  printf("#%d %d\n",pos,pre[l-1]);
//  return;
  tot++;
  bl[l]=bl[pos]=tot;
//  printf("(%d %d) : %d %d\n",l,r,fa,tot);
  E[fa].push_back(tot);
  build(l+1,pos-1,tot);
  build(pos+1,r,fa);
}

map<int,int>mp[maxn];

struct BIT{
  vector<ll>c;int N;
  void init(int sz){
    N=sz+1,c=vector<ll>(N+1,0);
  }
  void add(int pos,ll x){
    for(pos++;pos<=N;pos+=pos&-pos)c[pos]+=x;
  }
  ll query(int pos){
    ll res=0;for(pos++;pos;pos&=pos-1)res+=c[pos];return res;
  }
}bit_s[maxn],bit_c[maxn],seg;

int rt[maxn];
int fa[maxn],sz[maxn],dep[maxn],son[maxn],top[maxn],dfn[maxn],seq[maxn];
ll tpas[maxn];
void dfs1(int u,int f){
  tpas[u]=1ll*E[u].size()*(E[u].size()-1)/2+1;
  fa[u]=f,sz[u]=1,dep[u]=dep[f]+1;
  int id=0;
  bit_s[u].init(E[u].size());
  bit_c[u].init(E[u].size());
  for(int v:E[u])if(v!=f){
    dfs1(v,u),sz[u]+=sz[v];
    tpas[u]+=tpas[v];
    bit_c[u].add(id,1);
    bit_s[u].add(id,tpas[v]);
    if(sz[son[u]]<sz[v])son[u]=v;
    id++;
  }
//  printf("%d : %lld\n",u,tpas[u]);
}
void dfs2(int u,int tp){
  static int now;
  dfn[u]=++now,seq[now]=u;
  top[u]=tp;
  if(son[u])dfs2(son[u],tp);
  for(int v:E[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
}

void solve(){
  scanf("%d%d%s",&n,&q,S+1);
  int len=0;
  static int st[maxn];
  rep(i,1,n){
    pre[i]=pre[i-1]+(S[i]=='('?1:-1);
    if(S[i]=='('){
      st[++len]=i;
    }else{
      if(len&&S[st[len]]=='('){
        len--;
      }else{
        st[++len]=i;
      }
    }
  }
  ST::build();
  st[len+1]=n+1;
  tot=1;
  rep(i,1,len+1){
    int l=st[i-1]+1,r=st[i]-1;
    if(l<=r){
//      printf("(%d %d)\n",l,r);
      build(l,r,1);
    }
  }
  rep(i,1,tot){
    deg[i]=E[i].size();
    rep(j,0,E[i].size()-1){
      mp[i][E[i][j]]=j;
    }
  }
  dfs1(1,0),dfs2(1,1);
  seg.init(n);
  while(q--){
    int op=read(),l=read(),r=read();
    if(op==1){
      int u=bl[l];
      ll x=deg[fa[u]]--;
      seg.add(dfn[u],-1);
      seg.add(dfn[fa[u]],-x+1);
      bit_c[fa[u]].add(mp[fa[u]][u],-1);
      if(u!=son[fa[u]]){
        bit_s[fa[u]].add(mp[fa[u]][u],-1);
      }
      u=fa[u];
      for(;top[u]!=1;u=fa[top[u]]){
        bit_s[fa[top[u]]].add(mp[fa[top[u]]][top[u]],-x);
      }
    }else{
      ll ans=0;
      int u=bl[l],v=bl[r];
      int lef=mp[fa[u]][u],rig=mp[fa[v]][v];
      ans=bit_s[fa[u]].query(rig)-(lef?bit_s[fa[u]].query(lef-1):0);
      int ctt=bit_c[fa[u]].query(rig)-(lef?bit_c[fa[u]].query(lef-1):0);
      ans+=1ll*ctt*(ctt-1)/2;
      int w=son[fa[u]];
      int pos=mp[fa[u]][w];
      if(lef<=pos&&pos<=rig){
        ans+=seg.query(dfn[w]+sz[w]-1)-seg.query(dfn[w]-1);
      }
      printf("%lld\n",ans);
    }
  }
//  memcpy(T,S,sizeof S);
//  rep(i,1,q){
//    Q[i].op=read(),Q[i].l=read(),Q[i].r=read();
//    if(Q[i].op==1){
//      T[Q[i].l]=T[Q[i].r]='.';
//    }
//  }

}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}
/*
9 2
)(()())()
1 3 4
2 2 7

*/