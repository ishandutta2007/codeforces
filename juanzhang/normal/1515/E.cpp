#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=1010;
int n,P,val[maxn];

int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}

int inv[maxn],fac[maxn],ifac[maxn];
int binom(int n,int m){return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
void init(){
  fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=1;
  rep(i,2,maxn-1)inv[i]=1ll*(P-P/i)*inv[P%i]%P,fac[i]=1ll*i*fac[i-1]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P;
}

int dp[404][404];

void solve(){
  cin>>n>>P;
  init();
  rep(i,1,n){
    rep(j,1,i){
      Add(val[i],1ll*fac[i-1]*ifac[j-1]%P*ifac[i-j]%P);
    }
  }
  int ans=val[n];
  dp[0][0]=1;
  rep(i,1,n)rep(k,1,i){
    rep(j,0,i-2){
      Add(dp[i][k],1ll*dp[j][k-1]*ifac[i-j-1]%P*val[i-j-1]%P);
    }
    if(i==n||!dp[i][k])break;
//    printf("(%d %d)\n",i,k);
    int x=1ll*dp[i][k]*ifac[n-i]%P*fac[n-k]%P*val[n-i]%P;
//    printf("#%d %d\n",x,fac[n-k]);
    Add(ans,x);
  }
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}