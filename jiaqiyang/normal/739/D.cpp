#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 300 + 10;

int nextInt() {
  char ch;
  while (ch = getchar(), !isdigit(ch) && ch != '?') {}
  if (ch == '?') return -1;
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

struct Info {
  int x, y;
  Info() {}
  Info(int _x, int _y): x(_x), y(_y) {}
} l[N], r[N];

inline bool check(int a, int b) { return a == b || a == -1 || b == -1; }

int n, m;

int ans[N];

int match[N];
bool flag[N], adj[N][N];

bool mx[N], my[N];

bool dfs(int a) {
  for (int b = 1; b <= m; ++b) {
    if (!adj[a][b] || flag[b] || my[b]) continue;
    flag[b] = true;
    if (!match[b] || dfs(match[b])) return match[b] = a, true;
  }
  return false;
}

int a[N], b[N];

bool solve(int p, int q) {
  m = 0;
  for (int i = 1; i <= n; ++i) {
    int u = a[i], v = b[i];
    if (i == p && q != -1) u = std::max(u, i), v = std::max(v, q);
    for (int j = u; j--;) {
      r[++m] = Info(0, i);
      if (m > n) return false;
    }
    for (int j = 1; j <= v; ++j) {
      r[++m] = Info(j, i);
      if (m > n) return false;
    }
  }
  memset(mx, 0, sizeof mx);
  memset(my, 0, sizeof my);
  memset(match, 0, sizeof match);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      adj[i][j] = (check(l[i].x, r[j].x) && check(l[i].y, r[j].y));
      if (!mx[i] && !my[j] && l[i].x == r[j].x && l[i].y == r[j].y) {
        match[j] = i;
        mx[i] = my[j] = true;
        ++cnt;
      }
    }
  }
  for (int i = 1; i <= n; ++i) if (!mx[i]) memset(flag, 0, sizeof flag), cnt += dfs(i);
  return cnt == m;
}

#include <cassert>

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) l[i].x = nextInt(), l[i].y = nextInt();
  int temp = -1;
  memset(b, -1, sizeof b);
  for (int i = 1; i <= n; ++i) {
    if (l[i].y != -1) {
      b[l[i].y] = std::max(b[l[i].y], std::max(l[i].x, 0));
      if (l[i].x == 0) ++a[l[i].y];
    } else if (l[i].x > 0) {
      temp = std::max(temp, l[i].x);
    }
  }
  for (int i = 1; i <= n; ++i) if (b[i] != -1) a[i] = std::max((a[i] + i - 1) / i, 1) * i;
  for (int i = 1; i <= n; ++i) {
    if (solve(i, temp)) {
      for (int j = 1; j <= n; ++j) if (l[j].y == -1 && l[j].x > 0) l[j].y = i;
      goto success;
    }
  }
  puts("-1");
  return 0;
success:
  for (int i = 1; i <= m; ++i) l[match[i]] = r[i];
  for (int i = 1; i <= n; ++i) if (l[i].x <= 0 && l[i].y == -1) l[i] = Info(0, 1); else if (l[i].x == -1) l[i].x = 1;
  for (int i = 1; i <= n; ++i) {
    if (ans[i]) continue;
    if (l[i].x == 0) {
      std::vector<int> cur;
      cur.push_back(i);
      for (int j = i + 1; j <= n && cur.size() < l[i].y; ++j) if (l[j].x == 0 && l[j].y == l[i].y) cur.push_back(j);
      for (int j = 0; j < cur.size(); ++j) ans[cur[j]] = cur[(j + 1) % cur.size()];
      assert(cur.size() == l[i].y);
    } else {
      for (int j = 1; j <= n; ++j) if (l[i].y == l[j].y && l[i].x == l[j].x + 1) ans[i] = j;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}