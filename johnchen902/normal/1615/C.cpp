#include <stdio.h>
#include <algorithm>

constexpr int inf = 200000;

char a[100001], b[100001];

int solve1(int n) {
  int ans = 0, ones = 0;
  for (int i = 0; i < n; i++)
    if (a[i] != b[i]) {
      ans++;
      if (a[i] == '1')
        ones++;
    }
  return ans == ones * 2 ? ans : inf;
}

int solve2(int n) {
  int ans = 0, ones = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == b[i]) {
      ans++;
      if (a[i] == '1')
        ones++;
    }
  return ans == ones * 2 - 1 ? ans : inf;
}

int solve(int n) {
  int ans = std::min(solve1(n), solve2(n));
  return ans >= inf ? -1 : ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%s%s", &n, a, b);
    printf("%d\n", solve(n));
  }
}