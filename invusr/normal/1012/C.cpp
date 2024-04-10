#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

const int MaxN = 5000;
const int INF = 0x3f3f3f3f;

int n;
int a[MaxN + 2];

int f[MaxN + 1][MaxN / 2 + 1];
int g[MaxN + 1][MaxN / 2 + 1];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int m = (n - 1) / 2 + 1;
  memset(f, INF, sizeof(f));
  memset(g, INF, sizeof(g));
  f[0][0] = g[0][0] = 0;
  f[1][0] = g[1][0] = 0;
  f[1][1] = g[1][1] = max(0, a[2] - a[1] + 1);
  f[2][0] = g[2][0] = 0;
  f[2][1] = g[2][1] = max(0, a[3] - a[2] + 1) + max(0, a[1] - a[2] + 1);
  g[2][1] = min(g[2][1], g[1][1]);
  for (int i = 3; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      int left = min(a[i - 1], a[i - 2] - 1);
      f[i][j] = min(f[i][j], g[i - 3][j - 1] + max(0, a[i + 1] - a[i] + 1) + max(0, a[i - 1] - a[i] + 1));
      if (j > 1) {
        f[i][j] = min(f[i][j], f[i - 2][j - 1] + max(0, a[i + 1] - a[i] + 1) + max(0, left - a[i] + 1));
      }
      g[i][j] = min(g[i - 1][j], f[i][j]);
    }
  }

  for (int i = 1; i <= m; ++i) {
    cout << g[n][i] << ' ';
  }
  cout << endl;

  return 0;
}