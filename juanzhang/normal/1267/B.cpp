#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}

template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}

const int maxn = 6e5 + 10;
int n, tot, cnt[maxn];
char a[maxn], str[maxn];

int main() {
  scanf("%s", a + 1);
  n = strlen(a + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != str[tot]) {
      str[++tot] = a[i], cnt[tot] = 1;
    } else {
      cnt[tot]++;
    }
  }
  if (tot == 1) {
    if (n > 1) {
      ans = n + 1;
    }
  } else {
    int pos = 0;
    for (int i = 1; i <= tot; i++) {
      if (i - 1 == tot - i && cnt[i] > 1) {
        pos = i;
      }
    }
    if (pos) {
      ans = cnt[pos] + 1;
      bool flg = 1;
      for (int l = pos - 1, r = pos + 1; l >= 1 && r <= tot; l--, r++) {
        flg &= str[l] == str[r] && cnt[l] + cnt[r] > 2;
      }
      if (!flg) ans = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}