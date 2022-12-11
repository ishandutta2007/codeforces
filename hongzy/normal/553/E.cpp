#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define debug(x) printf("%s = %d\n", #x, (int) x)
using namespace std;

typedef double db;
typedef long long ll;

const db pi = 2 * acos(-1);
const int N = 262144 + 5, M = 110, T = 2e4 + 10;

struct comp {
   db x, y;
   comp() {} comp(db a, db b) : x(a), y(b) {}
   comp operator + (const comp &b) const { return comp(x + b.x, y + b.y); }
   comp operator - (const comp &b) const { return comp(x - b.x, y - b.y); }
   comp operator * (const comp &b) const { return comp(x * b.x - y * b.y, b.x * y + x * b.y); }
   comp conj() { return comp(x, -y); }
} W[N], A[N], B[N];

int rev[N], len;
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
struct edge {
   int u, v, w;
   db t[T];
} e[M];
int n, m, t, x;
db f[M][T * 2], g[M][T * 2], dis[M][M];
void cdq(int l, int r) {
   if(l >= t + 1) return ;
   if(l == r) {
      rep(i, 1, n - 1) f[i][l] = 1e18;
      rep(i, 1, m) if(e[i].u != n) {
         f[e[i].u][l] = min(f[e[i].u][l], e[i].w + g[i][l]);
      }
      return ;
   }
   int mid = (l + r) >> 1;
   cdq(mid + 1, r); init(r - mid + r - l);
   rep(i, 1, m) if(e[i].u != n) {
      int &v = e[i].v;
      A[0] = B[0] = comp(0, 0);
      rep(j, 1, len - 1) A[j] = comp(j <= r - mid ? f[v][mid + j] : 0, 0);
      rep(j, 1, len - 1) B[j] = comp(j <= r - l && j <= t ? e[i].t[j] : 0, 0);
      reverse(B, B + r - l + 1);
      fft(A, 1); fft(B, 1);
      rep(j, 0, len - 1) A[j] = A[j] * B[j];
      fft(A, -1);
      rep(j, l, mid) {
         g[i][j] += A[j - mid + r - l].x;
      }
   }
   cdq(l, mid);
}
int main() {
   scanf("%d%d%d%d", &n, &m, &t, &x);
   rep(i, 1, n) rep(j, 1, n) dis[i][j] = i == j ? 0 : 1e18;
   rep(i, 1, m) {
      scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
      rep(j, 1, t) { int x; scanf("%d", &x); e[i].t[j] = x / 1e5; }
      dis[e[i].u][e[i].v] = min(dis[e[i].u][e[i].v], (db) e[i].w);
   }
   rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
      dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
   rep(i, 1, n) rep(j, t + 1, 2 * t) f[i][j] = x + dis[i][n];
   cdq(0, 2 * t);
   printf("%.10f\n", f[1][0]);
   return 0;
}