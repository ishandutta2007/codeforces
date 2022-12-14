#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

const int N = 24;

int n, c[N], size[N], cnt[N];

bool Solve(int cur, int rem) {
  if (cur == n - 1) return cnt[cur] + rem > 1 && size[cur] + rem + 1 == c[cur];
  int temp = c[cur] - 1 - size[cur];
  if ((rem -= temp) < 0 || temp + cnt[cur] < 2) return false;
  for (int fa = cur + 1; fa < n; ++fa) {
    if (size[fa] + c[cur] < c[fa]) {
      size[fa] += c[cur];
      ++cnt[fa];
      if (Solve(cur + 1, rem)) return true;
      --cnt[fa];
      size[fa] -= c[cur];
    }
  }
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", c + i);
  std::sort(c, c + n);
  int cnt = std::count_if(c, c + n, std::bind1st(std::equal_to<int>(), 1));
  if (cnt == 1 && n == 1) {
    puts("YES");
  } else if (cnt < (n + 1) / 2) {
    puts("NO");
  } else {
    n = std::remove_if(c, c + n, std::bind1st(std::equal_to<int>(), 1)) - c;
    puts(Solve(0, cnt) ? "YES" : "NO");
  }
  return 0;
}