#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

const int P=998244353;
const int maxn=5010;

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

int S[maxn][maxn];

int main(){
  init();
  int n,m,k;
  cin>>n>>m>>k;
  if(m==1){
    cout<<qp(n,k)<<endl;return 0;
  }
  int res=0;
  int p=qp(m,P-2),q=(1-p+P)%P,z=1ll*p*qp(q,P-2)%P;
  S[0][0]=1;
  rep(i,1,k)rep(j,1,k)S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%P;
  int cur=1;
  rep(j,1,min(k,n)){
    cur=1ll*cur*inv[j]%P*(n-j+1)%P;
    int tp=1ll*qp(z+1,n-j)*qp(z,j)%P;
    res=(res+1ll*S[k][j]*fac[j]%P*tp%P*cur)%P;
  }
  res=1ll*res*qp(q,n)%P;
  cout<<res<<endl;
  return 0;
}