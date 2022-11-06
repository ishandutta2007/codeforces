#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline int Read(char*s) {
  int top=0;
  char ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++top]=ch,ch=gc();
  return top;
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
}
using namespace modular;
const int N=5005,lm=5000;
int mnpr[N],pri[N],rk[N],tot=0,ps[N],cnt[N],n,all=0;
bool vs[N];
vector<int>pr[N];
vector<int>fa,dep,siz;
inline void init() {
  for(ri x,i=2;i<=lm;++i) {
    if(!vs[i]) pri[++tot]=i;
    for(ri j=1,up=lm/i;j<=tot&&pri[j]<=up;++j) {
      vs[i*pri[j]]=1;
      if(i==i/pri[j]*pri[j]) break;
    }
    x=i;
    for(ri j=1;j<=tot&&x>1;++j) while(x==x/pri[j]*pri[j]) x/=pri[j],pr[i].pb(j);
  }
  fa.pb(0),dep.pb(0),siz.pb(0);
  for(ri tmp,cur=0,mxpr,i=2;i<=lm;++i) {
    mxpr=pr[i].back();
    for(ri j=1;j<mxpr;++j) for(ri k=1;k<=cnt[j];++k) cur=fa[cur];
    tmp=cnt[mxpr];
    for(ri j=(int)pr[i].size()-1;~j;--j) ++cnt[pr[i][j]];
    for(ri j=mxpr;j;--j) for(ri k=1,up=j==mxpr?cnt[j]-tmp:cnt[j];k<=up;++k) {
      dep.pb(dep[cur]+1);
      siz.pb(0),fa.pb(cur),cur=++all;
    }
    ps[i]=cur;
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  init();
  ll sum=0;
  n=read();
  for(ri x,i=1;i<=n;++i) {
    ++siz[ps[x=read()]];
    sum+=dep[ps[x]];
  }
  for(ri i=all;i;--i) siz[fa[i]]+=siz[i];
  int rt=0;
  for(ri i=1;i<=all;++i) if(siz[i]*2>=n) rt=i;
  while(rt) sum+=n-siz[rt]*2,rt=fa[rt];
  cout<<sum;
  return 0;
}