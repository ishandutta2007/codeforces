#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = std::int64_t;
using PII = std::pair<int, int>;

constexpr int N(2e5 + 5);
struct Node {
  Node *ls, *rs;
  int siz;
  LL sum, up, dn;
} t[N * 40], *ptr = t + 1, *null = t, *root = null;
LL p[N << 1];
int cnt;
void ins(Node *&o, int l, int r, int x, int y) {
  if (o == null) o = ptr++, o->ls = o->rs = null;
  o->siz += y;
  o->sum += p[x] * y;
  if (l == r) {
    o->up += p[x] * y;
    o->dn += p[x] * y;
    return;
  }
  auto m = l + r >> 1;
  x <= m ? ins(o->ls, l, m, x, y) : ins(o->rs, m + 1, r, x, y);
  o->up = o->ls->up + o->rs->up + o->ls->siz * o->rs->sum;
  o->dn = o->ls->dn + o->rs->dn + o->rs->siz * o->ls->sum;  
}
LL askSum(Node *o, int l, int r, int k) {
  if (o == null || !k) return 0;
  if (k == o->siz) return o->sum;
  auto m = l + r >> 1;
  return k <= o->ls->siz ? askSum(o->ls, l, m, k) : askSum(o->rs, m + 1, r, k - o->ls->siz) + o->ls->sum;
}
LL askL(Node *o, int l, int r, int k) {
  if (o == null || !k) return 0;
  if (k == o->siz) return o->dn;
  auto m = l + r >> 1;
  if (k <= o->ls->siz) return askL(o->ls, l, m, k);
  return askL(o->rs, m + 1, r, k - o->ls->siz) + o->ls->dn + (k - o->ls->siz) * o->ls->sum;
}
LL askR(Node *o, int l, int r, int k) {
  if (o == null || !k) return 0;
  if (k == o->siz) return o->up;
  auto m = l + r >> 1;
  if (k <= o->rs->siz) return askR(o->rs, m + 1, r, k);
  return askR(o->ls, l, m, k - o->rs->siz) + o->rs->up + (k - o->rs->siz) * o->rs->sum;
}
int n;
LL size(int k) {
  return askSum(root, 1, cnt, k + 1) - root->sum + askSum(root, 1, cnt, n - k);
}
LL sumSize(int k) {
  return askL(root, 1, cnt, k + 1) - askR(root, 1, cnt, k);
}
LL calc() {
  n = root->siz;
  if (n <= 1) return 0;
  LL ans = root->sum;
  int l = 0, r = n / 2;
  while (l < r) {
    int m = l + r + 1 >> 1;
    if (size(m) >= 0) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  ans -= sumSize(l);
  if (n == 2) return ans;
  l = std::max(n / 2 + 1, n - l - 1);
  while (size(l) < 0) l++;
  ans -= sumSize(n - 1) - sumSize(l - 1);
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int m;
  std::cin >> n >> m;
  std::vector<LL> a(n);
  std::vector<std::pair<int, LL>> q(m);
  for (auto &x : a) std::cin >> x, p[++cnt] = x;
  for (auto &[x, y] : q) std::cin >> x >> y, p[++cnt] = y;
  std::sort(p + 1, p + 1 + cnt);
  cnt = std::unique(p + 1, p + 1 + cnt) - p - 1;
  for (auto x : a) {
    ins(root, 1, cnt, std::lower_bound(p + 1, p + 1 + cnt, x) - p, 1);
  }
  std::cout << calc() << "\n";
  for (auto &[opt, x] : q) {
    ins(root, 1, cnt, std::lower_bound(p + 1, p + 1 + cnt, x) - p, opt == 1 ? 1 : -1);
    std::cout << calc() << "\n";
  }
  return 0;
}