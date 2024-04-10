#include <algorithm>
#include <stdio.h>
#include <vector>

int a[100000];
int b[100000];
int c[100000];

int ans[100000];

bool solve(int n, int m) {
  std::vector<std::vector<int>> v(n);
  for (int i = 0; i < n; i++)
    if (a[i] != b[i])
      v[b[i]].push_back(i);

  for (int i = m - 1; i >= 0; i--)
    if (v[c[i]].empty()) {
      if (i == m - 1) {
        int j = std::find(b, b + n, c[i]) - b;
        if (j == n) return false;
        ans[i] = j;
      } else {
        ans[i] = ans[m - 1];
      }
    } else {
      ans[i] = v[c[i]].back();
      v[c[i]].pop_back();
    }

  return std::all_of(v.begin(), v.end(),
      [](const std::vector<int> &s) { return s.empty(); });
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++)
      scanf("%d", a + i), a[i]--;
    for (int i = 0; i < n; i++)
      scanf("%d", b + i), b[i]--;
    for (int i = 0; i < m; i++)
      scanf("%d", c + i), c[i]--;

    if (solve(n, m)) {
      puts("YES");
      for (int i = 0; i < m; i++)
        printf("%d%c", ans[i] + 1, i == m - 1 ? '\n' : ' ');
    } else {
      puts("NO");
    }
  }
}