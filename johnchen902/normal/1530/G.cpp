#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <numeric>

int ans, al[8001], ar[8001];

void op(int *a, int i, int j, int c) {
  al[ans] = i + std::accumulate(a, a + i + 1, 0) - std::max(c, 0);
  ar[ans] = j + std::accumulate(a, a + j, 0) - std::min(c, 0);
  if (ar[ans] - al[ans] <= 1) return;
  ans++;
  a[i] -= c;
  a[j] += c;
  std::reverse(a + i + 1, a + j);
}

void normalize(int *a, int m, int k) {
  // m > k
  for (int i = 0; i < m - k - 1; i++)
    op(a, i, i + k, a[i]);

  if (k % 2) {
    for (int i = 0; i < k; i++) {
      op(a, m - k - 1, m - 1, a[m - k - 1]);
      op(a, m - k, m, a[m - k]);
    }
  } else {
    for (int i = 0; i < k; i += 2) {
      op(a, m - k - 1, m - 1, -a[m - 1]);
      op(a, m - k, m, a[m - k]);
    }
  }
}

char s[2001], t[2001];
int a[2001], b[2001];

bool solve() {
  int n, k;
  scanf("%d%d%s%s", &n, &k, s, t);
  int m = std::count(s, s + n, '1');
  if (m != std::count(t, t + n, '1')) return false;

  ans = 0;
  if (strcmp(s, t) == 0) return true;
  if (k == 0 || k > m) return false;

  std::fill_n(a, m + 1, 0);
  for (int i = 0, j = 0; i < n; i++)
    (s[i] == '1' ? j : a[j])++;
  std::fill_n(b, m + 1, 0);
  for (int i = 0, j = 0; i < n; i++)
    (t[i] == '1' ? j : b[j])++;

  if (k == m) {
    if (a[0] + a[k] != b[0] + b[k])
      return false;
    op(a, 0, k, a[0] - b[0]);
    if (std::equal(a, a + m + 1, b))
      return true;
    op(a, 0, k, 0);
    return std::equal(a, a + m + 1, b);
  }

  normalize(a, m, k);
  int oldans = ans;
  normalize(b, m, k);
  std::reverse(al + oldans, al + ans);
  std::reverse(ar + oldans, ar + ans);
  return std::equal(a, a + m + 1, b);
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    if (solve()) {
      printf("%d\n", ans);
      // fprintf(stderr, "Step %d: %s\n", 0, s);
      for (int i = 0; i < ans; i++) {
        printf("%d %d\n", al[i] + 1, ar[i]);
        // std::reverse(s + al[i], s + ar[i]);
        // fprintf(stderr, "Step %d: %s\n", i + 1, s);
      }
    } else {
      puts("-1");
    }
  }
}