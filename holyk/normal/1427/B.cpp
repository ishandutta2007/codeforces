#include <bits/stdc++.h>

template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar()); w = w * 10 + (c & 15));
  if (p) w = -w;
}
template <class T, class... Args>
inline void readInt(T &w, Args &... args) { readInt(w), readInt(args...); }
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
typedef long long LL;

char s[100005];
std::priority_queue<int> q;
int main() {
  int t; readInt(t);
  while (t--) {
    int n, k; readInt(n, k);
    scanf("%s", s + 1);
    while (!q.empty()) q.pop();
    int c = 1, ans = 0, nw = 0;
    while (c <= n && s[c] == 'L') c++;
    for (int i = c; i <= n; i++) {
      if (s[i] == 'W') {
        if (nw) {
          q.push(-nw);
          nw = 0;
        }
        ans++;
        if (s[i - 1] == 'W') ans++;
      } else {
        nw++; 
      }
    }
    if (!ans) {
      smin(k, c - 1);
      printf("%d\n", k ? k * 2 - 1 : 0);
      continue;
    }
    while (!q.empty()) {
      if (k + q.top() < 0) {
        ans += k << 1;
        k = 0;
        break;
      }
      ans += -q.top() << 1 | 1;
      k += q.top(); q.pop();
    }
    ans += std::min(k, c + nw - 1)  << 1;
    printf("%d\n", ans);
  }
  return 0;
}