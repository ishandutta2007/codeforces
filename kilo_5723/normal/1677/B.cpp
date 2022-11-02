#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
int cnt[maxn], ans[maxn], tmp[maxn];
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    fill(cnt, cnt + m, 0);
    fill(ans, ans + n * m, 0);
    int sum = 0;
    for (int i = 0; i < n * m; i++) {
      if (s[i] == '1') {
        if (!cnt[i % m]) sum++;
        cnt[i % m] = 1;
      }
      ans[i] = sum;
    }
    fill(tmp, tmp + n * m + 1, 0);
    for (int i = 1; i <= n * m; i++) tmp[i] = tmp[i - 1] + (s[i-1] == '1');
    // for (int i = 1; i <= n * m; i++)
    //   printf("%d%c", tmp[i], i < n * m ? ' ' : '\n');
    for (int i = n * m; i; i--)
      tmp[i] = (tmp[i] - (i < m ? 0 : tmp[i - m]) > 0);
    // for (int i = 1; i <= n * m; i++)
    //   printf("%d%c", tmp[i], i < n * m ? ' ' : '\n');
    for (int i = m; i <= n * m; i++) tmp[i] += tmp[i - m];
    // for (int i = 1; i <= n * m; i++)
    //   printf("%d%c", tmp[i], i < n * m ? ' ' : '\n');
    // for (int i = 0; i < n * m; i++)
    //   printf("%d%c", ans[i], i < n * m - 1 ? ' ' : '\n');
    for (int i = 1; i <= n * m; i++) ans[i - 1] += tmp[i];
    for (int i = 0; i < n * m; i++)
      printf("%d%c", ans[i], i < n * m - 1 ? ' ' : '\n');
  }
  return 0;
}