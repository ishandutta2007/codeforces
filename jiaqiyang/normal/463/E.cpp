#include <bits/stdc++.h>

const int N = 100000 + 10, lim = 2000000 + 10, root = 1;

int n, tcase;
int col[N], ans[N], dep[N];

std::vector<int> e[N];

void factor(int num, std::vector<int> &res) {
  res.clear();
  for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
      res.push_back(i);
      while (num % i == 0) num /= i;
    }
  }
  if (num > 1) res.push_back(num);
}

void solve(int a, int fa = 0) {
  static std::vector<int> res;
  static std::map<int, int> cur;
  std::map<int, int> buffer;
  factor(col[a], res);
  ans[a] = -1;
  for (auto i : res) {
    if ((!~ans[a] && cur[i]) || dep[cur[i]] > dep[ans[a]]) ans[a] = cur[i];
    buffer[i] = cur[i];
    cur[i] = a;
  }
  for (auto b : e[a]) if (b != fa) dep[b] = dep[a] + 1, solve(b, a);
  for (auto it : buffer) cur[it.first] = it.second;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &tcase);
  for (int i = 1; i <= n; ++i) scanf("%d", col + i);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  solve(root);
  while (tcase--) {
    int op, a, b;
    scanf("%d%d", &op, &a);
    switch (op) {
      case 1:
        printf("%d\n", ans[a]);
        break;
      case 2:
        scanf("%d", &b);
        col[a] = b;
        solve(root);
        break;
    }
  }
  return 0;
}