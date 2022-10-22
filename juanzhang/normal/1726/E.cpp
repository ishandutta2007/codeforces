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

//const int P=1e9+7;
const int maxn = 1 << 21 | 5, P = 998244353, G = 3, Gi = 332748118;
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

int N, lim, rev[maxn];
int n, m, A[maxn], B[maxn];

void NTT(int *A, int opt) {
  for (int i = 0; i < N; i++) {
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  }
  for (int l = 1; l < N; l <<= 1) {
    int w = qp(opt == 1 ? G : Gi, (P - 1) / (l << 1));
    for (int i = 0; i < N; i += l << 1) {
      int cur = 1;
      for (int j = 0; j < l; j++, cur = 1ll * cur * w % P) {
        int x = A[i + j], y = 1ll * cur * A[i + j + l] % P;
        A[i + j] = (x + y) % P, A[i + j + l] = (x - y + P) % P;
      }
    }
  }
}

int C[maxn];

void mul() {
//  scanf("%d %d", &n, &m);
  N = 1, lim = 0;
  while (N <= n + m) N <<= 1, lim++;
  rep(i, 0, N - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lim - 1));
//  rep(i, 0, n) scanf("%d", A + i);
//  rep(i, 0, m) scanf("%d", B + i);
  NTT(A, 1), NTT(B, 1);
  rep(i, 0, N - 1) A[i] = 1ll * A[i] * B[i] % P;
  NTT(A, -1);
  int tmp = qp(N, P - 2);
  rep(i, 0, n + m) C[i] = int(1ll * tmp * A[i] % P);
}

//int n,dp[maxn];
int ipw[maxn];

void solve(){
  int x;
  cin>>x;
  int ans=0;
  rep(i,0,x/4){
//    ans=(ans+1ll*binom(x-2*i,2*i)*binom(2*i,i)%P*fac[i]%P*ipw[i]%P*C[x-i*4]%P*pw2[i])%P;
//    ans=(ans+1ll*binom(x-2*i,2*i)*binom(2*i,i)%P*fac[i]%P*C[x-i*4])%P;
    ans=(ans+1ll*fac[x-2*i]*ifac[x-4*i]%P*ifac[i]%P*C[x-i*4])%P;
  }
  cout<<ans<<endl;
//  cin>>n;
//  cout<<dp[n]<<endl;
}

signed main(){
  ipw[0]=1;
  rep(i,1,maxn-1)ipw[i]=1ll*ipw[i-1]*(P+1)/2%P;
  init();
  n=m=3e5;
//  rep(i,0,n)if(i%2==0)C[i]=1ll*binom(i,i/2)*ipw[i/2]%P*fac[i/2]%P*ifac[i]%P;
//  rep(i,0,n-1)Add(C[i+1],C[i]);
  rep(i,0,n)A[i]=ifac[i];
  rep(i,0,m)if(i%2==0)B[i]=1ll*binom(i,i/2)*ipw[i/2]%P*fac[i/2]%P*ifac[i]%P;
  mul();
  rep(i,0,n)C[i]=1ll*fac[i]*C[i]%P;
//  rep(i,0,4)printf("%d : %d\n",i,C[i]);
//  mem(A);
//  rep(i,0,n)A[i]=C[i];
//  mem(B);
//  rep(i,0,m)if(i%4==0)C[i]=
//  n=3e5;
//  dp[1]=1;
//  dp[2]=2;
//  rep(i,3,n){
//    dp[i]=(1ll*i*dp[i-1]+1ll*i*(i-1)/2%P*dp[i-2])%P;
//  }
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}