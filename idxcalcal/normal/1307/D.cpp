#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
#define y2 cyktxdy
typedef long long ll;
typedef vector<int> poly;
typedef vector<ll> Poly;
typedef pair<int,int> pii;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1,inf=0x3f3f3f3f;
const ll Inf=1e18;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  bool f=1;
  char ch=gc();
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  ll ans=0;
  bool f=1;
  char ch=gc();
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline int Read(char*s) {
  int top=0;
  char ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++top]=ch,ch=gc();
  return top;
}
namespace modular {
  const int mod=1e9+7;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
}
using namespace modular;
template<typename T>inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T>inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T>inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
const double eps=1e-8;
//Math
/*
int fac[N],ifac[N],inv[N];
inline int C(int n,int m) { return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m])); }
inline void init_fac(int up) {
  fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
  for(ri i=2;i<=up;++i) {
    fac[i]=mul(fac[i-1],i);
    inv[i]=mul(inv[mod-mod/i*i],mod-mod/i);
    ifac[i]=mul(ifac[i-1],inv[i]);
  }
}
*/
const int N=2e5+5;
vector<int>e[N];
int a[N],n,m,K,dis1[N],dis2[N],suf[N];
bool vs[N];
inline bool cmp(int x,int y) { return dis1[x]==dis1[y]?dis2[x]>dis2[y]:dis1[x]<dis1[y]; }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),K=read();
  for(ri i=1;i<=K;++i) a[i]=read();
  for(ri i=1,u,v;i<=m;++i) {
  	u=read(),v=read();
  	e[u].pb(v),e[v].pb(u);
	}
	queue<int>q;
	q.push(1),vs[1]=1;
	while(q.size()) {
		int x=q.front();
		q.pop();
		for(ri i=0,v;i<(int)e[x].size();++i) {
			if(vs[v=e[x][i]]) continue;
			vs[v]=1,dis1[v]=dis1[x]+1,q.push(v);
		}
	}
	sort(a+1,a+K+1,cmp);
	memset(vs,0,sizeof(vs));
	q.push(n),vs[n]=1;
	while(q.size()) {
		int x=q.front();
		q.pop();
		for(ri i=0,v;i<(int)e[x].size();++i) {
			if(vs[v=e[x][i]]) continue;
			vs[v]=1,dis2[v]=dis2[x]+1,q.push(v);
		}
	}
	for(ri i=n;i;--i) suf[i]=max(suf[i+1],dis2[a[i]]);
	int res=0;
	for(ri i=1;i<K;++i) ckmax(res,dis1[a[i]]+1+suf[i+1]);
	cout<<min(res,dis1[n]);
  return 0;
}