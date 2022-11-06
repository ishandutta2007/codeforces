#include<bits/stdc++.h>
#define ri register int
#define int long long
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
  bool f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  bool f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T> inline T gcd(T a,T b) { return b?gcd(b,a%b):a; }
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
const int N=1e5+5;
pii a[N],b[N],tmp[N],res[N<<1];
int len;
inline ll cross(pii a,pii b) { return (ll)a.fi*b.se-(ll)a.se*b.fi; }
inline pii operator+(pii a,pii b) { return pii(a.fi+b.fi,a.se+b.se); }
inline pii operator-(pii a,pii b) { return pii(a.fi-b.fi,a.se-b.se); }
inline int graham(pii*a,int m){
	static int top=0,q[N],len;
  top=0;
  sort(a+1,a+m+1);
	for(ri i=1;i<=m;++i){
		while(top>1&&cross((a[i]-a[q[top]]),(a[q[top]]-a[q[top-1]]))<=0)--top;
		q[++top]=i;
	}
  for(ri i=m-1;i;--i) {
    while(top>len&&cross((a[i]-a[q[top]]),(a[q[top]]-a[q[top-1]]))<=0) --top;
    q[++top]=i;
  }
  for(ri i=1;i<=top;++i) tmp[i]=a[q[i]];
  for(ri i=1;i<=top;++i) a[i]=tmp[i];
  return top;
}
inline void Msum(pii*a,pii*b,int n,int m){
  len=0;
  res[++len]=a[1]+b[1];
	int p1=1,p2=1;
	pii ta,tb;
	while(p1<n&&p2<m){
		ta=a[p1+1]-a[p1],tb=b[p2+1]-b[p2];
		if(cross(ta,tb)<=0) res[len+1]=res[len]+ta,++p1,++len;
		else res[len+1]=res[len]+tb,++p2,++len;
	}
	while(p1<n) res[len+1]=res[len]+ta,++p1,++len;
	while(p2<m) res[len+1]=res[len]+tb,++p2,++len;
  len=graham(res,len);
}
int n;
signed main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  for(ri i=1;i<=n;++i) a[i].fi=read(),a[i].se=read();
  if(n&1) return puts("NO"),0;
  for(ri i=1,x=2,j=n/2+1,y=j%n+1;i<=n;++i,j=j%n+1,x=x%n+1,y=y%n+1) {
    if((a[i]-a[x]).fi!=(a[y]-a[j]).fi||(a[i]-a[x]).se!=(a[y]-a[j]).se) return puts("NO"),0;
  }
  puts("YES");
  return 0;
}