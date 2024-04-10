#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;
typedef unsigned long long u64;

const int N = 100000 + 10, S = 26, B = 31;

int n;
char s[N];

u64 val[N], mem[N];

inline u64 hash(int l, int r) { return l > r ? 0 : (val[r] - val[l - 1] * mem[r - l + 1]); }

int len[S];
int sum[S][N];

inline int get(int p, int l, int r) { return sum[p][r] - sum[p][l - 1]; }

int bSearch(int p, int q, int r) {
  int l = 0;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (hash(p, p + mid - 1) == hash(q, q + mid - 1)) l = mid; else r = mid - 1;
  }
  return l;
}

int main() {
  mem[0] = 1;
  for (int i = 1; i < N; ++i) mem[i] = B * mem[i - 1];
  len[0] = 1;
  for (int i = 1; i < S; ++i) len[i] = 2 * len[i - 1] + 1;
  scanf(" %s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) val[i] = B * val[i - 1] + s[i] - 'a' + 1;
  static bool flag[S][N];
  for (int i = 1; i <= n; ++i) flag[0][i] = true;
  for (int i = 0; i < S; ++i)
    for (int j = 1; j <= n; ++j)
      sum[i][j] = sum[i][j - 1] + (s[j] - 'a' == i);
  static i64 det[N][S], tag[N];
  i64 ans = n;
  for (int j = 1; j < S; ++j) {
    int a = len[j - 1], b = len[j];
    for (int i = 1; i + b - 1 <= n; ++i) {
      if (!flag[j - 1][i] && !flag[j - 1][i + a + 1]) continue;
      int t = bSearch(i, i + a + 1, a);
      if (hash(i + t + 1, i + a - 1) != hash(i + a + 1 + t + 1, i + b - 1)) continue;
      if (t < a) {
        int p = i + t, q = i + a + 1 + t;
        //s[p] = s[q]
        if (flag[j - 1][i + a + 1] && get(s[i + a] - 'a', i, i + b - 1) - (s[p] == s[i + a]) + (s[q] == s[i + a]) == 1) det[p][s[q] - 'a'] += (i64)b * b;
        if (flag[j - 1][i] && get(s[i + a] - 'a', i, i + b - 1) - (s[q] == s[i + a]) + (s[p] == s[i + a]) == 1) det[q][s[p] - 'a'] += (i64)b * b;
      } else {
        if (!flag[j - 1][i] || !flag[j - 1][i + a + 1]) continue;
        if (get(s[i + a] - 'a', i, i + b - 1) == 1) {
          flag[j][i] = true;
          tag[i] -= (i64)b * b;
          tag[i + b] += (i64)b * b;
          ans += (i64)b * b;
          for (int k = 0; k < S; ++k) if (get(k, i, i + b - 1) - (s[i + a] - 'a' == k) == 0) det[i + a][k] += (i64)b * b;
        } else {
          for (int k = 0; k < S; ++k) if (!get(k, i, i + b - 1)) det[i + a][k] += (i64)b * b;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) tag[i] += tag[i - 1];
  i64 temp = 0;
  for (int i = 1; i <= n; ++i) temp = std::max(temp, tag[i] + *std::max_element(det[i], det[i] + S));
  printf("%lld\n", ans + temp);
  return 0;
}