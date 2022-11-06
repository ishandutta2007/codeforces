#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(5e5 + 5);
int max[N << 2], tag[N << 2];
LL sum[N << 2];
#define ls o << 1
#define rs o << 1 | 1
inline void pushup(int o) {
  max[o] = std::max(max[ls], max[rs]);
  sum[o] = sum[ls] + sum[rs];
}
inline void pushdown(int o, int len) {
  if (tag[o]) {
    max[ls] = max[rs] = tag[ls] = tag[rs] = tag[o];
    sum[ls] = 1LL * tag[o] * (len - len / 2);
    sum[rs] = 1LL * tag[o] * (len / 2);
    tag[o] = 0;
  }
}
bool update(int o, int l, int r, int x, int y) {
  if (x < l) return true;
  if (r <= x) {
    if (max[o] <= y) {
      tag[o] = max[o] = y, sum[o] = 1LL * (r - l + 1) * y;
      return true;
    }
  }
  if (l == r) return false;
  pushdown(o, r - l + 1);
  int m = l + r >> 1;
  if (!update(rs, m + 1, r, x, y)) return pushup(o), false;
  bool res = update(ls, l, m, x, y);
  pushup(o);
  return res;
}
void ins(int o, int l, int r, int x, int y) {
  if (l == r) {
    max[o] = sum[o] = y;
    return;
  }
  pushdown(o, r - l + 1);
  int m = l + r >> 1;
  x <= m ? ins(ls, l, m, x, y) : ins(rs, m + 1, r, x, y);
  pushup(o);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::string s;
  std::cin >> n >> s;
  int now = 0;
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      for (int j = 1; j <= now; j++) {
        ins(1, 0, n - 1, i - j, j);
      }
      now = 0;
    } else {
      now++;
      ans += 1LL * (now + 1) * now / 2;
      update(1, 0, n - 1, i - now, now);
    }
    ans += sum[1];
  }
  std::cout << ans;
  return 0;
}