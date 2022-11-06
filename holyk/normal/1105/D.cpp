#include <bits/stdc++.h>
#include <cctype>
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

const PII D[] = {PII(-1, 0), PII(0, 1), PII(1, 0), PII(0, -1)};
char a[1001][1001];
int n, m, p;
struct Player {
  std::queue<PII> q, tmp;
  int cnt, id, ans;
  void extend() {
    for (int i = 0; i < cnt; i++) {
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : D) {
          dx += x, dy += y;
          if (dx < 1 || dy < 1 || dx > n || dy > m) continue;
          if (a[dx][dy] == '.') a[dx][dy] = id + '0', tmp.push({dx, dy}), ans++;
        }
      }
      if (tmp.empty()) break;
      while (!tmp.empty()) {
        q.push(tmp.front());
        tmp.pop();
      }
    }
    
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m >> p;
  std::vector<Player> v(p);
  for (int i = 0; i < p; i++) std::cin >> v[i].cnt, v[i].id = i + 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] + 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!std::isdigit(a[i][j])) continue;
      auto &u = v[a[i][j] - '1'];
      u.ans++;
      u.q.push({i, j});
    }
  for (int i = 1; i <= n * m; i++) for (auto &u : v) u.extend();
  for (auto &u : v) std::cout << u.ans << " ";
  return 0;
}