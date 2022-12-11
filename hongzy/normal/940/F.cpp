#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e5 + 10;
struct discrete {
   vector<int> v;
   vector<int>::iterator ep;
   void push(int x) { v.pb(x); }
   int size() { return ep - v.begin(); }
   void build() { sort(v.begin(), v.end()); ep = unique(v.begin(), v.end()); }
   int get(int x) { return lower_bound(v.begin(), ep, x) - v.begin() + 1; }
} ds;
struct Modify { int t, p, v; } c[N];
struct Query {
   int t, l, r, l2, r2;
   bool operator < (const Query &b) const {
      if(l2 != b.l2) return l2 < b.l2;
      if(r2 != b.r2) return r2 < b.r2;
      return t < b.t;
   }
} d[N];
int n, n1, n2, q, s, op[N], ql[N], qr[N], a[N], ans[N], cnt[N * 2], cc[N];
void ins(int x, int v) { cc[cnt[x]] --; cc[cnt[x] += v] ++; }
int main() {
   scanf("%d%d", &n, &q); s = max(1, int(ceil(pow(n, 2 / 3.0))));
   rep(i, 1, n) scanf("%d", a + i), ds.push(a[i]);
   rep(i, 1, q) {
      scanf("%d%d%d", op + i, ql + i, qr + i);
      if(op[i] == 2) ds.push(qr[i]);
   }
   ds.build();
   rep(i, 1, n) a[i] = ds.get(a[i]);
   rep(i, 1, q) if(op[i] == 2) qr[i] = ds.get(qr[i]);
   rep(i, 1, q) {
      if(op[i] == 1) d[++ n2] = {i, ql[i], qr[i], ql[i] / s, qr[i] / s};
      if(op[i] == 2) c[++ n1] = {i, ql[i], qr[i]};
   }
   if(!n2) return 0;
   sort(d + 1, d + n2 + 1);
   int l = d[1].l, r = l - 1, t = 0;
   rep(i, 1, n2) {
      while(l > d[i].l) ins(a[-- l], 1);
      while(r < d[i].r) ins(a[++ r], 1);
      while(l < d[i].l) ins(a[l ++], -1);
      while(r > d[i].r) ins(a[r --], -1);
      while(t < n1 && c[t + 1].t < d[i].t) {
         t ++;
         if(l <= c[t].p && c[t].p <= r) {
            ins(a[c[t].p], -1); ins(c[t].v, 1);
         }
         swap(c[t].v, a[c[t].p]);
      }
      while(t > 0 && c[t].t > d[i].t) {
         if(l <= c[t].p && c[t].p <= r) {
            ins(a[c[t].p], -1); ins(c[t].v, 1);
         }
         swap(c[t].v, a[c[t].p]);
         t --;
      }
      int z = 1;
      while(cc[z]) z ++;
      ans[d[i].t] = z;
   }
   rep(i, 1, q) if(ans[i]) printf("%d\n", ans[i]);
   return 0;
}