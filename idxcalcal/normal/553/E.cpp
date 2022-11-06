#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
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
struct cp {
  double x,y;
  cp(double x=0,double y=0):x(x),y(y) {}
  friend inline cp operator+(cp a,cp b) { return cp(a.x+b.x,a.y+b.y); }
  friend inline void operator+=(cp&a,cp b) { a=a+b; }
  friend inline cp operator-(cp a,cp b) { return cp(a.x-b.x,a.y-b.y); }
  friend inline void operator-=(cp&a,cp b) { a=a-b; }
  friend inline cp operator*(cp a,cp b) { return cp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }
  friend inline void operator*=(cp&a,cp b) { a=a*b; }
  friend inline cp operator*(cp a,double b) { return cp(a.x*b,a.y*b); }
  friend inline void operator*=(cp&a,double b) { a=a*b; }
  friend inline cp operator/(cp a,double b) { return cp(a.x/b,a.y/b); }
  friend inline void operator/=(cp&a,double b) { a=a/b; }
};
typedef vector<cp> poly;
const double pi=acos(-1.0);
int lim,tim,n,m,t,W;
cp w[23];
vector<int>rev[23];
inline void init_fft() { for(ri i=0;i<23;++i) w[i]=cp(cos(pi/(1<<i)),sin(pi/(1<<i))); }
inline void init(int up) {
  lim=1,tim=0;
  while(lim<up) lim<<=1,++tim;
  if(rev[tim].size()) return;
  rev[tim].resize(lim);
  for(ri i=1;i<lim;++i) rev[tim][i]=(rev[tim][i>>1]>>1)|((i&1)<<(tim-1));
}
inline void fft(poly&a,int typ) {
  for(ri i=1;i<lim;++i) if(i<rev[tim][i]) swap(a[i],a[rev[tim][i]]);
  cp a0,a1,mt;
  for(ri i=1,t=0;i<lim;i<<=1,++t) for(ri j=0,len=i<<1;j<lim;j+=len) {
    mt=cp(1,0);
    for(ri k=0;k<i;++k,mt*=w[t]) {
      a0=a[j+k],a1=a[j+k+i]*mt;
      a[j+k]=a0+a1,a[j+k+i]=a0-a1;
    }
  }
  if(~typ) return;
  reverse(++a.begin(),a.end());
  for(ri i=0;i<lim;++i) a[i]/=lim;
}
inline poly operator*(poly a,poly b) {
  int n=(int)a.size(),m=(int)b.size(),t=n+m-1;
  init(t);
  a.resize(lim),fft(a,1);
  b.resize(lim),fft(b,1);
  for(ri i=0;i<lim;++i) a[i]*=b[i];
  return fft(a,-1),a.resize(t),a;
}
const int N=105,M=205,K=20005;
int a[M],b[M],c[M],dis[N][N];
double f[N][K],sum[M][K],p[M][K];
inline void solve(int l,int r) {
  if(l==r) {
    for(ri e=1;e<=m;++e) f[a[e]][l]=min(f[a[e]][l],sum[e][l]+c[e]);
    return;
  }
  int mid=l+r>>1;
  solve(mid+1,r);
  poly F(r-mid),G(r-l+1),H;
  for(ri e=1;e<=m;++e) {
    for(ri i=mid+1;i<=r;++i) F[i-mid-1]=cp(f[b[e]][i],0);
    for(ri i=1;i<=r-l;++i) G[r-l-i]=cp(p[e][i],0);
    H=F*G;
    for(ri i=l;i<=mid;++i) sum[e][i]+=H[i-mid-1+r-l].x;
  }
  solve(l,mid);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  init_fft();
  n=read(),m=read(),t=read(),W=read();
  for(ri i=1;i<=n;++i) for(ri j=1;j<=n;++j) dis[i][j]=i==j?0:1e9;
  for(ri i=1;i<=m;++i) {
    a[i]=read(),b[i]=read(),c[i]=read();
    if(c[i]<dis[a[i]][b[i]]) dis[a[i]][b[i]]=c[i];
    for(ri j=1;j<=t;++j) p[i][j]=read()/100000.0;
  }
  for(ri k=1;k<=n;++k) for(ri i=1;i<=n;++i) for(ri j=1;j<=n;++j)
  dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  for(ri i=0;i<N;++i) for(ri j=0;j<K;++j) f[i][j]=1e9;
  for(ri i=1;i<=n;++i) f[i][t+1]=dis[i][n]+W;
  for(ri i=0;i<=t;++i) f[n][i]=0;
  double ss;
  for(ri e=1;e<=m;++e) {
    ss=0;
    for(ri i=1;i<=t;++i) {
      ss+=p[e][t+1-i];
      sum[e][i]=ss*f[b[e]][t+1];
    }
  }
  solve(0,t);
  printf("%.10lf",f[1][0]);
  return 0;
}