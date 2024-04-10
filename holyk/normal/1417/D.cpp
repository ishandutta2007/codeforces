#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

namespace FastIn {
 
template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar()); w = w * 10 + (c & 15));
  if (p) w = -w;
}
template <class T, class... Args>
inline void readInt(T &w, Args &... args) { readInt(w), readInt(args...); }
}  // namespace FastIn
using namespace FastIn;
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
constexpr int N(10005);
int n, a[N];

struct Data {
  int a, b, c;
};


int main() {
  int t; readInt(t);
  while(t--) {
    readInt(n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      readInt(a[i]);
      sum += a[i];
    }
    if (sum % n) {
      puts("-1");
      continue;
    }
    sum /= n;
    std::vector<Data> c; 
    for (int i = 2; i <= n; i++) {
      int delta = (i - (a[i] % i)) % i;
      if (delta) {
        c.push_back({1, i, delta});
        a[1] -= delta;
        a[i] += delta;
      }
      if (a[i]) {
        c.push_back({i, 1, a[i] / i});
        a[1] += a[i];
        a[i] = 0;
      }
    }
    for (int i = 2; i <= n; i++)
      c.push_back({1, i, sum});
    printf("%d\n", c.size());
    for (auto [x, y, z] : c) printf("%d %d %d\n", x, y, z);
  }
  return 0;
}