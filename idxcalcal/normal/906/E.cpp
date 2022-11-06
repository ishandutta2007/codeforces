#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1,inf=0x3f3f3f3f,blo=(1<<15)-1;
const ll Inf=1e18;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=1e6+5;
int n,m;
char s[N],A[N],B[N];
namespace pam {
  int l,last,tot,son[N][26],fail[N],len[N],anc[N];
  inline void init() { len[1]=-1,anc[1]=fail[0]=1,l=0,last=tot=1; }
  inline int getfail(int x) {
    while(s[l-len[x]-1]!=s[l]) x=fail[x];
    return x;
  }
  inline int Det(int x) { return len[x]-len[fail[x]]; }
  inline void insert(int x) {
    ++l;
    int t=getfail(last);
    if(!son[t][x]) {
      len[++tot]=len[t]+2;
      fail[tot]=son[getfail(fail[t])][x];
      son[t][x]=tot;
      anc[tot]=fail[tot]>1&&Det(tot)==Det(fail[tot])?anc[fail[tot]]:tot;
    }
    last=son[t][x];
  }
}
int f[N],g[N],F[N],G[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  scanf("%s",A+1),scanf("%s",B+1),m=strlen(A+1),n=0;
  for(ri i=1;i<=m;++i) s[++n]=A[i],s[++n]=B[i];
  F[0]=F[1]=inf;
  pam::init();
  for(ri i=1;i<=n;++i) {
    f[i]=inf,pam::insert(s[i]-'a');
    for(ri p=pam::last;p>1;p=pam::fail[pam::anc[p]]) {
      G[p]=i-pam::len[pam::anc[p]],F[p]=f[G[p]]+1;
      if(pam::anc[p]!=p&&F[pam::fail[p]]<F[p]) F[p]=F[pam::fail[p]],G[p]=G[pam::fail[p]];
      if((!(i&1))&&f[i]>F[p]) f[i]=F[p],g[i]=G[p];
    }
    if((!(i&1))&&s[i]==s[i-1]&&f[i]>f[i-2]) f[i]=f[i-2],g[i]=i-2;
  }
  if(f[n]==inf) return puts("-1"),0;
  cout<<f[n]<<'\n';
  for(ri p=n;p;p=g[p]) if(p-g[p]>2) cout<<g[p]/2+1<<' '<<p/2<<'\n';
  return 0;
}