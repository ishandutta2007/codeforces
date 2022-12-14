#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Info;

const int N = 200000 + 10, E = 10 * N;

int nextInt() {
  char ch;
  while (ch = getchar(), ch != '-' && !isdigit(ch)) {}
  bool flag = (ch == '-');
  if (flag) ch = getchar();
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return flag ? -res : res;
}

int n, m;

int adj[N], to[E], next[E], tag[E];

void link(int a, int b, int c) {
  static int cnt = 2;
  to[cnt] = b;
  next[cnt] = adj[a];
  tag[cnt] = c;
  adj[a] = cnt++;
}

std::vector<int> pool[N];

bool flag[N];
int ans[N];

inline bool sgn(int x) { return x > 0; }

void dfs(int a) {
  for (int i = adj[a]; i; i = next[i]) {
    int b = to[i], c = abs(tag[i]);
    if (!flag[b] && ans[c] == -1) flag[b] = true, ans[c] = sgn(tag[i]), dfs(b);
  }
}

bool mark[N];

bool find(int a, int e = -1) {
  if (mark[a]) return false;
  mark[a] = true;
  for (int i = adj[a]; i; i = next[i]) {
    if ((i ^ 1) == e) continue;
    int b = to[i];
    if (mark[b] || find(b, i)) {
      dfs(b);
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int k = nextInt(); k--;) {
      int a = nextInt();
      if (a > 0) pool[a].push_back(i); else pool[-a].push_back(-i);
    }
  }
  for (int i = 1; i <= m; ++i) ans[i] = -1;
  for (int i = 1; i <= m; ++i) {
    if (pool[i].size() == 2) {
      int x = pool[i][0], y = pool[i][1];
      if (sgn(x) != sgn(y)) {
        int p = abs(x), q = abs(y);
        link(p, q, sgn(y) ? i : -i), link(q, p, sgn(x) ? i : -i);
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (pool[i].empty()) {
      ans[i] = 0;
      continue;
    }
    if (pool[i].size() == 1) {
      int x = pool[i][0];
      ans[i] = sgn(x);
      int p = abs(x);
      flag[p] = true, dfs(p);
    }
    if (pool[i].size() == 2) {
      int x = pool[i][0], y = pool[i][1];
      if (sgn(x) == sgn(y)) {
        ans[i] = sgn(x);
        int p = abs(x), q = abs(y);
        flag[p] = true, dfs(p);
        flag[q] = true, dfs(q);
      }
    }
  }
  for (int i = 1; i <= n; ++i) find(i);
  for (int i = 1; i <= n; ++i) if (!flag[i]) return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i <= m; ++i) if (ans[i] == -1) ans[i] = 0;
  for (int i = 1; i <= m; ++i) putchar(ans[i] + '0');
  putchar('\n');
  return 0;
}