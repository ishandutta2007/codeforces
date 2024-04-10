#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 150000 + 10, T = 10;

int n, t[N];

inline bool check(int x) { return (x & 1) ? (t[x] < t[x + 1]) : (t[x] > t[x + 1]); }

inline bool checkRange(int l, int r) {
  for (int i = l; i <= r; ++i) if (!check(i)) return false;
  return true;
}

std::vector<int> cur;

bool test(int x) {
  for (int j = std::max(1, x - T); j < n && j <= x + T; ++j) if (!check(j)) return false;
  for (int i = 0; i < cur.size(); ++i)
    for (int j = std::max(1, cur[i] - T); j < n && j <= cur[i] + T; ++j)
      if (!check(j)) return false;
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
  static bool flag[N];
  for (int i = 1; i < n; ++i) if (!check(i)) cur.push_back(i), cur.push_back(i + 1);
  cur.erase(std::unique(cur.begin(), cur.end()), cur.end());
  if (cur.size() > T) return puts("0"), 0;
  for (int i = 0; i < cur.size(); ++i) flag[cur[i]] = true;
  int ans = 0;
  for (int i = 0; i < cur.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      if (cur[i] == j) continue;
      if (flag[j] && cur[i] > j) continue;
      std::swap(t[cur[i]], t[j]);
      if (test(j)) ++ans;
      std::swap(t[cur[i]], t[j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}