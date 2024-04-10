#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

int n;
char s[201];
int a[210], b[210];

int main() {
  scanf("%d %s", &n, s + 1);
  rep(i, 1, n) {
    scanf("%d %d", a + i, b + i);
  }
  int ans = 0;
  rep(i, 1, n) {
    ans += s[i] == '1';
  }
  rep(t, 1, 500000) {
    int v = 0;
    rep(i, 1, n) {
      if (t >= b[i] && (t - b[i]) % a[i] == 0) {
        s[i] ^= 1;
      }
    }
    rep(i, 1, n) {
      v += s[i] == '1';
    }
    ans = max(ans, v);
  }
  printf("%d", ans);
  return 0;
}