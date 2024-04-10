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

char s[1000005];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  printf("3\nL 2\nR 2\nR %d\n", n + n - 1);
  return 0;
}