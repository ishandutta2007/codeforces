#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using namespace std;
const int mod = 998244353, mod2 = mod - 1, g = 3;
const int N = 110;
int n, m, k, b[N];
struct mat {
   int a[N][N], n;
   mat operator * (const mat &b) const {
      mat ans; ans.n = n;
      rep(i, 1, n) rep(j, 1, n) {
         ans.a[i][j] = 0;
         rep(k, 1, n) {
            (ans.a[i][j] += 1ll * a[i][k] * b.a[k][j] % mod2) %= mod2;
         }
      }
      return ans;
   }
} fir, tr;
mat Pow(mat a, int b) {
   mat ans = a;
   for(b --; b >= 1; b >>= 1, a = a * a)
      if(b & 1) ans = ans * a;
   return ans;
}
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
int BSGS(int a, int b) {
   if(b == 1) return 0;
   int m = (int) ceil(sqrt(mod));
   int am = qpow(a, m), t = 1;
   map<int, int> Map; Map.clear();
   rep(i, 1, m) {
      t = 1ll * t * am % mod;
      if(!Map.count(t)) Map[t] = i;
   }
   t = b;
   rep(i, 0, m - 1) {
      if(Map.count(t)) {
         return Map[t] * m - i;
      }
      t = 1ll * t * a % mod;
   }
   return -1;
}
void exgcd(int a, int b, int &x, int &y, int &g) {
   if(!b) x = 1, y = 0, g = a;
   else exgcd(b, a % b, y, x, g), y -= x * (a / b);
}
int main() {
   scanf("%d", &k);
   rep(i, 1, k) scanf("%d", b + i);
   scanf("%d%d", &n, &m);
   fir.n = tr.n = k;
   fir.a[1][1] = 1;
   rep(i, 1, k) tr.a[i][1] = b[i] % mod2;
   rep(i, 1, k - 1) tr.a[i][i + 1] = 1;
   fir = fir * Pow(tr, n - k);
   int q = fir.a[1][1], r = BSGS(g, m), x, y, _g;
   // assert(qpow(g, r) == m);
   //q*x + (mod-1)*y = r (qx = r)
   exgcd(q, mod2, x, y, _g);
   if(r % _g) return puts("-1"), 0;
   int t = mod2 / _g;
   x = (1ll * x * (r / _g) % t + t) % t;
   printf("%d\n", qpow(g, x));
   return 0;
}