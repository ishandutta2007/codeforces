#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

const int N = 5e4 + 10;

int mod, n, m, s[N];
ll k;
pii a[N];
struct mat {
   int a[2][2];
   void init(int x, int y, int z, int w) {
      a[0][0] = x; a[1][0] = y; a[0][1] = z; a[1][1] = w;
   }
} f[N * 4], cur, ans, ans2;
mat operator * (const mat &a, const mat &b) {
   for(int i = 0; i < 2; i ++) {
      for(int j = 0; j < 2; j ++) {
         ans.a[i][j] = ((ll)a.a[i][0] * b.a[0][j] + (ll)a.a[i][1] * b.a[1][j]) % mod;
      }
   }
   return ans;
}
mat operator * (mat a, ll pw) {
   ans2.init(1, 0, 0, 1);
   for(; pw >= 1; pw >>= 1, a = a * a)
      if(pw & 1) ans2 = ans2 * a;
   return ans2;
}
void build(int u, int l, int r) {
   if(l == r) {
      f[u].init(s[l == n ? 0 : l], s[l - 1], 1, 0);
      return ;
   }
   int mid = (l + r) >> 1;
   build(u << 1, l, mid);
   build(u << 1 | 1, mid + 1, r);
   f[u] = f[u << 1] * f[u << 1 | 1];
}
mat query(int u, int l, int r, int ql, int qr) {
   if(l == ql && r == qr) return f[u];
   int mid = (l + r) >> 1;
   if(qr <= mid) return query(u << 1, l, mid, ql, qr);
   if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
   return query(u << 1, l, mid, ql, mid) * query(u << 1 | 1, mid + 1, r, mid + 1, qr);
}
mat query(int l, int r) { return query(1, 1, n, l, r); }
mat pro(ll l, ll r) {
   int l0 = (l - 1) % n + 1, r0 = (r - 1) % n + 1;
   ll L = l % n == 0 ? l + 1 : l + n + 1 - (l % n); //
   ll R = r % n == 0 ? r - n : r - (r % n); //
   if(L - R > 1) return query(l0, r0);
   return query(l0, n) * ( f[1] * ( (R - L + 1) / n ) ) * query(1, r0);
}
int main() {
   scanf("%lld%d%d", &k, &mod, &n); -- k;
   if(k == -1) { puts("0"); return 0; } 
   rep(i, 0, n - 1) scanf("%d", s + i), s[i] %= mod;
   build(1, 1, n);
   scanf("%d", &m);
   rep(i, 1, m) scanf("%lld%d", &a[i].fs, &a[i].sc), a[i].sc %= mod;
   sort(a + 1, a + m + 1);
   cur.init(1 % mod, 0, 0, 0);
   mat A;
   ll p = 0;
   rep(i, 1, m) {
      if(a[i].fs > k) break ;
      if(p + 1 < a[i].fs) cur = cur * pro(p + 1, a[i].fs - 1);
      p = a[i].fs;
      int c = a[i].sc, b = a[i].fs == a[i - 1].fs + 1 ? a[i - 1].sc : s[(a[i].fs - 1) % n];
      A.init(c, b, 1, 0); cur = cur * A;

      if(p + 1 <= k && (i == m || p + 1 < a[i + 1].fs)) {
         p ++;
         A.init(s[p % n], a[i].sc, 1, 0); cur = cur * A;
      }
   }
   if(p + 1 <= k) cur = cur * pro(p + 1, k);
   printf("%d\n", cur.a[0][0]);
   return 0;
}
/*
10 23333
3
1 2 1
2
7 3
5 4
*/