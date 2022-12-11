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
int n, q, sum;
struct node {
   int l, r; mutable int v;
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
void assign(int l, int r, int v) {
   odt epos = split(r + 1), st = split(l);
   for(odt it = st; it != epos; it ++) {
      if(it->v) sum -= it->r - it->l + 1;
   }
   S.erase(st, epos);
   S.insert((node) {l, r, v});
   if(v) sum += r - l + 1;
}
int main() {
   scanf("%d%d", &n, &q);
   S.insert((node) {1, n, 1}); sum = n;
   int l, r, x;
   rep(i, 1, q) {
      scanf("%d%d%d", &l, &r, &x);
      assign(l, r, x - 1);
      printf("%d\n", sum);
   }
   return 0;
}