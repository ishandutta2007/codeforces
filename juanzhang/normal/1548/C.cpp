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
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int P=1e9+7;
int fix(int x){
  return x+(x>>31&P);
}
void Add(int&x,int y){
  x+=y-P,x+=x>>31&P;
}
void Sub(int&x,int y){
  x-=y,x+=x>>31&P;
}
int Inc(int x,int y){
  return x+=y-P,x+(x>>31&P);
}
int Dec(int x,int y){
  return x-=y,x+(x>>31&P);
}
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=3e6+10;
int fac[maxn],inv[maxn],ifac[maxn];
int binom(int n,int m){
  return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
void init(){
  fac[0]=ifac[0]=inv[1]=ifac[1]=fac[1]=1;
  rep(i,2,maxn-1)inv[i]=1ll*(P-P/i)*inv[P%i]%P,fac[i]=1ll*fac[i-1]*i%P,ifac[i]=1ll*ifac[i-1]%P*inv[i]%P;
}

int n,q,dp[maxn][3];

void solve(){
  n=read(),q=read();
  dp[0][0]=n+1,dp[0][1]=dp[0][2]=n;
  rep(a,1,3*n){
    int coef[3]={0,0,0};
    rep(b,0,2){
      int c=(b+2)%3;
      coef[b]=(1ll*dp[a-1][c]-(c?0:Inc(binom(3*n,a-1),binom(3*n,a)))+P)%P;
    }
    int sum=binom(3*n+1,a+1);
    rep(b,0,2){
      dp[a][b]=(1ll*coef[b]+sum-coef[(b+1)%3]+P)%P*inv[3]%P;
    }
  }
  while(q--){
    int x=read();
    write(dp[x][0]),pc(10);
  }
}

signed main(){
  init();
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}