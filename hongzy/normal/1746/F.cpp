#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7, w = 32;
struct num {
  int c[w];
  void clr() {
    fill(c, c + w, 0);
  }
  num operator + (const num &b) const {
    num ans;
    for(int i = 0; i < w; i ++)
      ans.c[i] = c[i] + b.c[i];
    return ans;
  }
  num operator - (const num &b) const {
    num ans;
    for(int i = 0; i < w; i ++)
      ans.c[i] = c[i] - b.c[i];
    return ans;
  }
} bit[N];
unordered_map<int, uint> ID;
int n, q, a[N];
void add(int x, num y) {
  for(; x <= n; x += x & (-x))
    bit[x] = bit[x] + y;
}
void del(int x, num y) {
  for(; x <= n; x += x & (-x))
    bit[x] = bit[x] - y;
}
num qry(int x) {
  num z; z.clr();
  for(; x; x &= x-1)
    z = z + bit[x];
  return z;
}
num NUM(int x) {
  if(!ID.count(x)) {
    ID[x] = mt();
  }
  uint z = ID[x];
  num a;
  for(int i = 0; i < w; i ++)
    a.c[i] = z >> i & 1;
  return a;
}
int main() {
  scanf("%d%d", &n, &q);
  rep(i, 1, n) {
    scanf("%d", a + i);
    add(i, NUM(a[i]));
  }
  int op, l, r, k;
  rep(i, 1, q) {
    scanf("%d%d%d", &op, &l, &r);
    if(op == 1) {
      //a[l] = r
      if(a[l] == r)
        continue;
      del(l, NUM(a[l]));
      a[l] = r;
      add(l, NUM(a[l]));
    } else {
      scanf("%d", &k);
      num ans = qry(r) - qry(l-1);
      bool ok = 1;
      for(int j = 0; j < w; j ++)
        if(ans.c[j] % k) {
          ok = 0;
          break;
        }
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}