#include <bits/stdc++.h>

template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar()); w = w * 10 + (c & 15));
  if (p) w = -w;
}
template <class T, class... U>
inline void readInt(T &w, U &... a) { readInt(w), readInt(a...); }
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

typedef long long LL;
typedef std::pair<int, int> PII;

int d[6], s[7][7];
int main() {
  int t; readInt(t);
  while (t--) {
    int x, y; readInt(x, y);
    for (int i = 0; i < 6; i++) readInt(d[i]);
    memset(s, 0x3f, sizeof s);
    for (int i = 0; i < 7; i++) { 
      s[i][i] = 0;
      if (i < 6) s[6][i] = d[i];
    }
    s[0][1] = d[2];
    s[1][2] = d[3];
    s[2][3] = d[4];
    s[3][4] = d[5];
    s[4][5] = d[0];
    s[5][0] = d[1];

    s[0][5] = d[4];
    s[5][4] = d[3];
    s[4][3] = d[2];
    s[3][2] = d[1];
    s[2][1] = d[0];
    s[1][0] = d[5];
    for (int k = 0; k < 7; k++)
      for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
          smin(s[i][j], s[i][k] + s[k][j]);
    for (int i = 0; i < 6; i++)
      d[i] = s[6][i];
    LL ans = 0;
    if (x > 0 && y > 0) {
      int k = std::min(x, y);
      ans += d[0] * (LL)k;
      x -= k, y -= k;
    } else if (x < 0 && y < 0) {
      int k = std::min(-x, -y);
      ans += d[3] * (LL)k;
      x += k, y += k;
    }
    if (x >= 0)
      ans += d[5] * (LL)x;
    else
      ans += d[2] * (LL)(-x);
    if (y >= 0)
      ans += d[1] * (LL)y;
    else
      ans += d[4] * (LL)(-y);
    printf("%lld\n", ans);
  }
  return 0;
}