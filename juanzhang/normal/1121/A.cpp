#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int maxn = 105;
bool flg[maxn];
int n, m, k, a[maxn];

priority_queue <pii> Q[maxn];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    Q[x].push(pii(a[i], i));
  }
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x), flg[x] = 1;
  }
  for (int i = 1; i <= m; i++) {
    if (flg[Q[i].top().second]) k--;
  }
  printf("%d", k);
  return 0;
}