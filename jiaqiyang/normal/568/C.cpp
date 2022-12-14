#include <cstdio>
#include <bitset>
#include <string>
#include <iostream>

const int N = 400 + 10;

std::string type;

int n, l;
std::bitset<N> mask[N];

std::string s;

inline int pos(int a, int b) { return (a << 1) | b; }
inline int get(char ch) { return type[ch - 'a'] == 'V'; }

bool check(const std::string &cur, int len) {
  std::bitset<N> temp;
  for (int i = 0; i <= len; ++i) temp |= mask[pos(i, get(cur[i]))];
  for (int i = 0; i < n; ++i) if (temp[pos(i, 0)] && temp[pos(i, 1)]) return false;
  return true;
}

int main() {
  int m;
  std::cin >> type >> n >> m;
  l = type.length();
  while (m--) {
    int p1, p2;
    char t1, t2;
    scanf("%d %c%d %c", &p1, &t1, &p2, &t2);
    int a = pos(p1 - 1, t1 == 'V'), b = pos(p2 - 1, t2 == 'V');
    mask[a][b] = 1;
    mask[b ^ 1][a ^ 1] = 1;
  }
  for (int i = 0; i < 2 * n; ++i) mask[i][i] = 1;
  for (int k = 0; k < 2 * n; ++k)
    for (int i = 0; i < 2 * n; ++i)
      if (mask[i][k]) mask[i] |= mask[k];
  std::cin >> s;
  if (check(s, n - 1)) {
    std::cout << s << '\n';
    return 0;
  }
  for (int i = n - 1; i >= 0; --i) {
    std::string t = s;
    for (int j = s[i] - 'a' + 1; j < l; ++j) {
      t[i] = j + 'a';
      if (check(t, i)) {
        for (int k = i + 1; k < n; ++k) {
          for (int a = 0; a < l; ++a) {
            t[k] = a + 'a';
            if (check(t, k)) break;
          }
        }
        if (!check(t, n - 1)) puts("-1"); else std::cout << t << '\n';
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}