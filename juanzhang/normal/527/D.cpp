#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, tid[maxn], val[maxn], sum[maxn], data[maxn];

struct node {
  int x, w;
} a[maxn];

inline bool cmp(int x, int y) {
  return val[x] < val[y];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].x, &a[i].w);
    val[i] = a[i].x + a[i].w, tid[i] = i;
  }
  int ans = 1;
  fill(sum + 1, sum + n + 1, 1);
  sort(tid + 1, tid + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    data[i] = val[tid[i]];
  }
  for (int i = 2; i <= n; i++) {
    int pos = upper_bound(data + 1, data + i, a[tid[i]].x - a[tid[i]].w) - data - 1;
    sum[i] = max(sum[i - 1], sum[pos] + 1), ans = max(ans, sum[i]);
  }
  printf("%d", ans);
  return 0;
}