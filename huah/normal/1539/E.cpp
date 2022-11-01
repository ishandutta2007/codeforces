#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n, m, k[N], L[N], R[N];
int a[4][N];
int dp[N][2], pre[N][2];
int tot, ls[N * 20], rs[N * 20], mn[N * 20], mx[N * 20], rt[4];
int newnode() {
  tot++;
  ls[tot] = rs[tot] = 0;
  mn[tot] = inf;
  mx[tot] = -inf;
  return tot;
}
void Insert(int l, int r, int x, int v, int& now) {
  if (!now) now = newnode();
  mn[now] = min(mn[now], v);
  mx[now] = max(mx[now], v);
  if (l == r) return;
  int m = (l + r) >> 1;
  if (x <= m)
    Insert(l, m, x, v, ls[now]);
  else
    Insert(m + 1, r, x, v, rs[now]);
}
int querymn(int l, int r, int x, int y, int now) {
  if (r < x || l > y || !now) return inf;
  if (l >= x && r <= y) return mn[now];
  int m = (l + r) >> 1;
  return min(querymn(l, m, x, y, ls[now]), querymn(m + 1, r, x, y, rs[now]));
}
int querymx(int l, int r, int x, int y, int now) {
  if (r < x || l > y || !now) return -inf;
  if (l >= x && r <= y) return mx[now];
  int m = (l + r) >> 1;
  return max(querymx(l, m, x, y, ls[now]), querymx(m + 1, r, x, y, rs[now]));
}
void update(int x, int y, int v, int p) {
  if (v > dp[x][y]) {
    dp[x][y] = v;
    pre[x][y] = p;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k[i]);
    for (int j = 0; j < 4; j++) {
      scanf("%d", &a[j][i]);
      Insert(1, n, i, a[j][i], rt[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    L[i] = R[i] = i - 1;
    for (int j = 1 << 16; j; j >>= 1) {
      if (L[i] + j <= n) {
        int l = querymx(1, n, i, L[i] + j, rt[0]);
        int r = querymn(1, n, i, L[i] + j, rt[1]);
        if (k[i] >= l && k[i] <= r) L[i] += j;
      }
      if (R[i] + j <= n) {
        int l = querymx(1, n, i, R[i] + j, rt[2]);
        int r = querymn(1, n, i, R[i] + j, rt[3]);
        if (k[i] >= l && k[i] <= r) R[i] += j;
      }
    }
  }
  while (L[0] + 1 <= n && a[0][L[0] + 1] == 0) L[0]++;
  while (R[0] + 1 <= n && a[2][R[0] + 1] == 0) R[0]++;
  dp[0][0] = R[0];
  dp[0][1] = L[0];
  for (int i = 0; i < n; i++) {
    if (dp[i][0] >= i) {
      if (L[i + 1] >= i + 1) update(i + 1, 0, dp[i][0], 0);
      if (R[i + 1] >= i + 1) update(i + 1, 1, L[i], 0);
    }
    if (dp[i][1] >= i) {
      if (R[i + 1] >= i + 1) update(i + 1, 1, dp[i][1], 1);
      if (L[i + 1] >= i + 1) update(i + 1, 0, R[i], 1);
    }
  }
  int s = -1;
  if (dp[n][0] >= n) s = 0;
  if (dp[n][1] >= n) s = 1;
  if (s == -1)
    printf("No\n");
  else {
    printf("Yes\n");
    stack<int> ans;
    for (int i = n; i >= 1; i--) {
      ans.push(s);
      s = pre[i][s];
    }
    while (!ans.empty()) {
      printf("%d", ans.top());
      ans.pop();
      printf(ans.empty() ? "\n" : " ");
    }
  }
}