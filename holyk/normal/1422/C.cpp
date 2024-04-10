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

const int N(1e5 + 5), P(1e9 + 7);
char s[N];
int n, pw[N];
int calc(int x) {
  int ans = pw[x];
  for (int i = 1; i <= x; i++)
    ans = (ans + 1LL * (x - i + 1) * pw[x - i]) % P;
  return ans;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  pw[0] = 1;
  for (int i = 1; i <= n; i++)
    pw[i] = 10LL * pw[i - 1] % P;
  int now = 0, cnt = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    cnt = (cnt + 1LL * i * pw[i - 1]) % P;
  }
  for (int i = 0; i < n; i++) {
    now = s[i] - '0'; 
    cnt = (cnt - 1LL * pw[n - i - 1] * (n - i)) % P;
    if (!now) continue;
  //  printf("! %d\n", cnt);
  //  assert((cnt + pw[n - i - 1] - calc(n - i - 1)) % P == 0);
    ans = (ans + 1LL * now * (cnt + pw[n - i - 1] * (1LL * i * (i + 1) / 2 % P) % P)) % P;
  }
  std::cout << (ans + P) % P;
  return 0;
}