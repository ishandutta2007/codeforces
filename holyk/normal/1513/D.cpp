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

using LL = long long;
using PII = std::pair<int, int>;

int main() {
  // freopen("t.in", "r", stdin);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);  
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), p(n);
    for (auto &x : a) std::cin >> x;
    std::iota(p.begin(), p.end(), 0);
    auto f = p, left = p, right = p;
    std::sort(p.begin(), p.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    auto find = [&](int x) {
      while (x != f[x]) x = f[x] = f[f[x]];
      return x;
    };
    LL ans = 0;
    std::vector<std::vector<int>> st(std::__lg(n) + 1, std::vector<int>(n));
    st[0] = a;
    for (int i = 1; i < st.size(); i++)
      for (int j = (1 << i) - 1; j < n; j++)
        st[i][j] = std::gcd(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    auto askGcd = [&](int l, int r) {
      int k = std::__lg(r - l + 1);
      return std::gcd(st[k][r], st[k][l + (1 << k) - 1]);
    };
    for (int i : p) {
      int x = a[i];
      if (x >= m) break;
      int o = find(i);
      int l = left[o] - 1, r = right[o] + 1;
      while (l >= 0 && askGcd(l, i) == a[i]) {
        l = find(l);
        f[l] = o;
        smin(left[o], left[l]);
        smax(right[o], right[l]);
        ans += a[i];
        l = left[o] - 1;
      }
      while (r < n && askGcd(i, r)== a[i]) {
        r = find(r);
        f[r] = o;
        smin(left[o], left[r]);
        smax(right[o], right[r]);
        ans += a[i];
        r = right[o] + 1;
      }
      // dbg("%d\n")
    }

    for (int i = 1; i < n; i++) {
      if (find(i) != find(i - 1)) f[find(i)] = find(i - 1), ans += m;
    }
    std::cout << ans << "\n";
  }
  return 0;
}