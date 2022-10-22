#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
char str[maxn];
int n, dp[maxn], nxt[maxn];

int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && str[i] != str[j + 1]) j = nxt[j];
    j += str[i] == str[j + 1], nxt[i] = j;
  }
  for (int i = n; i; i--) {
    dp[i]++, dp[nxt[i]] += dp[i];
  }
  vector <int> ans1, ans2;
  for (int i = n; i; i = nxt[i]) {
    ans1.push_back(i);
    ans2.push_back(dp[i]);
  }
  reverse(ans1.begin(), ans1.end());
  reverse(ans2.begin(), ans2.end());
  int sz = ans1.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    printf("%d %d\n", ans1[i], ans2[i]);
  }
  return 0;
}