#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

const int maxn = 2e5 + 10;
int n, a[maxn], s[maxn];

int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i), a[i] = a[i] < 0 ? -1 : 1;
  rep(i, 1, n) {
    s[i] = s[i - 1] + (a[i] == -1);
  }
  int c = 0;
  long long s1 = 0, s2 = 0;
  rep(i, 1, n) {
    if (s[i] & 1) {
      s1 += i - c, s2 += c;
    } else {
      s1 += c, s2 += i - c;
    }
    c += s[i] & 1;
  }
  printf("%I64d %I64d", s1, s2);
  return 0;
}