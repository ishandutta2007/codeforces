// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef __int128 lll;

int n, d;
int a[100005];

lll dp[100005][10];
int p[100005][10];
const lll inf = lll(1e18) * lll(1e15);

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> d;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  if (d == 1 || d == 3 || d == 7 || d == 9) {
    // izbaci 5 i parne
    n = partition(a, a+n, [](int d) { d %= 10; return d == 1 || d == 3 || d == 7 || d == 9; }) - a;
  } else if (d == 5) {
    // izbaci parne
    n = partition(a, a+n, [](int d) { return d % 2 == 1; }) - a;
  } else if (d != 0) {
    // izbaci nule i petice
    n = partition(a, a+n, [](int d) { return d % 5 != 0; }) - a;
  }

  for (int i=0; i<=n; i++) {
    for (int j=0; j<10; j++) {
      dp[i][j] = inf;
      p[i][j] = -1;
    }
  }
  dp[0][1] = 1;

  for (int i=0; i<n; i++) {
    for (int j=0; j<10; j++) {
      // don't take
      int j2 = j;
      lll w2 = min(dp[i][j] * a[i], inf);

      if (w2 < dp[i+1][j2]) {
        dp[i+1][j2] = w2;
        p[i+1][j2] = -1;
      }

      // take
      j2 = j * a[i] % 10;
      w2 = dp[i][j];

      if (w2 < dp[i+1][j2]) {
        dp[i+1][j2] = w2;
        p[i+1][j2] = j;
      }
    }
  }

  if (dp[n][d] == inf || dp[n][d] == accumulate(a, a+n, lll(1), multiplies<lll>())) {
    cout << "-1\n";
    return 0;
  }

  vector<int> mark(n);
  for (int i=n, j=d; i>0; i--) {
    if (p[i][j] != -1) {
      mark[i-1] = 1;
      j = p[i][j];
    }
  }

  cout << count(begin(mark), end(mark), 1) << '\n';
  for (int i=0; i<n; i++) {
    if (mark[i]) {
      cout << a[i] << ' ';
    }
  }
  cout << '\n';
}