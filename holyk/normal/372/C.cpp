#include <bits/stdc++.h>

using LL = long long;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector<int> a(m), b(m), t(m);
  for (int i = 0; i < m; i++) std::cin >> a[i] >> b[i] >> t[i], a[i]--;
  std::vector<LL> f(n);
  for (int i = 0, j; i < m; i = j) {
    std::vector<LL> g(n), val(n);
    std::vector<int> q(n), cnt(n);
    int coef = 0;
    LL sum = 0;
    for (j = i; t[j] == t[i]; j++) {
      sum += b[j] - a[j];
      coef++;
      val[a[j]] += a[j];
      cnt[a[j]]++;
    }
    int l = 0, r = -1;
    auto add = [&](int x) {
      if (x < 0 || x >= n) return;
      while (l <= r && f[q[r]] <= f[x]) r--;
      q[++r] = x;
    };
    int e = std::min<LL>(n, 1LL * d * (i ? t[i] - t[i - 1] : t[i] - 1));
    for (int x = 0; x < e; x++) add(x);
    for (int x = 0; x < n; x++) {
      add(x + e);
      while (l <= r && q[l] < x - e) l++;
      sum += val[x] << 1;
      coef -= cnt[x] << 1;
      g[x] = f[q[l]] + 1LL * coef * x + sum;
    }
    f.swap(g);
  }
  std::cout << *std::max_element(f.begin(), f.end());
  return 0;
}