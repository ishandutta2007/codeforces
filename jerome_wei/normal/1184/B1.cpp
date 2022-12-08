#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct base {
  int power, gold;
  bool operator<(const base& a) const { return power < a.power; }
} b[N];

int sp[N], sum[N], qaq[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &sp[i]);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].power, &b[i].gold);
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + b[i].gold;
    qaq[i] = b[i].power;
  }
  for (int i = 1; i <= n; i++) {
    int qwq = upper_bound(qaq + 1, qaq + m + 1, sp[i]) - qaq - 1;
    printf("%d ", sum[qwq]);
  }
}