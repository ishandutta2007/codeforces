#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

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
template<class T>void write(T x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=3e5+10;
int n,q,vsz,oriA[maxn],orix[maxn],A[maxn],B[maxn];bool ans[maxn];

int dat[maxn*2];

struct Querys{
  int op,l,r,k;
}Q[maxn];

ll c[maxn],sum[maxn];
void add(int pos,int x){
  for(;pos<=n;pos+=pos&-pos)c[pos]+=x;
}
ll query(int pos){
  ll res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;
}

int cst;

void solve(){
  n=read(),q=read();
  rep(i,1,n)dat[i]=A[i]=read();
  vsz=n;
  rep(i,1,q){
    int op=read(),l=read(),r=read(),k=-1;
    if(op==1){
      dat[++vsz]=r;
    }else{
      k=read();
      ans[i]=1;
    }
    Q[i]={op,l,r,k};
  }
  sort(dat+1,dat+vsz+1);
  vsz=unique(dat+1,dat+vsz+1)-dat-1;
  rep(i,1,n)oriA[i]=lower_bound(dat+1,dat+vsz+1,A[i])-dat;
  rep(i,1,q)if(Q[i].op==1)orix[i]=lower_bound(dat+1,dat+vsz+1,Q[i].r)-dat;
  static int mp[maxn*2];
  rep(_,1,50){
    rep(i,1,vsz)mp[i]=(u64)Rnd()&(((u64)1<<31)-1);
    rep(i,1,n)B[i]=mp[oriA[i]];
    rep(i,1,q)if(Q[i].op==1)Q[i].r=mp[orix[i]];
    rep(i,1,n)sum[i]=sum[i-1]+B[i],c[i]=sum[i]-sum[i&(i-1)];
    rep(i,1,q){
      auto e=Q[i];
      if(e.op==1){
        add(e.l,-B[e.l]);
        add(e.l,B[e.l]=e.r);
      }else if(ans[i]){
        ans[i]&=(query(e.r)-query(e.l-1))%e.k==0;
      }
    }
    if((db)(clock()-cst)/CLOCKS_PER_SEC>2.8)break;
  }
  rep(i,1,q)if(Q[i].op==2)puts(ans[i]?"YES":"NO");
}

signed main(){
  cst=clock();
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}