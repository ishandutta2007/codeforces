#include <bits/stdc++.h>
#define fs first
#define sc second
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef double db;
const int N = 2000 + 10;
const db eps = 1e-8;
int n, a, b;
db p[N], q[N], t[N];
struct node {
   db v; int x, y;
   bool operator < (node b) const { return v < b.v; }
   node operator + (node b) { return {v + b.v, x + b.x, y + b.y}; }
} f;
inline node max(node a, node b) { return a < b ? b : a; }
void calc2(db k1, db k2) {
   f = {0, 0, 0};
   rep(i, 1, n) {
      f = f + max(node {0, 0, 0}, max(max(node {q[i] - k2, 0, 1}, node {p[i] - k1, 1, 0}), node {t[i] - k1 - k2, 1, 1}));
   }
}
pair<int, db> calc1(db k1) {
   db l = 0, r = 1.1, ans = 0; int cnt = 0;
   while(r - l > eps) {
      db mid = (l + r) / 2;
      calc2(k1, mid);
      if(f.y <= b) {
         r = mid; ans = f.v + r * b; cnt = f.x;
      } else {
         l = mid;
      }
   }
   return pair<int, db>(cnt, ans);
}
int main() {
   scanf("%d%d%d", &n, &a, &b);
   rep(i, 1, n) scanf("%lf", p + i);
   rep(i, 1, n) scanf("%lf", q + i);
   rep(i, 1, n) t[i] = p[i] + q[i] - p[i] * q[i];
   db l = 0, r = 1.1, ans = 0;
   while(r - l > eps) {
      db mid = (l + r) / 2;
      auto res = calc1(mid);
      if(res.fs <= a) {
         r = mid; ans = res.sc + r * a;
      } else {
         l = mid;
      }
   }
   printf("%.6f\n", ans);
   return 0;
}