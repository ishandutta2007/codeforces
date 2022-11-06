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

constexpr int N(2e5 + 5);
int n;
std::string s;

int c[N];
inline void add(int p, int x) {
  for (; p; p -= p & -p) c[p] += x;
}
inline int ask(int p) {
  int ans = 0;
  for (; p <= n; p += p & -p) ans += c[p];
  return ans;
}
std::vector<int> g[26];
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> s;
  for (int i = 0; i < n; i++) {
    g[s[i] - 'a'].push_back(i + 1);
    add(i + 1, 1);
  }
  LL ans = 0;
  
  for (int i = 0; i < n; i++) {
    int r = g[s[i] - 'a'].back();
    g[s[i] - 'a'].pop_back();
    ans += ask(r) - 1;
    add(r, -1);
  }
  std::cout << ans;
  return 0;
}