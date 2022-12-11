#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#define fs first
#define sc second
#define pb emplace_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, m, seed, vmax, a[N];
int rnd() {
   const int mod = 1e9 + 7;
   int ret = seed;
   seed = (seed * 7ll + 13) % mod;
   return ret;
}
int qpow(int a, int b, int mod) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
struct node {
   int l, r;
   mutable ll v;
   bool operator < (const node &b) const {
      return l < b.l;
   }
};
set<node> S;
typedef set<node>::iterator odt;
odt split(int x) {
   if(x > n) return S.end();
   odt it = -- S.upper_bound((node) {x, 0, 0ll});
   if(it->l == x) return it;
   node t = *it; S.erase(it);
   S.insert((node) {t.l, x - 1, t.v});
   return S.insert((node) {x, t.r, t.v}).fs;
}
void assign(int l, int r, ll v) {
   odt it = split(r + 1);
   S.erase(split(l), it);
   S.insert((node) {l, r, v});
}
void add(int l, int r, ll v) {
   odt epos = split(r + 1);
   for(odt it = split(l); it != epos; it ++) {
      it->v += v;
   }
}
ll kth(int l, int r, int k) {
   vector< pair<ll, int> > vec;
   odt epos = split(r + 1);
   for(odt it = split(l); it != epos; it ++) {
      vec.pb(it->v, it->r - it->l + 1);
   }
   sort(vec.begin(), vec.end());
   rep(i, 0, (int) vec.size() - 1) {
      k -= vec[i].sc;
      if(k <= 0) return vec[i].fs;
   }
   return -1;
}
int query(int l, int r, int x, int mod) {
   odt epos = split(r + 1);
   int ans = 0;
   for(odt it = split(l); it != epos; it ++) {
      (ans += (it->r - it->l + 1ll) * qpow(it->v % mod, x, mod) % mod) %= mod;
   }
   return ans;
}
int main() {
   scanf("%d%d%d%d", &n, &m, &seed, &vmax);
   rep(i, 1, n) S.insert((node) {i, i, rnd() % vmax + 1});
   int op, l, r, x, y;
   rep(i, 1, m) {
      op = rnd() % 4 + 1; l = rnd() % n + 1; r = rnd() % n + 1;
      if(l > r) swap(l, r);
      if(op == 3) x = rnd() % (r - l + 1) + 1;
      else x = rnd() % vmax + 1;
      if(op == 4) y = rnd() % vmax + 1;

      if(op == 1) add(l, r, x);
      if(op == 2) assign(l, r, x);
      if(op == 3) printf("%lld\n", kth(l, r, x));
      if(op == 4) printf("%d\n", query(l, r, x, y));
   }
   return 0;
}