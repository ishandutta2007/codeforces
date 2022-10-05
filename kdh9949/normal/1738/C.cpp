#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 105;
int dp[N][N][2][2];

int f(int a, int b, int c, int t) {
  if(a == 0 && b == 0) return (c == 0);
  if(~dp[a][b][c][t]) return dp[a][b][c][t];
  int &res = dp[a][b][c][t];
  if(t == 0) {
    if(a && f(a - 1, b, c ^ 1, 1)) return res = 1;
    if(b && f(a, b - 1, c, 1)) return res = 1;
    return res = 0;
  }
  else {
    if(a && !f(a - 1, b, c, 0)) return res = 0;
    if(b && !f(a, b - 1, c, 0)) return res = 0;
    return res = 1;
  }
}

void solve() {
  int n;
  cin >> n;

  int a = 0, b = 0;
  while(n--) {
    int x;
    cin >> x;
    if(x & 1) ++a;
    else ++b;
  }

  cout << (f(a, b, 0, 0) ? "Alice" : "Bob") << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  memset(dp, -1, sizeof(dp));

  int t;
  cin >> t;
  while(t--) { solve(); }

  return 0;
}