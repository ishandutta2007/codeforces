#include <bits/stdc++.h>
#define fs first
#define sc second
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
const db eps = 1e-8;
const db pi = acos(-1.0);

template<class T>
struct BIT {
   vector<T> c;
   int n;
   BIT(int sz) { c.resize(1 + (n = sz)); }
   void add(int x, T y) {
      for(; x <= n; x += x & (-x))
         c[x] += y;
   }
   T qry(int x) {
      T ans = 0;
      for(; x >= 1; x &= x - 1)
         ans += c[x];
      return ans;
   }
};
struct point {
   db d, a;
} a[N];
int n, sz; ll k;
db num[N], ql[N], qr[N];
pii it[N];
ll calc(db r) { //dis <= r
   sz = 0;
   db *pos = &num[1];
   rep(i, 1, n) if(a[i].d > r) {
      db e = acos(r / a[i].d);
      sz ++;
      ql[sz] = a[i].a - e; qr[sz] = a[i].a + e;
      if(ql[sz] < -pi) ql[sz] += 2 * pi;
      if(qr[sz] > pi) qr[sz] -= 2 * pi;
      if(ql[sz] > qr[sz]) swap(ql[sz], qr[sz]);
      *pos ++ = ql[sz]; *pos ++ = qr[sz];
   }
   if((n - sz) * (n - sz - 1ll) / 2 >= k) return k;
   ll ans = 0;
   sort(num + 1, pos);
   rep(i, 1, sz) {
      it[i].fs = lower_bound(num + 1, pos, ql[i]) - num;
      it[i].sc = lower_bound(num + 1, pos, qr[i]) - num;
   }
   sort(it + 1, it + sz + 1, [&](pii x, pii y) { return x.fs < y.fs || (x.fs == y.fs && x.sc > y.sc); });
   BIT<int> bit(pos - num);
   rep(i, 1, sz) {
      ans += bit.qry(it[i].sc - 1) - bit.qry(it[i].fs);
      bit.add(it[i].sc, 1);
   }
   ans = n * (n - 1ll) / 2 - ans;
   return ans;
}
int main() {
   scanf("%d%lld", &n, &k);
   db l = 0, r = 0;
   rep(i, 1, n) {
      int x, y; scanf("%d%d", &x, &y);
      a[i].d = sqrt(x * x + y * y); a[i].a = atan2(y, x);
      r = max(r, a[i].d);
   }
   while(r - l > eps) {
      db mid = (l + r) / 2;
      if(calc(mid) >= k) r = mid; else l = mid;
   }
   printf("%.10f\n", l);
   return 0;
}