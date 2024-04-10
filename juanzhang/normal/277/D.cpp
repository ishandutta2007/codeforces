#include <bits/stdc++.h>
using namespace std;

typedef long double db;
const db eps = 1e-15;
const int maxn = 2010;
int n, m;
db dp[maxn], val[maxn];

struct node {
  int v1, v2, t1, t2; db p;
  
  inline bool operator < (const node &o) const {
    return t2 * p / (1 - p) < o.t2 * o.p / (1 - o.p);
  }
} a[maxn];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    double f;
    scanf("%d %d %d %d %lf", &a[i].v1, &a[i].v2, &a[i].t1, &a[i].t2, &f);
    a[i].p = f;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    dp[i] = -1e18, val[i] = 1e18;
  }
  for (int i = 1; i <= n; i++) {
    db p = a[i].p, tmp1, tmp2;
    int v1 = a[i].v1, v2 = a[i].v2;
    int t1 = a[i].t1, t2 = a[i].t2;
    for (int j = m; j >= t1; j--) {
      tmp1 = dp[j - t1] + v1, tmp2 = val[j - t1] + t1;
      if (dp[j] < tmp1 || (fabs(dp[j] - tmp1) < eps && val[j] > tmp2)) {
        dp[j] = tmp1, val[j] = tmp2;
      }
      if (j < t1 + t2) continue;
      tmp2 = dp[j - t1 - t2] + v1 + (1 - p) * v2;
      tmp1 = t1 + (1 - p) * (j - t1) + p * val[j - t1 - t2];
      if (dp[j] < tmp2 || (fabs(dp[j] - tmp2) < eps && val[j] > tmp1)) {
        dp[j] = tmp2, val[j] = tmp1;
      }
    }
  }
  int pos = 0;
  for (int i = 1; i <= m; i++) {
    if (dp[pos] < dp[i] || (fabs(dp[pos] - dp[i]) < eps && val[i] < val[pos])) {
      pos = i;
    }
  }
  printf("%.10lf %.10lf", (double) dp[pos], (double) val[pos]);
  return 0;
}