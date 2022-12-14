#include <cctype>
#include <stdio.h>
#include <map>
#include <vector>

const int N = 400000 + 10;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n;
std::vector<int> adj[N];

int size[N];

void dfs(int a, int fa = -1) {
  size[a] = 1;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != fa) {
      dfs(b, a);
      size[a] += size[b];
    }
  }
}

int ans[N];

int s;

void solve(int a, int fa) {
  int cur = n - s - size[a];
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != fa) {
      cur = std::max(cur, size[b]);
      solve(b, a);
    }
  }
  if (2 * cur <= n) ans[a] = 1; else ans[a] = 0;
}

int main() {
  n = nextInt();
  for (int i = n - 1; i--;) {
    int a = nextInt(), b = nextInt();
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  int r = 1;
  while (1) {
    bool flag = false;
    for (int i = 0; i < adj[r].size(); ++i) {
      int b = adj[r][i];
      if (size[b] < size[r] && 2 * size[b] >= n) {
        r = b;
        flag = true;
        break;
      }
    }
    if (!flag) break;
  }
  dfs(r);
  ans[r] = 1;
  int s1 = 0, s2 = 0;
  for (int i = 0; i < adj[r].size(); ++i) {
    int b = adj[r][i];
    if (size[b] > s1) s2 = s1, s1 = size[b]; else s2 = std::max(s2, size[b]);
  }
  for (int i = 0; i < adj[r].size(); ++i) {
    int b = adj[r][i];
    if (size[b] == s1) {
      s = s2;
      if (2 * (n - s1) <= n) s = std::max(s, n - s1);
      solve(b, r);
    } else {
      s = s1;
      solve(b, r);
    }
  }
  for (int i = 1; i <= n; ++i) {
    putchar('0' + ans[i]);
    putchar(i == n ? '\n' : ' ');
  }
  return 0;
}