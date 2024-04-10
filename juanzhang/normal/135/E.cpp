#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

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
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

const int P=1e9+7;
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int&x,int y){if((x+=y)>=P)x-=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}

const int maxn=1e6+10;
int fac[maxn],ifac[maxn],inv[maxn];
int binom(int n,int m){
  return n<m||m<0?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
int calc(int n,int m){
  return n<m||m<0?0:1ll*fac[n]*ifac[n-m]%P;
}
void init(){
  fac[0]=ifac[0]=fac[1]=ifac[1]=inv[1]=1;
  rep(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%P,inv[i]=1ll*(P-P/i)*inv[P%i]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P;
}

int k,w;

void solve(){
  cin>>k>>w;
  int ans=0;
  rep(j1,2,k+1){
    ll res;
    int n=w+j1-1;
    if(j1<=w){
      res=1ll*binom(k,j1-1)*fac[j1-1]%P*(j1-1)%P*binom(k,n-w)%P*fac[n-w]%P*qp(k,w-j1)%P;
    }else{
      int inter=j1-w;
      res=1ll*binom(k-inter,w-1)*fac[w-1]%P*w%P*binom(k,n-w)%P*fac[n-w]%P;
    }
//    printf("%d : %lld\n",j1,res);
    ans=(ans+res)%P;
  }
  rep(j1,2,k+1){
    ll res;
    int n=w+j1-1;
    if(j1<w){
      res=1ll*binom(k,j1-1)*fac[j1-1]%P*(j1-1)%P*binom(k,n-w+1)%P*fac[n-w+1]%P*qp(k,w-j1-1)%P;
    }else{
      int inter=j1-w+1;
      res=1ll*binom(k-inter,w-2)*fac[w-2]%P*(w-1)%P*binom(k,n-w+1)%P*fac[n-w+1]%P;
    }
    ans=(ans+res)%P;
  }
  cout<<ans<<endl;
}

signed main(){
  init();
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}