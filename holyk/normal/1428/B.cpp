#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(3e5 + 5);

int n, in[N], cnt, ans;
std::vector<int> g[N];
void dfs(int x) {
  static int s[N], low[N];
  static bool ins[N];
  in[x] = low[x] = ++cnt;
  s[++s[0]] = x, ins[x] = 1;
  for (int y : g[x]) {
    if (!in[y]) {
      dfs(y);
      smin(low[x], low[y]);
    } else if (ins[y]) {
      smin(low[x], in[y]);
    }
  }
  if (in[x] == low[x]) {
    if (s[s[0]] == x) {
      ins[x] = 0;
      s[0]--;
      return;
    }
    int z;
    do {
      z = s[s[0]--];
      ++ans;
      ins[z] = 0;
    } while (z != x);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> n >> s;
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < n; i++) {
      switch(s[i]) {
      case '>': {
        g[i].push_back((i + 1) % n);
        break;
      }
      case '<': {
        g[(i + 1) % n].push_back(i);
        break;
      }
      case '-': {
        g[i].push_back((i + 1) % n);
        g[(i + 1) % n].push_back(i);
        break;
      }
      }
    }
    cnt = ans = 0;
    memset(in, 0, n << 2);
    for (int i = 0; i < n; i++)
      if (!in[i]) dfs(i);
    std::cout << ans << "\n";
  }
  return 0;
}