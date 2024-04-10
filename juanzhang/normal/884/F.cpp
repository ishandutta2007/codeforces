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

char str[105];
int n, cnt[26], cost[105];

int main() {
  int ans = 0, tot = 0;
  scanf("%d %s", &n, str + 1);
  rep(i, 1, n) cost[i] = read(), ans += cost[i];
  rep(i, 1, n / 2) if (str[i] == str[n - i + 1]) {
    cnt[str[i] -'a']++, tot++;
    ans -= min(cost[i], cost[n - i + 1]);
  }
  int x = -1;
  rep(i, 0, 25) if (2 * cnt[i] > tot) {
    x = i;
  }
  if (x == -1) {
    return printf("%d", ans), 0;
  }
  multiset <int> S;
  rep(i, 1, n / 2) if (str[i] != str[n - i + 1] && str[i] != 'a' + x && str[n - i + 1] != 'a' + x) {
    S.insert(min(cost[i], cost[n - i + 1]));
  }
  rep(T, 1, 2 * cnt[x] - tot) {
    ans -= *S.begin(), S.erase(S.begin());
  }
  cout << ans;
  return 0;
}