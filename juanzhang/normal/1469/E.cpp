#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=1e6+10;

const int P1 = 1e9 + 7, P2 = 1e9 + 9;
int base, pow1[maxn], pow2[maxn];

struct Hash {
  int v1, v2;

  Hash() {}
  Hash(int x, int y) : v1(x), v2(y) {}
  
  ll gvz(){return 1ll*v1*P2+v2;}

  void print() {
    printf("#(%d %d)\n", v1, v2);
  }

  void get(Hash &o, char ch) {
    v1 = (1ll * o.v1 * base + ch) % P1;
    v2 = (1ll * o.v2 * base + ch) % P2;
  }

  bool operator == (const Hash &o) const {
    return v1 == o.v1 && v2 == o.v2;
  }

  bool operator != (const Hash &o) const {
    return v1 != o.v1 || v2 != o.v2;
  }
}H[maxn],F[maxn];

Hash getsum(Hash *A, int l, int r) {
  return Hash((A[r].v1 + 1ll * (P1 - A[l - 1].v1) * pow1[r - l + 1]) % P1,
              (A[r].v2 + 1ll * (P2 - A[l - 1].v2) * pow2[r - l + 1]) % P2);
}

void init() {
  base = Rnd();
  if (base < 0) base = -base;
  base %= 19260817, base += 257;
  pow1[0] = pow2[0] = 1;
  rep(i, 1, maxn - 1) {
    pow1[i] = 1ll * base * pow1[i - 1] % P1;
    pow2[i] = 1ll * base * pow2[i - 1] % P2;
  }
  rep(i,1,maxn-1){
    F[i].get(F[i>>1],i&1);
  }
}

int n,k,A[maxn];
char str[maxn];

void solve(){
  scanf("%d%d%s",&n,&k,str+1);
  rep(i,1,n)A[i]=(str[i]-'0')^1,H[i].get(H[i-1],A[i]);
  set<ll>vis;
  rep(i,1,n-k+1)vis.insert(getsum(H,i,i+k-1).gvz());
  rep(i,0,min(n-k+2,k<=25?(1<<k)-1:n)){
    if(!vis.count(F[i].gvz())){
      puts("YES");
      static int ans[maxn];
      memset(ans,0,(k+1)<<2);
      int x=i,ps=k;
      while(x)ans[ps--]=x&1,x>>=1;
      rep(i,1,k)printf("%d",ans[i]);
      puts("");
      return;
    }
  }
  puts("NO");
}

signed main(){
  init();
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}