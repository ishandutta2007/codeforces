#include <cstdio>
#include <map>
#include <vector>
#include <functional>

typedef long long i64;

std::map<int, int> input() {
  std::map<int, int> res;
  for (int i = 3; i--;) {
    int x;
    scanf("%d", &x);
    for (int y = 2; y * y <= x; ++y)
      for (; x % y == 0; x /= y) ++res[y];
    if (x > 1) ++res[x];
  }
  return res;
}

i64 calc(const std::map<int, int> &pool) {
  i64 res = 1;
  for (const auto &it : pool)
    for (int k = it.second; k--;)
      res *= it.first;
  return res;
}

int main() {
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    std::map<int, int> n = input(), m = input(), s = input();
    ++s[2];
    std::vector<i64> p;
    for (auto it : n) {
      int x = s.count(it.first) ? s[it.first] : 0;
      if (it.second > x) {
        i64 cur = 1;
        for (int i = x + 1; i--;) cur *= it.first;
        p.push_back(cur);
      }
    }
    i64 ans = 0, x = calc(n), y = calc(m);
    for (int i = 0; i < (1 << p.size()); ++i) {
      i64 w = 1;
      for (int j = 0; j < p.size(); ++j) if (i >> j & 1) w *= p[j];
      ans += (__builtin_parity(i) ? -1 : 1) * (y / w);
    }
    std::vector<std::pair<int, int>> q;
    for (auto it : s) q.emplace_back(it.first, it.second);
    std::function<void(int, i64)> dfs = [&] (int i, i64 cur) {
      if (cur > x) return;
      if (i == q.size()) {
        ++ans;
        return;
      }
      dfs(i + 1, cur);
      for (int j = q[i].second; j--;) dfs(i + 1, cur *= q[i].first);
    };
    dfs(0, 1);
    printf("%lld\n", ans);
  }
  return 0;
}