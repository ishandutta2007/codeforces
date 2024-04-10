#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int n, c, a[maxn], sum[maxn];

vector <int> vec[maxn];

int main() {
  scanf("%d %d", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    vec[a[i]].push_back(i);
    sum[i] = sum[i - 1] + (a[i] == c);
  }
  int ans = 0;
  for (int i = 1; i < 500001; i++) {
    int val = 1 << 30, cnt = 0, res = 0;
    for (int pos : vec[i]) {
      val = min(val, cnt++ - sum[pos - 1]);
      res = max(res, cnt - sum[pos] - val);
    }
    ans = max(ans, res);
  }
  printf("%d", ans + sum[n]);
  return 0;
}