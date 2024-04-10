#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::string s;
  std::cin >> s >> m;
  n = s.length();
  std::vector<int> a(n, 63), cnt(64), p(64);
  auto out = [](int x) {
    std::cout << std::bitset<6>(x) << "\n";
  };
  for (char x : s) cnt[1 << x - 'a']++;
  for (int i = 0; i < 64; i++) cnt[i] = cnt[i & -i] + cnt[i & i - 1];
  while (m--) {
    int x;
    std::string s;
    std::cin >> x >> s;
    x--;
    a[x] = 0;
    for (char c : s) a[x] |= 1 << c - 'a';
  }
  for (int i = 0; i < 64; i++) {
    for (int x : a) if (x & i) p[i]++;
    if (p[i] < cnt[i]) return puts("Impossible"), 0;
  }
  for (int x : a) {
    for (int i = 0; i < 64; i++) if (x & i) p[i]--;
    for (int i = 0; i < 6; i++) {
      if (x >> i & 1 ^ 1) continue;
      bool ok = true;
      cnt[1 << i]--;
      for (int j = 0; j < 64; j++) {
        cnt[j] = cnt[j & -j] + cnt[j & j - 1];
        if (p[j] < cnt[j]) {
          ok = false;
        }
      }
      if (ok) {
        std::cout << char(i + 'a');
        break;
      }
      cnt[1 << i]++;
    }
  }
  return 0;
}