#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define pb push_back
#define rez resize
const ll Inf=1e18;
const int inf=1e9;
const int rlen=1<<20;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans,f;
  static char ch;
  ans=0,ch=gc(),f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
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
  inline int sqr(int a) { return (ll)a*a%mod; }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
} using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=5e5+5;
int n,m,id[N],ft1[N],sz[N],ft2[N],mx[N],Q=0,suf[N],tl[N];
bool is[N];
pii upd[N];
inline int find1(int x) { return x^ft1[x]?ft1[x]=find1(ft1[x]):x; }
inline int find2(int x) { return x^ft2[x]?ft2[x]=find2(ft2[x]):x; }
vector<int> e[N];
vector<pii> qy[N];
ll ans[N];
inline char getal() { static char ch;for(ch=gc();!isalpha(ch);ch=gc()); return ch; }
inline int idx(char x) {
  if(x=='U') return 1;
  if(x=='M') return 2;
  if(x=='A') return 3;
  if(x=='Z') return 4;
  return 5;
}
namespace bit {
  ll bt[N];
  inline int lbt(int x) { return x&-x; }
  inline void upd(int x,int v) { for(;x<=n;x+=lbt(x)) bt[x]+=v; }
  inline ll qry(int x) { ll res=0;for(;x;x^=lbt(x)) res+=bt[x];return res; }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1;i<=n;++i) tl[i]=i,ft1[i]=ft2[i]=i,sz[i]=1;
  queue<int> q;
  for(ri i=1,x,y,op;i<=m;++i) {
    op=idx(getal());
    if(op==1) {
      x=find1(read()),y=find1(read());
      if(x==y) continue;
      ft1[y]=x,sz[x]+=sz[y],suf[tl[x]]=y,tl[x]=tl[y];
    }
    else if(op==2) {
      x=find2(read()),y=find2(read());
      if(x==y) continue;
      e[x].pb(y),e[y].pb(x);
    }
    else if(op==3) x=find1(read()),upd[i]=pii(x,sz[x]);
    else if(op==4) {
      x=find2(read());
      q.push(x);
      while(q.size()) {
        int _x=q.front();
        q.pop();
        for(ri j=0,y;j<e[_x].size();++j) {
          y=find2(e[_x][j]);
          if(x^y) ft2[y]=x,q.push(y);
        }
        e[_x].rez(0);
      }
      mx[x]=i;
    }
    else x=read(),++Q,qy[i].pb(pii(Q,x)),qy[mx[find2(x)]].pb(pii(Q,-x));
  }
  int tot=0;
  for(ri i=1;i<=n;++i) if(find1(i)==i) for(ri p=i;p;p=suf[p]) id[p]=++tot;
  for(ri i=1,l,r;i<=m;++i) {
    if(upd[i].fi) {
      l=id[upd[i].fi],r=l+upd[i].se-1;
      bit::upd(l,upd[i].se);
      bit::upd(r+1,-upd[i].se);
    }
    for(ri j=0;j<qy[i].size();++j) {
      if(qy[i][j].se>0) ans[qy[i][j].fi]+=bit::qry(id[qy[i][j].se]);
      else ans[qy[i][j].fi]-=bit::qry(id[-qy[i][j].se]);
    }
  }
  for(ri i=1;i<=Q;++i) cout<<ans[i]<<'\n';
  return 0;
}