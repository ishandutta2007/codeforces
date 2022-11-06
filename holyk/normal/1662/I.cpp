#include <bits/stdc++.h>

using LL = long long;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m + 2);
  std::vector<LL> s(n + 1);
  for (int i = 0; i < n; i++) std::cin >> a[i], s[i + 1] = s[i] + a[i];
  for (int i = 0; i < m; i++) std::cin >> b[i];
  m += 2;
  b[m - 2] = -1e9;
  b[m - 1] = 1e9;
  std::sort(b.begin(), b.end());

  long long ans = 0;
  for (int i = 0, j = 0, k = 0; i < n; i++) {
    while (k < m && b[k] < i * 100) k++;
    assert(k && k < m);	
    if (b[k] == i * 100) continue;
    int l = b[k - 1], r = b[k];

    double x = std::max(i * 100 * 2 - r + 0.5, (double)l), lp = (l + x) / 2;

    while (j < n && j * 100 <= lp) j++;
    // std::cerr << l << " " << r << " " << x << " " << lp << "\n";
    ans = std::max(ans, s[i + 1] - s[j]);
  }
  std::cout << ans << "\n";
  return 0;
}