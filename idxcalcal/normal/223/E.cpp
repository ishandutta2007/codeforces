#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef vector<int> poly;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define rez resize
#define ppp pop_back
#define fi first
#define se second
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans,f;
  static char ch;
  for(ans=0,f=1,ch=gc();!isdigit(ch);f^=ch=='-',ch=gc());
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
namespace modular {
  const int mod=998244353;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
} using namespace modular;
const int N=1e5+5;
struct pt {
  int x,y;
  pt(int x=0,int y=0):x(x),y(y) {}
  inline pt operator+(pt a) { return pt(x+a.x,y+a.y); }
  inline pt operator-(pt a) { return pt(x-a.x,y-a.y); }
  inline ll operator*(pt a) { return (ll)x*a.y-(ll)y*a.x; }
  inline bool operator<(const pt&a) const { return x^a.x?x<a.x:y<a.y; }
} a[N];
int fl[N<<1],tot=-1;
struct edge {
  double ang;
  int v,id;
  inline bool operator<(const edge&a) const { return ang<a.ang; }
};
vector<edge> e[N];
inline void addedge(int u,int v) {
  pt cur=a[v]-a[u];
  e[u].pb((edge) { atan2(cur.y,cur.x),v,++tot } );
}
inline void _add(int u,int v) { addedge(u,v),addedge(v,u); }
int n,m;
pii E[N];
vector<ll> pre1[N],pre2[N];
int S;
map<int,int> edge_id[N];
bool vs[N];
int dfs(int p) {
  vs[p]=1;
  int res=1;
  for(ri i=0,v;i<e[p].size();++i) if(!vs[v=e[p][i].v]) res+=(fl[e[p][i].id^1]=dfs(v));
  return res;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1;i<=m;++i) E[i].fi=read(),E[i].se=read();
  for(ri i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
  int ps=1;
  for(ri i=2;i<=n;++i) if(a[i]<a[ps]) ps=i;
  --(a[0]=a[ps]).x;
  _add(0,ps);
  for(ri i=1;i<=m;++i) _add(E[i].fi,E[i].se);
  for(ri i=0;i<=n;++i) {
    sort(e[i].begin(),e[i].end());
    for(ri j=0;j<e[i].size();++j) edge_id[i][e[i][j].v]=j;
  }
  dfs(0);
  for(ri i=0;i<=n;++i) {
    pre1[i].rez(e[i].size()),pre2[i].rez(e[i].size());
    pre1[i][0]=fl[e[i][0].id^1],pre2[i][0]=fl[e[i][0].id];
    for(ri j=1;j<e[i].size();++j) {
      pre1[i][j]=pre1[i][j-1]+fl[e[i][j].id^1];
      pre2[i][j]=pre2[i][j-1]+fl[e[i][j].id];
    }
  }
  for(ri In,Out,tt=read(),K;tt;--tt) {
    K=read();
    poly idd(K+1);
    for(ri i=0;i<K;++i) idd[i]=read();
    idd[K]=idd[0];
    ll ss=0;
    for(ri i=0;i<K;++i) ss+=a[idd[i]]*a[idd[i+1]];
    if(ss<0) idd.ppp(),reverse(idd.begin(),idd.end()),idd.pb(idd[0]);
    In=Out=0;
    #define Nxt(x) ((x)==K-1?0:x+1)
    for(ri len,ql,qr,pr=K-1,sf=1,i=0;i<K;++i,pr=Nxt(pr),sf=Nxt(sf)) {
      len=e[idd[i]].size();
      ql=edge_id[idd[i]][idd[pr]],qr=edge_id[idd[i]][idd[sf]];
      ql=ql==len-1?0:ql+1;
      if(ql==qr) continue;
      qr=qr?qr-1:len-1;
      if(ql<=qr) {
        In+=pre2[idd[i]][qr]-(ql?pre2[idd[i]][ql-1]:0);
        Out+=pre1[idd[i]][qr]-(ql?pre1[idd[i]][ql-1]:0);
      }
      else {
        In+=pre2[idd[i]].back()-pre2[idd[i]][ql-1]+pre2[idd[i]][qr];
        Out+=pre1[idd[i]].back()-pre1[idd[i]][ql-1]+pre1[idd[i]][qr];
      }
    }
    cout<<In-Out<<'\n';
  }
  return 0;
}