#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 1e5 + 10;
char str[maxn];
int n, cnt[26], flg[26];

bool check(int mid) {
  memset(flg, 1, sizeof flg);
  memset(cnt, 0, sizeof cnt);
  rep(i, 1, mid) {
    cnt[str[i] - 'a']++;
  }
  rep(i, 0, 25) if (!cnt[i]) {
    flg[i] = 0;
  }
  rep(i, mid + 1, n) {
    ++cnt[str[i] - 'a'];
    int lst = str[i - mid] - 'a';
    if (!--cnt[lst]) {
      flg[lst] = 0;
    }
  }
  rep(i, 0, 25) if (flg[i]) {
    return 1;
  }
  return 0;
}

int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    check(mid) ? r = mid : l = mid + 1;
  }
  cout << l;
  return 0;
}