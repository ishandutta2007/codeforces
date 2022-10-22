#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

const int maxn = 205;
int n;
char a[maxn];

bool check(char c) {
  vector <int> ans;
  for (int i = 1, j; i <= n; i++) {
    if (a[i] != c) {
      for (j = i + 1; j <= n && a[j] == c; j++);
      if (j > n) return 0;
      for (int k = i; k < j; k++) {
        ans.push_back(k);
      }
      i = j;
    }
  }
  printf("%d\n", (int) ans.size());
  for (int x : ans) printf("%d ", x);
  return 1;
}

int main() {
  scanf("%d %s", &n, a + 1);
  bool flg = 1;
  rep(i, 1, n - 1) {
    flg &= a[i] == a[i + 1];
  }
  if (flg) {
    return puts("0"), 0;
  }
  if (!check('B') && !check('W')) {
    puts("-1");
  }
  return 0;
}