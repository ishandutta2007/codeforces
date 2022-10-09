// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[100005];
int l[100005], r[100005];
ll dp[100005][2];

void dfs(int x, int p) {
  dp[x][0] = dp[x][1] = 0;
  for (int y : e[x]) {
    if (y != p) {
      dfs(y, x);
      dp[x][0] += max(dp[y][0] + abs(l[y] - l[x]), dp[y][1] + abs(r[y] - l[x]));
      dp[x][1] += max(dp[y][0] + abs(l[y] - r[x]), dp[y][1] + abs(r[y] - r[x]));
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1; i<=n; i++) {
      e[i] = {};
    }

    for (int i=1; i<=n; i++) cin >> l[i] >> r[i];
    for (int i=1; i<n; i++) {
      int x, y;
      cin >> x >> y;
      e[x] += y;
      e[y] += x;
    }

    dfs(1, 1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
  }
}