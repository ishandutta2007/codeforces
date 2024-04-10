#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 3e5 + 10;

const int P = 998244353;

int Inc(int x, int y) {
  return x + y < P ? x + y : x + y - P;
}

int Dec(int x, int y) {
  return x < y ? x - y + P : x - y;
}

void Add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

void Sub(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}

int inv[maxn], fac[maxn], ifac[maxn];

int binom(int n, int m) {
  return n < m ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

void init() {
  fac[0] = ifac[0] = 1;
  inv[1] = fac[1] = ifac[1] = 1;
  rep(i, 2, maxn - 1) {
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    fac[i] = 1ll * i * fac[i - 1] % P;
    ifac[i] = 1ll * inv[i] * ifac[i - 1] % P;
  }
}

int n, m, cnt[maxn], val[41][maxn];

struct line {
  int l, r;
} A[maxn], con[20];

void solve() {
  init();
  cin >> n >> m;
  rep(i,1,n){
    int l=read(),r=read();
    A[i]={l,r},cnt[l]++,cnt[r+1]--;
  }
  rep(i,0,m-1)con[i].l=read(),con[i].r=read();
  rep(i,1,n){
    cnt[i]+=cnt[i-1];
    rep(j,0,40)val[j][i]=Inc(val[j][i-1],(cnt[i]>=j&&i>=j?binom(cnt[i]-j,i-j):0));
  }
  int ans=0;
  static int vis[maxn];
  memset(vis, -1, sizeof vis);
  rep(S,0,(1<<m)-1){
    int l=1,r=n,sum=0;
    rep(i,0,m-1)if(S>>i&1){
      int lef=con[i].l,rig=con[i].r;
      if(vis[lef]!=S)vis[lef]=S,sum++;
      if(vis[rig]!=S)vis[rig]=S,sum++;
      chkmax(l,max(A[lef].l,A[rig].l));
      chkmin(r,min(A[lef].r,A[rig].r));
    }
    if(l>r)continue;
    ans=(ans+1ll*(__builtin_popcount(S)%2==1?-1:1)*(val[sum][r]-val[sum][l-1]+P)+P+P)%P;
  }
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}