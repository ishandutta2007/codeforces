#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef double db;
const int N = 1024;
int n, k;
db f[2][N + 1];
int main() {
  cin >> n >> k;
  int c = 0;
  rep(i, 1, n) {
    c ^= 1; memset(f[c], 0, sizeof f[c]);
    for(int j = 1; j < N; j ++) {
      f[c][j] = (f[c ^ 1][j] * (k * (j + 1) - 1) + f[c ^ 1][j + 1] + j * (j + 3) / 2) / (k * (j + 1));
    }
  }
  printf("%.11f\n", f[c][1] * k);
  return 0;
}