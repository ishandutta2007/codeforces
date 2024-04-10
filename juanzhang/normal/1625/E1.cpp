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
vi E[maxn];
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

namespace fhq{

int tot,rnd[maxn*2],ch[maxn*2][2],val[maxn*2];ll vvv[maxn*2],sum[maxn*2];

int newnode(int v,ll w){
  rnd[++tot]=Rnd(),val[tot]=v,vvv[tot]=sum[tot]=w;
  return tot;
}

void mt(int k){
  int x=ch[k][0],y=ch[k][1];
  sum[k]=sum[x]+sum[y]+vvv[k];
}

void split(int k, int v, int& x, int& y) {
  if (!k) {
    x = y = 0;
    return;
  }
  if (val[k] <= v) {
    x = k, split(ch[k][1], v, ch[k][1], y);
  } else {
    y = k, split(ch[k][0], v, x, ch[k][0]);
  }
  mt(k);
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  int res;
  if (rnd[x] < rnd[y]) {
    res = x, ch[x][1] = merge(ch[x][1], y);
  } else {
    res = y, ch[y][0] = merge(x, ch[y][0]);
  }
  return mt(res), res;
}

void add(int&rt,int v,ll w){
  int x,y;
  split(rt,v,x,y);
  rt=merge(x,merge(newnode(v,w),y));
}
ll query(int&rt,int v){
  int x,y;
  split(rt,v,x,y);
  ll res=sum[x];
  rt=merge(x,y);
  return res;
}

}

struct BIT{
  ll c[maxn];
  void add(int pos,ll x){
    for(;pos<maxn;pos+=pos&-pos)c[pos]+=x;
  }
  ll query(int pos){
    ll res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;
  }
}S0,S1;
void add(int l,int r,ll x){
  S0.add(l,x),S1.add(l,l*x);
}
ll _query(int pos){
  return (pos+1)*S0.query(pos)-S1.query(pos);
}
ll query(int l,int r){
  return _query(r)-_query(l);
}

int rt[maxn];
int fa[maxn],sz[maxn],dep[maxn],son[maxn],top[maxn],dfn[maxn],seq[maxn];
ll tpas[maxn];
void dfs1(int u,int f){
  tpas[u]=1ll*E[u].size()*(E[u].size()-1)/2+1;
  fa[u]=f,sz[u]=1,dep[u]=dep[f]+1;
  int id=0;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),sz[u]+=sz[v];
    tpas[u]+=tpas[v];
    fhq::add(rt[u],id,tpas[v]);
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

void add_line(int u,ll w){
  for(;u;u=fa[top[u]]){
    add(dfn[top[u]],dfn[u],w);
  }
}

void solve(){
  scanf("%d%d%s",&n,&q,S+1);
  int top=0;
  static int st[maxn];
  rep(i,1,n){
    pre[i]=pre[i-1]+(S[i]=='('?1:-1);
    if(S[i]=='('){
      st[++top]=i;
    }else{
      if(top&&S[st[top]]=='('){
        top--;
      }else{
        st[++top]=i;
      }
    }
  }
  ST::build();
  st[top+1]=n+1;
  tot=1;
  rep(i,1,top+1){
    int l=st[i-1]+1,r=st[i]-1;
    if(l<=r){
//      printf("(%d %d)\n",l,r);
      build(l,r,1);
    }
  }
  rep(i,1,tot){
    rep(j,0,E[i].size()-1){
      mp[i][E[i][j]]=j;
    }
  }
  dfs1(1,0),dfs2(1,1);
  while(q--){
    int op=read(),l=read(),r=read();
    if(op==1){
//      int u=bl[l];

    }else{
      ll ans=0;
      int u=bl[l],v=bl[r];
      int lef=mp[fa[u]][u],rig=mp[fa[v]][v];
      ans=fhq::query(rt[fa[u]],rig)-(lef?fhq::query(rt[fa[u]],lef-1):0);
      int ctt=rig-lef+1;
      ans+=1ll*ctt*(ctt-1)/2;
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