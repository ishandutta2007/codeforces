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

typedef long long ll;
int n;
bool flg[105];
char str[105];

bool check(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
  cin >> n;
  scanf("%s", str + 1);
  rep(i, 1, n - 1) {
    if (!check(str[i]) || flg[i]) continue;
    int j = i;
    while (j < n && check(str[j + 1])) j++;
    rep(k, i + 1, j) flg[k] = 1;
  }
  rep(i, 1, n) if (!flg[i]) putchar(str[i]);
  return 0;
}