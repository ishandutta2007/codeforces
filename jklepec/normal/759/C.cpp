#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int off = 1 << 17, inf = 1e9;

struct tour {
   int t[2 * off];
   int p[2 * off];
   void init() {
      fill(t, t + (2 * off), inf);
      fill(p, p + (2 * off), 0);
   }
   void prop(int x) {
      if(p[x]) {
         t[x] += p[x];
         if(x < off) {
            p[x * 2] += p[x];
            p[x * 2 + 1] += p[x];
         }
         p[x] = 0;
      }
   }
   void update(int x, int a, int b, int v, int lo = 0, int hi = off) {
      if(lo >= a && hi <= b) {
         p[x] += v;
         prop(x);
         return;
      }
      prop(x);
      if(lo >= b || hi <= a)
         return;
      int mid = (lo + hi) >> 1;
      update(x * 2 + 0, a, b, v, lo, mid);
      update(x * 2 + 1, a, b, v, mid, hi);
      t[x] = min(t[x * 2], t[x * 2 + 1]);
   }
   int potraga(int x = 1, int lo = 0, int hi = off) {
      prop(x);

      if(t[x] >= 0)
         return -1;

      if(hi - lo == 1)
         return lo;

      int mid = (lo + hi) >> 1;
      int ret = potraga(x * 2 + 1, mid, hi);

      if(ret != -1)
         return ret;

      return potraga(x * 2, lo, mid);
   }
} T;

int a[off];

void read() {
   int x, t; cin >> x >> t;
   if(t) {
      cin >> a[x];
      T.update(1, 0, x + 1, -1);
      T.update(1, x, x + 1, -inf);
   }
   else {
      T.update(1, 0, x, 1);
   }

   int sol = T.potraga();
   if(sol == -1) {
      cout << -1 << '\n';
   }
   else {
      cout << a[sol] << '\n';
   }
   //
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);

   T.init();

   int q; cin >> q;
   REP(i, q)
      read();
}