#include <bits/stdc++.h>

#define fst first
#define snd second

typedef long long int64;

const int N = 500000 + 10;

int n;
std::map<int, int> cnt;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  int64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    int num;
    std::cin >> num;
    ans += num;
    ++cnt[num];
  }
  static std::multiset<int> g;
  int cur = 0;
  for (std::map<int, int>::reverse_iterator it = cnt.rbegin(); it != cnt.rend(); ++it) {
    int x = it->fst, y = it->snd;
    int sz = std::min(cur, (cur + y) / 2), st = std::max(0, sz - y);
    static int pool[N];
    for (int i = sz - 1; i >= st; --i) {
      if (i < g.size()) {
        pool[i] = *g.begin();
        g.erase(g.begin());
      } else {
        pool[i] = 0;
      }
    }
    for (int i = st, j = cur - i; i < j && i < sz; ++i)
      if (pool[i] < x) pool[i] = x; else if (--j < sz) pool[j] = std::max(0, 2 * x - pool[i]);
    g.insert(pool + st, pool + sz);
    cur += y;
  }
  std::cout << ans - std::accumulate(g.begin(), g.end(), 0LL) << std::endl;
  return 0;
}