#include <algorithm>
#include <cstdio>
#include <vector>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std; 
#define pb push_back
typedef long long ll
;
const int mod = 998244353;
const int uni = 1 << 18;
inline void upd(int &x, const int &y) {
   (x += y) >= mod ? x -= mod : 0;
}
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
int n, m, s, pc[uni];
inline int popcount(ll x) {
   return pc[x & (uni - 1)] + pc[(x >> 18) & (uni - 1)] + pc[x >> 36];
}
struct Lbase {
   ll a[64];
   int size() {
      int s = 0;
      rep(i, 0, m - 1) s += a[i] > 0;
      return s;
   }
   void insert(ll x) {
      per(i, m - 1, 0) if(x >> i & 1) {
         if(!a[i]) {
            a[i] = x;
            per(j, i - 1, 0) if(a[i] >> j & 1) a[i] ^= a[j];
            rep(j, i + 1, m - 1) if(a[j] >> i & 1) a[j] ^= a[i];
            break ;
         }
         x ^= a[i];
      }
   }
} L;
namespace task1 {

vector<int> pos;
int ans[64];
void dfs(int u, ll x) {
   if(u == s) {
      ans[popcount(x)] ++; return ;
   }
   dfs(u + 1, x ^ L.a[pos[u]]);
   dfs(u + 1, x);
}
void main() {
   rep(i, 0, m - 1) if(L.a[i]) pos.pb(i);
   dfs(0, 0);
   int tot = qpow(2, n - s);
   rep(i, 0, m) {
      ans[i] = 1ll * ans[i] * tot % mod;
      printf("%d ", ans[i]);
   }
   putchar('\n');
}

}
namespace task2 {

vector<int> pos;
ll sta, st[64];
int C[64][64], B[64][64], ans[64], cnt[64];
void dfs(int u, int c, ll free) {
   if(u == pos.size()) {
      cnt[popcount(free) + c] ++;
      return ;
   }
   dfs(u + 1, c + 1, free ^ st[pos[u]]);
   dfs(u + 1, c, free);
}
void main() {
   rep(i, 0, m - 1) if(!L.a[i]) pos.pb(i); else sta ^= 1ll << i;
   rep(i, 0, m - 1) if(L.a[i]) {
      rep(j, 0, m - 1) if(!L.a[j] && L.a[i] >> j & 1) {
         st[j] ^= 1ll << i;
      }
   }
   dfs(0, 0, 0);
   rep(i, 0, m) {
      C[i][0] = C[i][i] = 1;
      rep(j, 1, i - 1) {
         C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
      }
   }
   rep(k, 0, m) {
      rep(i, 0, m) {
         int res = 0;
         rep(j, 0, m) {
            if(j > k || j > i) break ;
            if(j & 1) res = dec(res, 1ll * C[i][j] * C[m - i][k - j] % mod);
            else upd(res, 1ll * C[i][j] * C[m - i][k - j] % mod);
         }
         upd(ans[k], 1ll * res * cnt[i] % mod);
      }
   }
   int tot = 1ll * qpow(2, n - s) * qpow((mod + 1) / 2, m - s) % mod;
   rep(i, 0, m) {
      ans[i] = 1ll * ans[i] * tot % mod;
      printf("%d ", ans[i]);
   }
}

}
int main() {
   scanf("%d%d", &n, &m);
   rep(i, 1, n) { ll x; scanf("%lld", &x); L.insert(x); }
   s = L.size();
   rep(i, 1, uni - 1) pc[i] = pc[i & (i - 1)] + 1;
   ll Ag1 = 1ll << s, Ag2 = (1ll << (m - s)) + m * m * m;
   if(Ag1 < Ag2) task1::main(); else task2::main();
   return 0;
}