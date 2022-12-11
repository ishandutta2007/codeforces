#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef double db;
typedef long long ll;
 
const int N = 1e6 + 10;
const db pi = 2 * acos(-1);
struct comp {
   db x, y;
   comp() {}
   comp(db a, db b) : x(a), y(b) {}
   comp operator + (const comp &b) const { return comp(x + b.x, y + b.y); }
   comp operator - (const comp &b) const { return comp(x - b.x, y - b.y); }
   comp operator * (const comp &b) const { return comp(x * b.x - y * b.y, b.x * y + x * b.y); }
} W[N], A[N], B[N];
int len, rev[N];
void init(int n) {
   int k = 0;
   for(len = 1; len <= n; len <<= 1) k ++;
   for(int i = 1; i < len; i ++)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
   for(int i = 0; i < len; i ++)
      W[i] = comp(cos(pi * i / len), sin(pi * i / len));
}
void fft(comp *a, int ty) {
   for(int i = 1; i < len; i ++)
      if(i < rev[i]) swap(a[i], a[rev[i]]);
   static comp t1, t2;
   for(int i = 1; i < len; i <<= 1) {
      for(int j = 0; j < len; j += i << 1) {
         for(int k = j; k < j + i; k ++) {
            t1 = a[k], t2 = W[len / (i << 1) * (k - j)] * a[k + i];
            a[k] = t1 + t2; a[k + i] = t1 - t2;
         }
      }
   }
   if(ty == -1) {
      reverse(a + 1, a + len);
      for(int i = 0; i < len; i ++)
         a[i].x /= len, a[i].y /= len;
   }
}
int n, x, a[N], f[N], g[N];
ll ans0, ans[N];
int main() {
   scanf("%d%d", &n, &x);
   rep(i, 1, n) scanf("%d", a + i), a[i] = a[i] < x;
   ll z = 0;
   rep(i, 1, n) {
      if(a[i]) z = 0;
      else {
         z ++; ans0 += z;
      }
   }
   rep(i, 1, n) a[i] += a[i - 1];
   rep(i, 0, n) f[a[i]] ++;
   rep(i, 0, n) g[i] = f[n - i];
   init(n << 1);
   rep(i, 0, n) A[i] = comp(f[i], 0), B[i] = comp(g[i], 0);
   fft(A, 1); fft(B, 1);
   rep(i, 0, len - 1) A[i] = A[i] * B[i];
   fft(A, -1);
   rep(i, 1, n) ans[i] = (ll)(A[n + i].x + 0.5);
   printf("%lld", ans0);
   rep(i, 1, n) printf(" %lld", ans[i]);
   return 0;
}