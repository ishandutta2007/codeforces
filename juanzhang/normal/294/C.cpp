#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=1010,P=1e9+7;

int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}

int inv[maxn],fac[maxn],ifac[maxn],pw2[maxn];
int binom(int n,int m){return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
void init(){
  fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=pw2[0]=1,pw2[1]=2;
  rep(i,2,maxn-1)inv[i]=1ll*(P-P/i)*inv[P%i]%P,fac[i]=1ll*i*fac[i-1]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P,pw2[i]=2*pw2[i-1]%P;
}

int n,m,A[maxn];

void solve(){
  init();
  cin>>n>>m;
  rep(i,1,m)A[i]=read();
  sort(A+1,A+m+1);
  int ans=fac[n-m];
  A[0]=0,A[m+1]=n+1;
  rep(i,1,m+1){
    int x=A[i]-A[i-1]-1;
    ans=1ll*ans*ifac[x]%P*(i==1||i==m+1||!x?1:pw2[x-1])%P;
  }
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}