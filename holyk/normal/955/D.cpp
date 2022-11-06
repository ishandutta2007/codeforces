#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e6 + 5);

int n, m, k;
std::vector<int> g[N];
int in[N], out[N], cnt;
void dfs(int x) {
  in[x] = ++cnt;
  for (int y : g[x]) {
    dfs(y);
  }
  out[x] = cnt;
}
int c[N];
void add(int p, int x) {
  for (; p <= cnt; p += p & -p) {
    c[p] += x;
  }
}
int ask(int p) {
  int r = 0;
  for (; p; p -= p & -p) {
    r += c[p];
  }
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s, t;
  std::cin >> n >> m >> k >> s >> t;
  std::vector<int> p(m), q(m + n + 1); 
  p[0] = -1;
  for (int i = 1, j; i < m; i++) {
    for (j = p[i - 1]; j >= 0 && t[j + 1] != t[i]; j = p[j]) ;
    p[i] = j + (t[j + 1] == t[i]);
  }
  q[m - 1] = m;
  g[m].push_back(m - 1);
  for (int i = m - 2, j; i >= 0; i--) {
    for (j = q[i + 1]; j < m && t[j - 1] != t[i]; j = q[j]) ;
    q[i] = j - (t[j - 1] == t[i]);
    g[q[i]].push_back(i);
  }
  for (int i = n - 1, j = m; i >= 0; i--) {
    for (; j < m && t[j - 1] != s[i]; j = q[j]) ;
    j -= t[j - 1] == s[i];  
    if (j == 0) {
      if (i >= n - k && k - 1 < n - k) {
        std::cout << "Yes\n" << 1 << " " << n - k + 1 << "\n";
        return 0;
      }
      j = q[j];
    }
    g[j].push_back(i + m + 1);
    q[i + m + 1] = j;
  }
  dfs(m);
  std::vector<int> vis(m);
  for (int i = 0, j = -1; i < n - k; i++) {
    for (; j >= 0 && t[j + 1] != s[i]; j = p[j]) ;
    j += t[j + 1] == s[i];
    if (j == m - 1) {
      if (i < k && k - 1 < n - k) {
        std::cout << "Yes\n" << 1 << " " << n - k + 1 << "\n";
        return 0;
      }
      j = p[j];
    }
    if (i < k - 1) continue;
    for (int k = j; k >= m - ::k - 1 && vis[k] <= 0; k = p[k]) {
      vis[k] = i + 1;
      if (k < ::k) {
        add(in[k + 1], 1), add(out[k + 1] + 1, -1);
      } else {
        vis[k] = -vis[k];
      }
    }
    if (ask(in[i + m + 2])) {
      std::cout << "Yes\n";
      int x = q[i + m + 2];
      for (; x < m && vis[x - 1] <= 0; x = q[x]) ;
      std::cout << vis[x - 1] - k + 1 << " " << i + 2 << "\n";
      return 0;
    }
  }
  std::cout << "No\n";
  return 0;
}