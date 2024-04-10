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
const int N=3e5+5,inf=0x3f3f3f3f;
int n,m,siz[N][2],col[N],ft[N],res=0;
char s[N];
vector<int>id[N];
inline int find(int x) { int t=ft[x];return x^ft[x]?(ft[x]=find(ft[x]),col[x]^=col[t],ft[x]):x; }
inline void merge(int x,int y,int w) {
  int _x=find(x),_y=find(y);
  if(_x==_y) return;
  w^=col[x]^col[y];
  x=_x,y=_y;
  if(x>m) swap(x,y);
  res-=min(x>m?inf:siz[x][0],siz[x][1]);
  res-=min(y>m?inf:siz[y][0],siz[y][1]);
  ft[x]=y,col[x]^=w;
  siz[y][0]+=siz[x][w];
  siz[y][1]+=siz[x][w^1];
  res+=min(y>m?inf:siz[y][0],siz[y][1]);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  Read(s);
  for(ri i=1;i<=m;++i) for(ri tt=read();tt;--tt) id[read()].pb(i);
  for(ri i=1;i<=m+1;++i) ft[i]=i,siz[i][0]=1;
  for(ri i=1;i<=n;++i) {
    while((int)id[i].size()<2) id[i].pb(m+1);
    merge(id[i][0],id[i][1],(s[i]-'0')^1);
    cout<<res<<'\n';
  }
  return 0;
}