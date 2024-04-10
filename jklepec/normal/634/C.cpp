#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i < n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 2e5 + 5, M = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

int x, y;

int a[MAXN], b[MAXN];

struct fenwick {

   ll L[MAXN];

   fenwick() {
      memset(L, 0, sizeof L);
   }

   void update(int x, int val) {
      for(; x < MAXN; x += x & -x) L[x] += (ll)val;
   }

   ll read(int x) {
      if(x >= MAXN)
         x = MAXN - 1;
      if(x < 1)
         return 0LL;
      ll ret = 0;
      for(; x > 0; x -= x & -x) ret += (ll)L[x];
      return ret;
   }

} f1, f2;

void fix() {
   int d, v;
   cin >> d >> v;

   ll fa = 0, fb = 0;

   fa = min(x - a[d], v);
   a[d] = min(a[d] + v, x);

   fb = min(y - b[d], v);
   b[d] = min(b[d] + v, y);

   f1.update(d, fa);
   f2.update(d, fb);
}

int k;

void solve() {
   int p; cin >> p;

   ll sol = 0;

   sol += f2.read(p - 1);
   sol += f1.read(MAXN - 1);
   sol -= f1.read(p + k - 1);

   cout << sol << endl;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int n, q;

   cin >> n >> k >> x >> y >> q;

   rep(i, q) {
      int tip; cin >> tip;
      if(tip == 1)
         fix();
      if(tip == 2)
         solve();
   }

}